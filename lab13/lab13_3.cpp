/* Dzhevzhyk Andrii KN 1-2*/
/*LAB 13*/
/*18 variant - 3 task*/
/*Написати процедуру для сортування за спаданням елементів квадратної матриці, що розташовані по головній діагоналі*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void CreateMatrix(int matrix[25][25], int sizeOfMatrix);
void PrintMatrix(int matrix[25][25], int sizeOfMatrix);
void SortMainMatrixDiagonal(int matrix[25][25], int sizeOfMatrix);

int main() {
	system("cls");
	srand(time(NULL));
	int sizeOfMatrix = 10;
	int matrix[25][25];
	CreateMatrix(matrix, sizeOfMatrix);
	PrintMatrix(matrix, sizeOfMatrix);
	SortMainMatrixDiagonal(matrix, sizeOfMatrix);
	cout << "Sorted Matrix Diagonal:" << endl;
	PrintMatrix(matrix, sizeOfMatrix);
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

void SortMainMatrixDiagonal(int matrix[25][25], int sizeOfMatrix){ //sort matrix diagonal by insertion algorithm 
	int valueForSaveElement = 0;
	for(int i = 1; i < sizeOfMatrix; i++){
		valueForSaveElement = matrix[i][i];
    	int previousElementIndex = i - 1;
    	while (previousElementIndex >= 0 && matrix[previousElementIndex][previousElementIndex] < valueForSaveElement) {
        	matrix[previousElementIndex + 1][previousElementIndex + 1] = matrix[previousElementIndex][previousElementIndex];
        	previousElementIndex--;
    	}
    	matrix[previousElementIndex + 1][previousElementIndex + 1] = valueForSaveElement;
	}
}

