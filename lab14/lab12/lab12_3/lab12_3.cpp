#include "dll_lib.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

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
