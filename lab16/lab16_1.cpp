/*
Dzhevzhyk Andrii KN 1-2
Lab 16
Task 16.1
*/
#include <conio.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void gotoxy(int xp, int yp)
{
    COORD new_xy;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    new_xy.X = xp;
    new_xy.Y = yp;
    SetConsoleCursorPosition(hStdOut, new_xy);
}

void createAndWriteToTextFileMatrix();
void createAndWriteToTextFileStrings();
void createAndWriteToBinaryFileMatrix();

int main()
{
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int numberOfChoice;
    do
    {
        system("cls");
        gotoxy(10, 5);
        cout << " ������� ���� ";
        gotoxy(10, 7);
        cout << " 1. ��������� �� ����� � ������ ��������� ���� �������";
        gotoxy(10, 8);
        cout << " 2. ��������� �� ����� � ������ ��������� ���� ���������� ����� ";
        gotoxy(10, 9);
        cout << " 3. ��������� �� ����� � ������ ������� ���� �������";
        gotoxy(10, 10);
        cout << " 4. ��������� �� ����� � ������ ������� ���� �������";
        gotoxy(10, 12);
        cout << " 0. �����";
        gotoxy(10, 13);
        cout << " ������ ����� ������: ";
        cin >> numberOfChoice;
        switch (numberOfChoice)
        {
            case 1:
            {
                createAndWriteToTextFileMatrix();
                break;
            }
            case 2:
            {
                createAndWriteToTextFileStrings();
                break;
            }
            case 3:
            {
                createAndWriteToBinaryFileMatrix();
                break;
            }
            case 4:
            {
                createAndWriteToBinaryFileMatrix();
                break;
            }
        }
    }
    while (numberOfChoice != 0);
    return 0;
}

void createAndWriteToTextFileMatrix()
{
    system("cls");
    int rows = 0, columns = 0;
    float x;
    ofstream file;
    char fileName[40];
    cin.ignore(1, '\n');
    printf("������ ��'� ������� ���������� �����: ");
    gets(fileName);
    file.open(fileName);
    if (!file)
    {
        printf("������� ������� ��� �������� ����� \n");
        while (!kbhit())
            ;
        return;
    }
    printf("������ ������� ����� �������: ");
    cin >> rows;
    printf("������ ������� ��������� �������: ");
    cin >> columns;
    file << rows << "\n";
    file << columns << "\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            x = (rand() % 100 - 50.0) / 5;
            printf("%7.2f ", x);
            file << x << "\t";
        }
        file << "\n";
        cout << endl;
    }
    file.close();
    printf("\n�������� ���� %s \n", fileName);
    while (!kbhit());
}

void createAndWriteToTextFileStrings()
{
    system("cls");
    int i, k = 0, m;
    ofstream file;
    char fileName[40];
    char str[77];
    cin.ignore(1, '\n');
    printf("������ ��'� ������� ���������� �����: ");
    gets(fileName);
    file.open(fileName);
    if (!file)
    {
        printf("������� ������� ��� �������� ����� \n");
        while (!kbhit())
            ;
        return;
    }
    printf("��� ���������� ������ ������� �����\n");
    do
    {
        printf("%d: ", i);
        gets(str);
        if (!*str)
            break;
        m = strlen(str);
        file << str << '\0' << '\n';
    } while (*str);
    file.close();
    printf("\n�������� ���� %s \n", fileName);
    while (!kbhit())
        ;
}

void createAndWriteToBinaryFileMatrix()
{
    system("cls");
    int rows = 0, columns = 0;
    float x;
    ofstream file;
    char fileName[40];
    cin.ignore(1, '\n');
    printf("������ ��'� �������� �����: ");
    gets(fileName);
    file.open(fileName, ios::out | ios::binary);
    if (!file)
    {
        printf("������� ������� ��� �������� ����� \n");
        while (!kbhit());
        return;
    }
    printf("������ ������� ����� �������: ");
    cin >> rows;
    printf("������ ������� ��������� �������: ");
    cin >> columns;
    file.write((char *)&rows, sizeof(rows));
    file.write((char *)&columns, sizeof(columns));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            x = (rand() % 100 - 50.0) / 5;
            printf("%7.2f ", x);
            file.write((char *)&x, sizeof(x));
        }
        cout << endl;
    }
    file.close();
    printf("�������� ���� %s \n", fileName);
    while (!kbhit())
        ;
}
