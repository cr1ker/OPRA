/*
Dzhevzhyk Andrii KN 1-2
Lab 15
Task 15.2
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE *inputFile, *outputFile; 
	char nameOfInputFile[40], nameOfOutputFile[40];
	char str[80]; 
	printf("Введіть ім'я вхідного файлу': ");
	gets(nameOfInputFile);
	inputFile = fopen(nameOfInputFile, "r+");
	if(inputFile == NULL)
	{
		printf("Помилка при відкритті файлу\n");
		return 0;
	}
	printf("Введіть ім'я файлу для результату:' : ");
	gets(nameOfOutputFile);
	outputFile = freopen(nameOfOutputFile, "w+", stdout);
	if(outputFile == NULL)
	{
		printf("Виникла помилка при відкритті файлу \n");
		return 0;
	}
	int p;
	while (!feof(inputFile)) 
	{
	fgets(str, 79, inputFile);
	if (ferror(inputFile)){
		printf("Виникла помилка зчитування!");
	}
	string modifiedStr;
	short countOfSpaces = 0, wordLength = 0;
	for(int i = 0; i < 80; i++){
		if(str[i] != ' '){
			modifiedStr += str[i];
		}else{
			countOfSpaces++;
		}
	}
	for(int i = 0; i < countOfSpaces;i++){
		modifiedStr += ' ';
	}
	cout << modifiedStr;
	}
	fclose(outputFile);
	fclose(inputFile);
	return 0;
}


