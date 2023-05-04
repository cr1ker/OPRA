#include "dll_lib.h"
#include <windows.h>
#include <string>
using namespace std;

string __declspec(dllexport) ModifyWordByReplaceSpaces(string word){
	string modifiedWord;
	short countOfSpaces = 0, wordLength = 0;
	for(int i = 0; i < word.size(); i++){
		if(word[i] != ' '){
			modifiedWord += word[i];
		}else{
			countOfSpaces++;
		}
	}
	for(int i = 0; i < countOfSpaces;i++){
		modifiedWord += ' ';
	}
	return modifiedWord;
}
