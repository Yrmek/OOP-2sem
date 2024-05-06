//9. «аписать в новую строку слова исходной строки, в которых буквы упор€дочены
//по алфавиту

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string getNewString(vector<string> words) {
    string output;
    char buf = 0;
    for (const auto& i : words) {
        bool istrue = 0;
        buf = 0;
        for (const auto& j : i) {
            if (buf > j) {
                istrue = 0;
                break;
            }
            else {
                istrue = 1;
            }
            buf = j;
        }
        if (istrue) {
            output.append(i);
            output.append(" ");
        }
    }
    return output;
}

vector<string> getWords(string input) {
    istringstream iss(input);
    vector<string> words;

    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

void main()
{
	string input("bib pop abcegy bobka bceop cocpc egoql");
    cout << "Initial string : " << input <<endl;
    vector<string> words = getWords(input);
    string output = getNewString(words);
    cout <<"New transformed string : "<< output;
}