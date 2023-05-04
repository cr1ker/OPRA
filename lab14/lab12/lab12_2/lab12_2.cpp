#include "dll_lib.h"
#include <iostream>

using namespace std;


int main() {
	system("cls");
	string userWord;
	string modifiedWord;
	cout << "Write your word for modify:" << endl;
	getline(cin, userWord);
	modifiedWord = ModifyWordByReplaceSpaces(userWord);
	cout << "Modified word with replaced spaces: - " << modifiedWord;

}
