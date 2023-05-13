/*
Dzhevzhyk Andrii KN 1-2
Lab 16
Task 16.4
*/
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main()
{
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream inputFile; // вхідний файл
    FILE* outputFile; // вихідний файл
    char inputFileName[40], outputFileName[40]; // змінна для повного імені файлу

    printf("Введіть ім'я вхідного файлу: ");
    gets(inputFileName);

    inputFile.open(inputFileName, ios::in | ios::binary); // відкриваємо файл у бінарному режимі для запису даних
    if (!inputFile)
    {
        printf("Виникла помилка при створенні файлу \n");
        return 0;
    }

    printf("Введіть ім'я файлу для результату: ");
    gets(outputFileName);

    outputFile = freopen(outputFileName, "w+", stdout); // відкриваємо та перенаправляємо потік виведення у заданий файл
    if (outputFile == NULL)
    {
        printf("Виникла помилка при відкритті файлу \n");
        return 0;
    }

    int i, j, rows = 0, columns = 0;
    inputFile.read((char*)&rows, sizeof(columns)); // записуємо першим елементом кількість рядків матриці
    inputFile.read((char*)&columns, sizeof(columns)); // записуємо другим елементом кількість стовпчиків
    float matrix[rows][columns];
    float x;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            inputFile.read((char*)&x, sizeof(x)); // записуємо першим елементом кількість рядків матриці
            matrix[i][j] = x;
        }
    }

    int valueForSaveElement = 0;
	for(int i = 1; i < rows; i++){
		valueForSaveElement = matrix[i][i];
    	int previousElementIndex = i - 1;
    	while (previousElementIndex >= 0 && matrix[previousElementIndex][previousElementIndex] < valueForSaveElement) {
        	matrix[previousElementIndex + 1][previousElementIndex + 1] = matrix[previousElementIndex][previousElementIndex];
        	previousElementIndex--;
    	}
    	matrix[previousElementIndex + 1][previousElementIndex + 1] = valueForSaveElement;
	}

    printf("Матриця matrix[%d,%d]:\n", rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
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

    fclose(outputFile);
    inputFile.close();
    return 0;
}



