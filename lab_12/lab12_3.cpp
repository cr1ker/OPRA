/* Dzhevzhyk Andrii KN 1-2*/
/*LAB 12*/
/*Написати числову функцію для пошуку кількості парних додатних елементів в одновимірному масиві*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int GetArrayEvenPositiveValues(int array[]);

int main() {
	system("cls");
	srand(time(NULL));
	int array[10];
	for(int i = 0; i < 10; i++){
		array[i] = rand() % 100 - 50;
		printf("%4d", array[i]);
	}
	cout << "\nNumber of Even Positive Values = " << GetArrayEvenPositiveValues(array); 
}

int GetArrayEvenPositiveValues(int array[]){
	int countOfEvenValues;
	for(int i = 0; i < sizeof(array); i++){
		if(array[i] % 2 == 0 && array[i] > 0){
			countOfEvenValues++;
		}
	}
	return countOfEvenValues;
}
