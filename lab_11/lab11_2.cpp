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
	int line = 5, column = 6;
	int matrix[line][column];
	cout << "Not Sorted Matrix:" << endl;
	for(i = 0; i < line; i++){
		for(j = 0; j < column; j++){
			matrix[i][j] = rand() % 100 - 50;
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
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
	for(i = 0; i < line; i++){
		for(j = 0; j < column; j++){
			printf("%4d", matrix[i][j]);
		}
		cout << endl;
	}
}
