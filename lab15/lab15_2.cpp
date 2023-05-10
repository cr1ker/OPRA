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
	inputFile = fopen(nameOfInputFile, "r+");
	if(inputFile == NULL)
	{
		printf("Виникла помилка при відкритті файлу \n");
		return 0;
	}
	fscanf(inputFile, "rows=%d ", &rows); 
	fscanf(inputFile, "columns=%d ", &columns); 
	float matrix[rows][columns];
	float averageValues[columns];
	int k;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			fscanf(inputFile, "%f ", &matrixElement); 
			matrix[i][j] = matrixElement;
		}
	}
	int arrayOfNegativeIndexes[columns];
	int sumOfIndexes = 0;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			if(matrix[i][j] < 0){
				sumOfIndexes += i + j;
			}
		}
		arrayOfNegativeIndexes[i] = sumOfIndexes;
		sumOfIndexes = 0;
	}
	for(int i = 0; i < columns; i++){
		cout << arrayOfNegativeIndexes[i] << " ";
	}
	printf("Матриця matrix[%d,%d]:\n", rows, columns);
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++){
			printf("%7.2f ", matrix[i][j]);
			printf("\n");
		}
	}
	printf("\n Масив Негативних Елементів(%d): \n", columns);
	for(int i = 0; i < columns; i++){
		cout << arrayOfNegativeIndexes[i] << "  ";
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
	printf("\n Масив Негативних Елементів(%d): \n", columns);
	for(int i = 0; i < columns; i++){
		cout << arrayOfNegativeIndexes[i] << " ";
	}
	printf("\n");
	fclose(outputFile);	
	fclose(inputFile);
	return 0;
}

