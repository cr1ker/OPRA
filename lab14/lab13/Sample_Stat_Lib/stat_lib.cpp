#include "stat_lib.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>

void CreateArray(int array[], int sizeOfArray){
	for(int i = 0; i < sizeOfArray; i++){
		array[i] = rand() % 100 - 50;
	}
}

void PrintArray(int array[], int sizeOfArray){
	for(int i = 0; i < sizeOfArray; i++){
		printf("%4d", array[i]);
	}
}

void CreateMatrix(int matrix[20][20], int line, int column){
	for(int i = 0; i < line; i++){
		for(int j = 0; j < column; j++){
			matrix[i][j] = rand() % 100 - 50;
		}
		cout << endl;
	}
}

void PrintMatrix(int matrix[20][20], int line, int column){
	for(int i = 0; i < line; i++){
		for(int j = 0; j < column; j++){
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
}
