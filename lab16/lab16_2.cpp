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
    std::fstream inputFile; // inputFile - ������� ����
    FILE* outputFile;       // outputFile - �������� ����
    char inputFileName[40], outputFileName[40]; // ����� ��� ������� ���� �����

    printf("������ ��'� �������� �����: ");
    gets(inputFileName);

    inputFile.open(inputFileName); // ��������� ���� ��� ���������� � ���������� �����
    if (!inputFile)
    {
        printf("������� ������� ��� ������� ����� \n");
        return 0;
    }

    inputFile >> rows; // ������� ������� ����� �������
    inputFile >> columns; // ������� ������� ��������� �������
    float matrix[rows][columns];
    float sum = 0.0;
    int k;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            inputFile >> x; // ������� �������� �������
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

    printf("\n������ ��'� ����� ��� ����������: ");
    gets(outputFileName);

    outputFile = freopen(outputFileName, "w+", stdout); // ��������� �� ��������������� ���� ��������� � ������� ����

    // ���� ������� ������� �� ������������� ���� ���������, �� ��������� ���� ������������ � ������� ���� � �� ���������� �� �����
    if (outputFile == NULL)
    {
        printf("������� ������� ��� ������� ����� \n");
        return 0;
    }

    // ��������� ������� �� ���������� ����������
    printf("������� matrix[%d,%d]:\n", rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%7.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n ����� arrayOfNegativeIndexes(%d): \n", columns);
    for(int i = 0; i < columns; i++){
		cout << arrayOfNegativeIndexes[i] << " ";
	}
    printf("\n");

    inputFile.close();
    fclose(outputFile);
    return 0;
}


