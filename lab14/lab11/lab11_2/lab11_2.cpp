#include "stat_lib.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main(){
	system("cls");
	srand(time(NULL));
	int i, j;
	int line = 5, column = 6;
	int matrix[25][25];
	cout << "Not Sorted Matrix:" << endl;
	CreateMatrix(matrix, line, column);
	PrintMatrix(matrix, line, column);
	cout << endl;
	int currentElement, variableForSaveCurrentElement;
	for(i = 0; i < line; i++){
		if(i % 2 == 0){
			currentElement = 0;
			while(currentElement < column - 1){
				if(matrix[i][currentElement] < matrix[i][currentElement + 1]){
					variableForSaveCurrentElement = matrix[i][currentElement];
					matrix[i][currentElement] = matrix[i][currentElement + 1];
					matrix[i][currentElement + 1] = variableForSaveCurrentElement;
					currentElement = 0;
				}else{
					currentElement++;
				}
			}
		}
	}
	cout << "Sorted Matrix:" << endl;
	PrintMatrix(matrix, line, column);
}
