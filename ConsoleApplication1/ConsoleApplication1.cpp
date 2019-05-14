#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool isLimit(char c) {
	char lim[] = { ' ', '\t', '\n' };
	for (int i = 0; i < sizeof(lim); ++i)
		if (c == lim[i]) return true;
	return false;
}
	int main() {
		ifstream fin("infile.txt", ios::in | ios::_Nocreate);
		if (!fin) {
			cout << "Error: Can't open file." << endl;
			return 1;
		}
		int count = 0;
		string word;
		ostringstream sentence;
		while (!fin.eof()) {
			char symb;
			while (isLimit(symb = fin.peek())) {
				sentence << symb;
				if (symb == '\n') break;
				fin.seekg(1, ios::cur);
			}
			fin >> word;
			sentence << word;
			char last = word[word.size() - 1];
			if ((last == '.') || (last == '!')) {
				sentence.str("");
				continue;
			}
			if (last == '?') {
				cout << sentence.str();
				sentence.str("");
				count++;
			}
		}
		if (!count) cout << "Вопросительных предложений нет.";
		cout << endl;
		return 0;
}
