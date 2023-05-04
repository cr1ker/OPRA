#include "stat_lib.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

void CreateMatrix(int matrix[25][25], int line, int column){
	for(int i = 0; i < line; i++){
		for(int j = 0; j < column; j++){
			matrix[i][j] = rand() % 100 - 50;
		}
	}
}

void PrintMatrix(int matrix[25][25], int line, int column){
	for(int i = 0; i < line; i++){
		for(int j = 0; j < column; j++){
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
}
