#include "dll_lib.h"
#include <windows.h>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

bool __declspec(dllexport) IsWordPalindrom(string wordByUser){
	string palindrom = wordByUser;
	reverse(palindrom.begin(), palindrom.end());
	return wordByUser == palindrom;
}
