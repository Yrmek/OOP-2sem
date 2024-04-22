//9. »сключить из строки группы символов, расположенные между символами '('
//и ')' вместе со скобками.≈сли нет символа ')' дл€ С(С, то исключить все символы до
//	конца строки после '(. 
#include <iostream>
#include <string>

using namespace std;

string removeParentheses(const std::string& input) {
  string result;
    bool inParentheses = false;

    for (char c : input) {
        if (c == '(') {
            inParentheses = true;
        }
        else if (c == ')') {
            inParentheses = false;
        }
        else if (!inParentheses) {
            result.push_back(c);
        }
    }

    return result;
}

int main() {
    string input;
    input.assign("ab(cd)ef(gh)avaaa(asd(sdasdsad(AS)dasd");
    input.append("bibibib");
    string output = removeParentheses(input);

    cout << "Input: " << input << std::endl;
    cout << "Output: " << output << std::endl;

    return 0;
}