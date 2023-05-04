#include "dll_lib.h"
#include "stat_lib.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

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
