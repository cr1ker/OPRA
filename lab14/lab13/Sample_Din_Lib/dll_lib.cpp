#include "dll_lib.h"
#include <windows.h>
#include <iostream>

using namespace std;

void __declspec(dllexport) GetAverageAndCountOfPositiveElements(int array[], int sizeOfArray){
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

void __declspec(dllexport) ModifyArray(int array[], int sizeOfArray){
	int copyArray[sizeOfArray];
	int arrayIndex = 0;
	for(int i = 0; i < sizeOfArray; i++){
		copyArray[i] = array[i];
	}
	for(int i = 0; i < sizeOfArray; i++){
		if(copyArray[i] == 0){
			array[arrayIndex] = 0;
			arrayIndex++;
		}
	}
	for(int i = 0; i < sizeOfArray; i++){
		if(copyArray[i] > 0){
			array[arrayIndex] = copyArray[i];
			arrayIndex++;
		}
	}
	for(int i = 0; i < sizeOfArray; i++){
		if(copyArray[i] < 0){
			array[arrayIndex] = copyArray[i];
			arrayIndex++;
		}
	}
}

void __declspec(dllexport) SortMainMatrixDiagonal(int matrix[20][20], int line, int column){ //sort matrix diagonal by insertion algorithm 
	int valueForSaveElement = 0;
	for(int i = 1; i < line; i++){
		valueForSaveElement = matrix[i][i];
    	int previousElementIndex = i - 1;
    	while (previousElementIndex >= 0 && matrix[previousElementIndex][previousElementIndex] < valueForSaveElement) {
        	matrix[previousElementIndex + 1][previousElementIndex + 1] = matrix[previousElementIndex][previousElementIndex];
        	previousElementIndex--;
    	}
    	matrix[previousElementIndex + 1][previousElementIndex + 1] = valueForSaveElement;
	}
}

void __declspec(dllexport) CreateArrayBySumOfNegativeValueIndexes(int matrix[20][20], int line, int column){
	int arrayOfNegativeIndexes[line];
	int sumOfIndexes = 0;
	for(int i = 0; i < line; i++){
		for(int j = 0; j < column; j++){
			if(matrix[j][i] < 0){
				sumOfIndexes += i + j;
			}
		}
		arrayOfNegativeIndexes[i] = sumOfIndexes;
		sumOfIndexes = 0;
	}
	for(int i = 0; i < line; i++){
		cout << arrayOfNegativeIndexes[i] << " ";
	}
}
