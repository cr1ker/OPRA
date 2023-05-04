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
	int i;
	const int sizeOfArray = 10;
	int sizeOfSortedArray = 0, acceptedIndex = 0, sortedArrayIndex = 0;
	int array[sizeOfArray];
	cout << "Array: ";
	CreateArray(array, sizeOfArray);
	PrintArray(array, sizeOfArray);
	cout << "\nWrite your index:" << endl;
	cin >> acceptedIndex;
	for(i = 0; i <= acceptedIndex; i++){
		if(i % 2 == 1){
			sizeOfSortedArray++;
		}
	}
	int sortedArray[sizeOfSortedArray];
	for(i = 0; i < sizeOfArray; i++){
		if(i % 2 == 1 && i <= acceptedIndex){
			sortedArray[sortedArrayIndex] = array[i];
			sortedArrayIndex++;
		} 
	}
	cout << "Not Sorted Array:";
	PrintArray(sortedArray, sizeOfSortedArray);
	int currentElement = 1, nextElement = 2, variableForSavePreviousElement;
	while(currentElement < sizeOfSortedArray){
		if(sortedArray[currentElement - 1] <= sortedArray[currentElement]){
			currentElement = nextElement;
			nextElement++;
		}else{
			variableForSavePreviousElement = sortedArray[currentElement - 1];
			sortedArray[currentElement - 1] = sortedArray[currentElement];
			sortedArray[currentElement] = variableForSavePreviousElement;
			currentElement--;
			if(currentElement == 0){
				currentElement = nextElement;
				nextElement++;
			}
		}
	}
	cout << "\nSorted Array:";
	PrintArray(sortedArray, sizeOfSortedArray);
}
