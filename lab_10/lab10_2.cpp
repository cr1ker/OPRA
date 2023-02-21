/* Dzhevzhyk Andrii KN 1-2*/
/*LAB 10*/
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;
int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int element, arrayCount, sum;
	const int row = 5, column = 6;
	srand(time(NULL));
	cout << endl;
	int matrix[row][column];
	int* mp;
	int* ap;
	mp = &matrix[0][0];
	printf("  Matrix( %d, %d): \n", row, column);
	for (int i = 0; i < row; i++)
	{
		arrayCount += i % 2 == 0 ? 1 : 0; //calculate how many not even elements will be have array
		for (int j = 0; j < column; j++)
		{
			*mp = rand() % 100 - 50;
			printf("%4d", *mp);
			mp++;
		}
		cout << endl;
	}
	int array[arrayCount];
	ap = &array[0];
	mp = &matrix[0][0];
	for (int i = 0; i < row; i++)
	{
		sum = 0;
		for (int j = 0; j < column; j++)
		{
			element = *mp;
			if (element < 0 && i % 2 == 0){
				sum += element;
			}
			mp++;
		}
		if(sum != 0){
			*ap = sum;
			ap++;
		}
	}
	ap = &array[0];
	printf("\n Array r(%d): \n", arrayCount);
	for (int i = 0; i < arrayCount; i++)
	{
			cout << " " << *ap;
			ap++;
	}
	cout << endl;
	system("pause");
}
