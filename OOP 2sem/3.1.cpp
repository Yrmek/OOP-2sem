#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readFromFile(const string& filename, vector<int>& numbers) {
    ifstream file(filename);
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }
}

void writeToFile(const string& filename, const vector<int>& numbers) {
    ofstream file(filename);
    file.clear();
    for (auto i = 0; i < numbers.size(); ++i) {
        file << numbers[i] << " ";
    }
}

void splitNumbers(const vector<int>& numbers, vector<int>& evenNumbers, vector<int>& oddNumbers) {
    for (auto i = 0; i < numbers.size(); ++i) {
        if (numbers[i] % 2 == 0) {
            evenNumbers.push_back(numbers[i]);
        }
        else {
            oddNumbers.push_back(numbers[i]);
        }
    }
}

int main() {
    vector<int> numbers;
    readFromFile("input.txt", numbers);

    vector<int> evenNumbers, oddNumbers;
    splitNumbers(numbers, evenNumbers, oddNumbers);

    for (auto i = 0; i < oddNumbers.size(); ++i) {
        evenNumbers.push_back(oddNumbers[i]);
    }

    writeToFile("out_put.txt", evenNumbers);

    return 0;
}