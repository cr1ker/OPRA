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
    fstream inputFile; // вхідний файл
    FILE* outputFile; // вихідний файл
    char inputFileName[40], outputFileName[40]; // змінна для повного імені файлу
    char str[80]; // змінна для зчитування символьного рядка з файлу

    printf("Введіть ім'я вхідного файлу: ");
    gets(inputFileName);

    inputFile.open(inputFileName); // відкриваємо файл для зчитування в текстовому режимі
    if (!inputFile)
    {
        printf("Виникла помилка при відкритті файлу \n");
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

    string inputString; // змінна для символьного рядка
    string filterCharacters(" */+-"); // змінна для рядка шаблона символьного рядка
    int i, p;
    while (!inputFile.eof()) // зчитування буде відбуватися до тих пір, поки не дійдемо до кінця файлу
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
