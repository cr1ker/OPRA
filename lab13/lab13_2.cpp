/* Dzhevzhyk Andrii KN 1-2*/
/*LAB 13*/
/*18 variant  - 2 task*/
/*Написати процедуру для модифікації одновимірного рядка шляхом розташування його елементів за схемою: нульові, потім додатні, а подім віж'ємні*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void CreateArray(int array[], int sizeOfArray);
void PrintArray(int array[], int sizeOfArray);
void ModifyArray(int array[], int sizeOfArray);

int main() {
	system("cls");
	srand(time(NULL));
	int sizeOfArray = 10;
	int array[sizeOfArray];
	CreateArray(array, sizeOfArray);
	PrintArray(array, sizeOfArray);
	cout << endl;
	ModifyArray(array, sizeOfArray);
	cout << "Modified Array:" << endl;
	PrintArray(array, sizeOfArray);
}

void PrintArray(int array[], int sizeOfArray){
	for(int i = 0; i < sizeOfArray; i++){
		printf("%4d", array[i]);
	}
}

void CreateArray(int array[], int sizeOfArray){
	for(int i = 0; i < sizeOfArray; i++){
		array[i] = rand() % 100 - 50;
	}
}

void ModifyArray(int array[], int sizeOfArray){
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

