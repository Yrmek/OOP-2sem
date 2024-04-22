//9. Получить все натуральные числа 106
//, которые являются палиндромами как
//в десятичной, так и в шестнадцатиричной системах.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXNUM = 10e6;

string decToHex(int dec) {
    string digits[16] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
    string hex;
    do
    {
        hex.insert(0, digits[dec % 16]);
        dec /= 16;
    } while (dec != 0);
    return hex;
}

int countDigits(int num) {
    int digits = 0;
    while (num) {
        num /= 10;
        digits++;
    }
    return digits;
}

void findPalindroms(vector<bool> numbers) {
    for (int i = 5665; i < MAXNUM; i++) {
        int revnum = 0;
        int rate = 10;
        if (i % rate == 0 && i / 10 == 0) continue;
        int buf = i;
        while (buf != 0) {
            revnum *= 10;
            revnum += buf % rate;
            buf /= 10;
        }
        if (i == revnum) {
            string hexnum = decToHex(i);
            if (hexnum.length() < 2) continue;
            for (int j = 0; j < hexnum.length(); ++j) {
                if (hexnum[j] != hexnum[hexnum.length() - j - 1]) {
                    numbers[i] = false;
                    break;
                }
                else {
                    numbers[i] = true;
                }
            }
            if (numbers[i]) cout << i << " - " << hexnum << endl;
        }
    }
}

int main()
{
    vector<bool> palindrom(MAXNUM, false);
    findPalindroms(palindrom);
}