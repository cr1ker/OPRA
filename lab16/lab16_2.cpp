/*
Dzhevzhyk Andrii KN 1-2
Lab 16
Task 16.2
*/
#include <conio.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows = 0, columns = 0;
    float x;
    std::fstream inputFile; // inputFile - вхідний файл
    FILE* outputFile;       // outputFile - вихідний файл
    char inputFileName[40], outputFileName[40]; // змінна для повного імені файлу

    printf("Введіть ім'я вхідного файлу: ");
    gets(inputFileName);

    inputFile.open(inputFileName); // відкриваємо файл для зчитування в текстовому режимі
    if (!inputFile)
    {
        printf("Виникла помилка при відкритті файлу \n");
        return 0;
    }

    inputFile >> rows; // зчитуємо кількість рядків матриці
    inputFile >> columns; // зчитуємо кількість стовпчиків матриці
    float matrix[rows][columns];
    float sum = 0.0;
    int k;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            inputFile >> x; // зчитуємо елементи матриці
            matrix[i][j] = x;
        }
    }

    float arrayOfNegativeIndexes[columns];
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

    printf("\nВведіть ім'я файлу для результату: ");
    gets(outputFileName);

    outputFile = freopen(outputFileName, "w+", stdout); // відкриваємо та перенаправляємо потік виведення у заданий файл

    // якщо вдалось відкрити та перенаправити потік виведення, то виведення буде записуватись у заданий файл і не виводитись на екран
    if (outputFile == NULL)
    {
        printf("Виникла помилка при відкритті файлу \n");
        return 0;
    }

    // виведення матриці та результатів обчислення
    printf("Матриця matrix[%d,%d]:\n", rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%7.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n Масив arrayOfNegativeIndexes(%d): \n", columns);
    for(int i = 0; i < columns; i++){
		cout << arrayOfNegativeIndexes[i] << " ";
	}
    printf("\n");

    inputFile.close();
    fclose(outputFile);
    return 0;
}


