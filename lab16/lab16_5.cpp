/*
Dzhevzhyk Andrii KN 1-2
Lab 16
Task 16.5
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

    int rows = 0, columns = 0;
    inputFile.read((char*)&rows, sizeof(rows)); // �������� ������ ��������� ������� ����� �������
    inputFile.read((char*)&columns, sizeof(columns)); // �������� ������ ��������� ������� ���������
    float matrix[rows][columns];
    float r[rows];
    float v[columns];
    float sum = 0.0;
    float x;

    for (int i = 0; i < rows; i++)
    {
        inputFile.read((char*)&v, sizeof(v));
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = v[j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        sum = 0;
        for (int j = 0; j < columns; j++)
        {
            sum = sum + matrix[i][j];
        }
        r[i] = sum;
    }

    printf("������� a[%d,%d]:\n", rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%7.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n ����� r(%d): \n", columns);
    for (int i = 0; i < rows; i++)
    {
        printf("%7.2f ", r[i]);
    }
    printf("\n");

    fclose(outputFile);
    inputFile.close();
    return 0;
}

