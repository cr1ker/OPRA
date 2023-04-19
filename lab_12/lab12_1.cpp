/* Dzhevzhyk Andrii KN 1-2*/
/*LAB 12*/
/*Написати логічну функцію яка визначає чи є слово паліндромом*/
#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

bool IsWordPalindrom(string wordByUser);

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

bool IsWordPalindrom(string wordByUser){
	string palindrom = wordByUser;
	reverse(palindrom.begin(), palindrom.end());
	return wordByUser == palindrom;
}
