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
	int value;
	const int size = 5;
	srand(time(NULL));
	cout << endl;
	int array[size];
	int* mp;
	mp = &array[0];
	cout << "Array:";
	for (int i = 0; i < size; i++)
	{
		*mp = rand() % 100 - 50;
		printf("%4d", *mp);
		mp++;
	}
	mp = &array[0];
	cout << "\nWrite your number:" << endl;
	cin >> value;
	cout << "Elements: \n";
	for (int i = 0; i < size; i++)
	{
		if(value < *mp){
			cout << "Value: " << *mp;
			cout << " Index: " << i;
			cout << endl;
		}
		*mp++;
	}
	cout << endl;
	system("pause");
}
