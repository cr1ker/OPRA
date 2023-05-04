#include "dll_lib.h"
#include "stat_lib.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
	system("cls");
	srand(time(NULL));
	int sizeOfMatrix = 5;
	int matrix[20][20];
	CreateMatrix(matrix, sizeOfMatrix, sizeOfMatrix);
	PrintMatrix(matrix, sizeOfMatrix, sizeOfMatrix);
	cout << "Array By Sum Of Negative Value Indexes" << endl;
	CreateArrayBySumOfNegativeValueIndexes(matrix, sizeOfMatrix, sizeOfMatrix);
}
