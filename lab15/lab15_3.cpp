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
	int rows = 0, columns = 0;
	float matrixElement;
	FILE *inputFile, *outputFile; 
	char nameOfInputFile[40], nameOfOutputFile[40];
	printf("Введіть ім'я вхідного файлу: ");
	gets(nameOfInputFile);
	inputFile = fopen(nameOfInputFile, "rb");
	if(inputFile == NULL)
	{
		printf("Виникла помилка при відкритті файлу \n");
		return 0;
	}
	fread(&rows, sizeof(int), 1, inputFile); 
	fread(&columns, sizeof(int), 1, inputFile); 
	float matrix[rows][columns];
	int k;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			fread(&matrixElement, sizeof(float), 1, inputFile); 
			matrix[i][j] = matrixElement;
		}
	}
	int valueForSaveElement = 0;
	for(int i = 1; i < columns; i++){
		valueForSaveElement = matrix[i][i];
    	int previousElementIndex = i - 1;
    	while (previousElementIndex >= 0 && matrix[previousElementIndex][previousElementIndex] < valueForSaveElement) {
        	matrix[previousElementIndex + 1][previousElementIndex + 1] = matrix[previousElementIndex][previousElementIndex];
        	previousElementIndex--;
    	}
    	matrix[previousElementIndex + 1][previousElementIndex + 1] = valueForSaveElement;
	}
	printf("Матриця matrix[%d,%d]:\n", rows, columns);
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++){
			printf("%7.2f ", matrix[i][j]);
			printf("\n");
		}
	}
	printf("\n Відсортована підголовна матриця(%d): \n", columns);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
	printf("\n");
	printf("\nВведіть ім'я файлу для результату: ");
	gets(nameOfOutputFile);
	outputFile = freopen(nameOfOutputFile, "w+", stdout);
	if(outputFile == NULL)
	{
		printf("Виникла помилка при відкритті файлу \n");
		return 0;
	}
	printf("Матриця matrix[%d,%d]:\n", rows, columns);
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++){
			printf("%7.2f ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n Відсортована підголовна матриця(%d): \n", columns);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
	printf("\n");
	fclose(outputFile);	
	fclose(inputFile);
	return 0;
}

