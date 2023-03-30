/* Dzhevzhyk Andrii KN 1-2*/
/*LAB 11*/
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
	int matrix[size][size];
	int minElement = 0;
	int lineIndex = 0, columnIndex = 0;
	int containerForValue;
	cout << "Not Sorted Matrix:" << endl;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			matrix[i][j] = rand() % 100 - 50;
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
	
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
    for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			matrix[i][j];
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
}
