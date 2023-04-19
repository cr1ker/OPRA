/* Dzhevzhyk Andrii KN 1-2*/
/*LAB 12*/
/*Створити числову функцію для пошуку кількк від'ємних елементів.*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int FindNegativeMatrixValues(int column[]);

int main() {
	system("cls");
	srand(time(NULL));
	int size = 5, i, j;
	int matrix[size][size];
	int columnArray[size];
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			matrix[i][j] = rand() % 100 - 50;
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
	cout << "Array of Negative Matrix Elements:" << endl;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			columnArray[j] = matrix[j][i];
		}
		cout << FindNegativeMatrixValues(columnArray) << "  ";
	}
}

int FindNegativeMatrixValues(int column[]){
	int countOfNegativeElements;
	for(int i = 0; i < sizeof(column); i++){
		if(column[i] < 0){
			countOfNegativeElements++;
		}
	}
	return countOfNegativeElements;
}
