#include "dll_lib.h"
#include <windows.h>

int __declspec(dllexport) GetArrayEvenPositiveValues(int array[]){
	int countOfEvenValues;
	for(int i = 0; i < sizeof(array); i++){
		if(array[i] % 2 == 0 && array[i] > 0){
			countOfEvenValues++;
		}
	}
	return countOfEvenValues;
}
