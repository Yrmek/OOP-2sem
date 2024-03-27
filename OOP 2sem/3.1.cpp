//Компоненты файла f – целые числа.Получить файл g из чисел исходного
//файла, в котором записаны сначала все четные числа, затем все нечетные числа.

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void SplitNumbers(const string& infilename, const string& outfilename) 
{
    fstream infile(infilename,ios::trunc);
    ofstream outfile(outfilename, ios::trunc);

    int n = 0;
    cout << "Enter amount n of numbers in file :" << endl;
    cin >> n;
    if (n < 0) return;
    for (int i = 0; i < n; ++i)
    {
        infile << rand() % 1000 << " ";
    }
    infile.clear();
    infile.seekg(0, ios::beg);

    int num;
    while (infile >> num)
    {
        if (num % 2 == 0) outfile << num << " ";
    }
    infile.clear();
    infile.seekg(0, ios::beg);

    while (infile >> num)
    {
        if (!(num % 2 == 0)) outfile << num << " ";
    }
}

int main() 
{
    SplitNumbers("input.txt","out_put.txt");
    return 0;
}