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
	int size = 5;
	int matrix[25][25];
	int minElement = 0;
	int lineIndex = 0, columnIndex = 0;
	int containerForValue;
	cout << "Not Sorted Matrix:" << endl;
	CreateMatrix(matrix, size, size);
	PrintMatrix(matrix, size, size);
    for (i = 0; i < size; i++) {
    	for (j = 0; j <= i+1; j++) {
    		if(i-j >= 0){
    			cout << matrix[i-j][j] << " ";
			}
			if(matrix[i-j][j] < matrix[lineIndex][columnIndex] && matrix[i-j][j] < 0){
				containerForValue = matrix[lineIndex][columnIndex];
				matrix[lineIndex][columnIndex] = matrix[i-j][j];
				matrix[i-j][j] = containerForValue;
				if(columnIndex < size){
					columnIndex++;
				}else{
					lineIndex++;
					columnIndex = 0;
				}
			}
		}
		cout << endl;
    }
    int additionalIndex = 0;
	for (i = 1; i < size; i++) {
		additionalIndex = i;
    	for (j = 4; j >= i; j--) {
    		additionalIndex++;
    		cout << matrix[j][additionalIndex-1] << " ";
		}
		if(matrix[i-j][j] < matrix[lineIndex][columnIndex] && matrix[i-j][j] < 0){
				containerForValue = matrix[lineIndex][columnIndex];
				matrix[lineIndex][columnIndex] = matrix[j][additionalIndex-1];
				matrix[j][additionalIndex-1] = containerForValue;
				if(columnIndex < size){
					columnIndex++;
				}else{
					lineIndex++;
					columnIndex = 0;
				}
			}
		cout << endl;
    }
    cout << "\nSorted Matrix:" << endl;
    PrintMatrix(matrix, size, size);
}
