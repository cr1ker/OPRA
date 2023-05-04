#include "dll_lib.h"
#include "stat_lib.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
	system("cls");
	srand(time(NULL));
	int sizeOfMatrix = 10;
	int matrix[20][20];
	CreateMatrix(matrix, sizeOfMatrix, sizeOfMatrix);
	PrintMatrix(matrix, sizeOfMatrix, sizeOfMatrix);
	SortMainMatrixDiagonal(matrix, sizeOfMatrix, sizeOfMatrix);
	cout << "Sorted Matrix Diagonal:" << endl;
	PrintMatrix(matrix, sizeOfMatrix, sizeOfMatrix);
}
