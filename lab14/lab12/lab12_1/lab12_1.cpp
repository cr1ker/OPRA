#include "dll_lib.h"
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int main() {
	system("cls");
	string userWord;
	bool isWordPalindrom;
	cout << "Write your word:" << endl;
	cin >> userWord;
	cout << "Is your word palindrom? - ";
	if(IsWordPalindrom(userWord)){
		cout << "Yes";
	}else{
		cout << "No";
	}
}
