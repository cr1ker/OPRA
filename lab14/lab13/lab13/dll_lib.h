#include <iostream>
using namespace std;

#ifndef _DLL_LIB_H_
#define _DLL_LIB_H_
	void __declspec(dllexport) GetAverageAndCountOfPositiveElements(int array[], int sizeOfArray);
	void __declspec(dllexport) ModifyArray(int array[], int sizeOfArray);
	void __declspec(dllexport) SortMainMatrixDiagonal(int matrix[20][20], int line, int column);
	void __declspec(dllexport) CreateArrayBySumOfNegativeValueIndexes(int matrix[20][20], int line, int column);
#endif
