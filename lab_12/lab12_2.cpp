/* Dzhevzhyk Andrii KN 1-2*/
/*LAB 12*/
/*Написати символьну функцію яка модіфікує, що переносить усі пробіли в кінець*/
#include <iostream>
using namespace std;

string ModifyWordByReplaceSpaces(string word);

int main() {
	system("cls");
	string userWord;
	string modifiedWord;
	cout << "Write your word for modify:" << endl;
	getline(cin, userWord);
	modifiedWord = ModifyWordByReplaceSpaces(userWord);
	cout << "Modified word with replaced spaces: - " << modifiedWord;

}

string ModifyWordByReplaceSpaces(string word){
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

