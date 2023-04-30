/* Dzhevzhyk Andrii KN 1-2*/
/*LAB 13*/
/*18 variant  - 4 task*/
/*Написати процедуру для створення одновимірного масиву із сум індексів від'ємних елементів кожного стовпчика вхідної матриці*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void CreateMatrix(int matrix[25][25], int sizeOfMatrix);
void PrintMatrix(int matrix[25][25], int sizeOfMatrix);
void CreateArrayBySumOfNegativeValueIndexes(int matrix[25][25], int sizeOfMatrix);

int main() {
	system("cls");
	srand(time(NULL));
	int sizeOfMatrix = 5;
	int matrix[25][25];
	CreateMatrix(matrix, sizeOfMatrix);
	PrintMatrix(matrix, sizeOfMatrix);
	cout << "Array By Sum Of Negative Value Indexes" << endl;
	CreateArrayBySumOfNegativeValueIndexes(matrix, sizeOfMatrix);
}

void PrintMatrix(int matrix[25][25], int sizeOfMatrix){
	for(int i = 0; i < sizeOfMatrix; i++){
		for(int j = 0; j < sizeOfMatrix; j++){
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
}

void CreateMatrix(int matrix[25][25], int sizeOfMatrix){
	for(int i = 0; i < sizeOfMatrix; i++){
		for(int j = 0; j < sizeOfMatrix; j++){
			matrix[i][j] = rand() % 100 - 50;
		}
	}
}

void CreateArrayBySumOfNegativeValueIndexes(int matrix[25][25], int sizeOfMatrix){
	int arrayOfNegativeIndexes[sizeOfMatrix];
	int sumOfIndexes = 0;
	for(int i = 0; i < sizeOfMatrix; i++){
		for(int j = 0; j < sizeOfMatrix; j++){
			if(matrix[j][i] < 0){
				sumOfIndexes += i + j;
			}
		}
		arrayOfNegativeIndexes[i] = sumOfIndexes;
		sumOfIndexes = 0;
	}
	for(int i = 0; i < sizeOfMatrix; i++){
		cout << arrayOfNegativeIndexes[i] << " ";
	}
}

