/*
Dzhevzhyk Andrii KN 1-2
Lab 15
Task 15.1
*/
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

void gotoxy(int xp, int yp);
int CreateFileAndNoteMatrix();
int CreateAndNoteSymbolRow();
int CreateAndNoteMatrixByElements();
int CreateAndNoteMatrixByRows();

int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int numberOfOperation;
	do
	{
	system("cls");
	gotoxy(10,5);
	cout << " Main Menu ";
	gotoxy(10,7); cout << " 1. Creating and note on first text file matrix";
	gotoxy(10,8); cout << " 2. Creating and note on second text file symbols rows ";
	gotoxy(10,9); cout << " 3. Creating and note on first binary file matrix";
	gotoxy(10,10); cout << " 4. Creating and note on second binary file matrix";
	gotoxy(10,12); cout << " 0. Exit";
	gotoxy(10,13); cout << " Write number of operation : ";
	cin >> numberOfOperation;
	switch (numberOfOperation)
	{
		case 1:
		{
			CreateFileAndNoteMatrix();
			break;
		}
		case 2:
		{
			CreateAndNoteSymbolRow();
			break;
		}
		case 3:
		{
			CreateAndNoteMatrixByElements();
			break;
		}
		case 4:
		{
			CreateAndNoteMatrixByRows();
			break;
		}
	}
	}while (numberOfOperation != 0);
	return 0;
}

void gotoxy(int xp, int yp)
{
	COORD new_xy;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	new_xy.X = xp; new_xy.Y = yp;
	SetConsoleCursorPosition(hStdOut,new_xy);
}

int CreateFileAndNoteMatrix()
{
	system("cls");
	int rows = 0, columns = 0;	
	float x;
	FILE *file; //f - ??????? ?????
	char nameOfFile[40];// ?????? ??? ??????? ????? ?????
	cin.ignore(1,'\n');
	printf("Write name of first text file: ");
	gets(nameOfFile);
	file = fopen(nameOfFile, " w+"); //??????????? ???? ??? ?????? ? ??????????
	if(file == NULL)
	{
		printf("Error while creating file\n");
		while (!kbhit());
		return 0;
	}
	printf("Write count of matrix rows: ");
	cin >> rows;
	printf("Write count of matrix columns: ");
	cin >> columns;
	fprintf(file, "rows=%d ", rows); // ????????? ????????? ?????? ???????
	fprintf(file, "columns=%d \n", columns); // ????????? ????????? ?????????? ???????
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < (columns-1); j++)
		{
			x=(rand()%100-50.0)/5;
			printf("%7.2f ", x);
			fprintf(file, "%7.2f ", x);
		}
		x=(rand()%100-50.0)/5;
		printf("%7.2f \n", x);
		fprintf(file, "%7.2f \n", x);
	}
	fclose(file);
	printf("Created file: %s \n", nameOfFile);	
	while (!kbhit());
	return 0;
}

int CreateAndNoteSymbolRow()
{
	system("cls");
	int strLength, k=0;
	FILE *file; // оголошуємо файлову змінну
	char nameOfFile[40]; // змінна для повного імені файлу
	char str[77];
	cin.ignore(1,'\n');
	printf("Write name of second text file: ");
	gets(nameOfFile);
	file = fopen(nameOfFile, "w+");//відкриваємо файл для записування в текстовому
	if(file == NULL)
	{
		printf("Error while creating file \n");
		while (!kbhit());
		return 0;
	}
	printf("For stop, just write a space \n");
	do
	{
		printf("%d: ", k);
		gets(str);
		if (!*str) break;
		strLength = strlen(str);	
		k++;
		for(int i = 0; i < strLength; i++){
			putc(str[i],file);
			putc('\0',file);
			putc('\n',file);
		}
	}while(*str);
	printf("\n");
	fclose(file); // закриваємо файл
	printf("Created file: %s \n", nameOfFile);
	while (!kbhit());
	return 0;
}

int CreateAndNoteMatrixByElements()
{
	system("cls");
	int rows = 0, columns = 0;
	float x;
	FILE *file; //f - ??????? ?????
	char nameOfFile[40];// ?????? ??? ??????? ????? ?????
	cin.ignore(1,'\n');
	printf("Write name of binary file: ");
	gets(nameOfFile);
	file = fopen(nameOfFile, " w+b"); //??????????? ???? ??? ?????? ? ?????????
	if(file == NULL)
	{
		printf("Error while creating file \n");
		while (!kbhit());
		return 0;
	}
	printf("Write count of matrix rows: ");
	cin	>> rows;
	printf("Write count of matrix columns: ");
	cin >> columns;
	fwrite(&rows, sizeof(int), 1, file); // ????????? ?????? ????????? ?????????
	fwrite(&columns, sizeof(int), 1, file); // ????????? ?????? ????????? ?????????
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			x = (rand()%100-50.0)/5;
			printf("%7.2f ", x);
			fwrite(&x, sizeof(float), 1, file);
		}
		cout<<endl;
	}
	fclose(file);
	printf("Created file: %s \n", nameOfFile);
	while (!kbhit());
	return 0;
}

int CreateAndNoteMatrixByRows()
{
	system("cls");
	int rows = 0, columns = 0;
	float x;
	FILE *file; //f - ??????? ?????
	char nameOfFile[40];// ?????? ??? ??????? ????? ?????
	cin.ignore(1,'\n');
	printf("Write name of binary file: ");
	gets(nameOfFile);
	file = fopen(nameOfFile, " w+b"); //??????????? ???? ??? ?????? ? ?????????
	if(file == NULL)
	{
		printf("Error while creating file \n");
		while (!kbhit());
		return 0;
	}
	printf("Write count of matrix rows: ");
	cin	>> rows;
	printf("Write count of matrix columns: ");
	cin >> columns;
	float v[columns];
	fwrite(&rows, sizeof(int), 1, file); // ????????? ?????? ????????? ?????????
	fwrite(&columns, sizeof(int), 1, file); // ????????? ?????? ????????? ?????????
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			x = (rand()%100-50.0)/5;
			v[j] = x;
			printf("%7.2f ", x);
		}
		fwrite(&v, sizeof(v), 1, file);
		cout<<endl;
	}
	fclose(file);
	printf("Created file: %s \n", nameOfFile);
	while (!kbhit());
	return 0;
}

