/* Dzhevzhyk Andrii KN 1-2*/
/*LAB 13*/
/*18 variant - 1 task*/
/*Написати процедуру для визначення середнього арифметичного значення та кількості додатних елементів одновимірного масиву*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void PrintArray(int array[], int sizeOfArray);
void CreateArray(int array[], int sizeOfArray);
void GetAverageAndCountOfPositiveElements(int array[], int sizeOfArray);

int main() {
	system("cls");
	srand(time(NULL));
	int sizeOfArray = 10;
	int array[sizeOfArray];
	CreateArray(array, sizeOfArray);
	PrintArray(array, sizeOfArray);
	GetAverageAndCountOfPositiveElements(array, sizeOfArray);
}

void PrintArray(int array[], int sizeOfArray){
	for(int i = 0; i < sizeOfArray; i++){
		printf("%4d", array[i]);
	}
}

void CreateArray(int array[], int sizeOfArray){
	for(int i = 0; i < sizeOfArray; i++){
		array[i] = rand() % 100 - 50;
	}
}

void GetAverageAndCountOfPositiveElements(int array[], int sizeOfArray){
	int averageValue = 0, countOfPositiveElements = 0;
	for(int i = 0; i < sizeOfArray; i++){
		averageValue += array[i];
		if(array[i] > 0){
			countOfPositiveElements++;
		}
	}
	averageValue = averageValue/sizeOfArray;
	cout << "\nAverage Value = " << averageValue << endl;
	cout << "Count Of Positive Elements = " << countOfPositiveElements << endl;
}

