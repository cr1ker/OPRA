#include "dll_lib.h"
#include <windows.h>

int __declspec(dllexport) FindNegativeMatrixValues(int column[]){
	int countOfNegativeElements;
	for(int i = 0; i < sizeof(column); i++){
		if(column[i] < 0){
			countOfNegativeElements++;
		}
	}
	return countOfNegativeElements;
}
