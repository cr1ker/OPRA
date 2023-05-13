/*
Dzhevzhyk Andrii KN 1-2
Lab 16
Task 16.3
*/
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main()
{
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    float x;
    fstream inputFile; // ������� ����
    FILE* outputFile; // �������� ����
    char inputFileName[40], outputFileName[40]; // ����� ��� ������� ���� �����
    char str[80]; // ����� ��� ���������� ����������� ����� � �����

    printf("������ ��'� �������� �����: ");
    gets(inputFileName);

    inputFile.open(inputFileName); // ��������� ���� ��� ���������� � ���������� �����
    if (!inputFile)
    {
        printf("������� ������� ��� ������� ����� \n");
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

    string inputString; // ����� ��� ����������� �����
    string filterCharacters(" */+-"); // ����� ��� ����� ������� ����������� �����
    int i, p;
    while (!inputFile.eof()) // ���������� ���� ���������� �� ��� ��, ���� �� ������ �� ���� �����
    {
        inputFile.getline(str, sizeof(str));
        inputString = str;

        string modifiedStr;
        int countOfSpaces = 0;

        for (int i = 0; i < 80; i++)
        {
            if (str[i] != ' ')
            {
                modifiedStr += str[i];
            }
            else
            {
                countOfSpaces++;
            }
        }

        for (int i = 0; i < countOfSpaces; i++)
        {
            modifiedStr += ' ';
        }

        cout << modifiedStr << endl;
    }

    fclose(outputFile);
    inputFile.close();
    return 0;
}
