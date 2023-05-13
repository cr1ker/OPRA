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

    ifstream inputFile; // ������� ����
    FILE* outputFile; // �������� ����
    char inputFileName[40], outputFileName[40]; // ����� ��� ������� ���� �����

    printf("������ ��'� �������� �����: ");
    gets(inputFileName);

    inputFile.open(inputFileName, ios::in | ios::binary); // ��������� ���� � �������� ����� ��� ������ �����
    if (!inputFile)
    {
        printf("������� ������� ��� �������� ����� \n");
        return 0;
    }

    printf("������ ��'� ����� ��� ����������: ");
    gets(outputFileName);

    outputFile = freopen(outputFileName, "w+", stdout); // ��������� �� ��������������� ���� ��������� � ������� ����
    if (outputFile == NULL)
    {
        printf("������� ������� ��� ������� ����� \n");
        return 0;
    }

    int i, j, rows = 0, columns = 0;
    inputFile.read((char*)&rows, sizeof(columns)); // �������� ������ ��������� ������� ����� �������
    inputFile.read((char*)&columns, sizeof(columns)); // �������� ������ ��������� ������� ���������
    float matrix[rows][columns];
    float x;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            inputFile.read((char*)&x, sizeof(x)); // �������� ������ ��������� ������� ����� �������
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

    printf("������� matrix[%d,%d]:\n", rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%7.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n ³���������� ��������� �������(%d): \n", columns);
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



