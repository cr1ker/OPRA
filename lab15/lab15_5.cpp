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
	printf("������ ��'� �������� �����': ");
	gets(nameOfInputFile);
	inputFile = fopen(nameOfInputFile, "r+");
	if(inputFile == NULL)
	{
		printf("������� ��� ������� �����\n");
		return 0;
	}
	printf("������ ��'� ����� ��� ����������:' : ");
	gets(nameOfOutputFile);
	outputFile = freopen(nameOfOutputFile, "w+", stdout);
	if(outputFile == NULL)
	{
		printf("������� ������� ��� ������� ����� \n");
		return 0;
	}
	int p;
	while (!feof(inputFile)) 
	{
	fgets(str, 79, inputFile);
	if (ferror(inputFile)){
		printf("������� ������� ����������!");
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


