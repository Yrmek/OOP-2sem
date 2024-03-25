//Компоненты файла f – целые числа.Получить файл g из чисел исходного
//файла, в котором записаны сначала все четные числа, затем все нечетные числа.

#include <iostream>
#include <fstream>

using namespace std;

void SplitNumbers(const string& infilename, const string& outfilename) 
{
    ifstream infile(infilename);
    ofstream outfile(outfilename);
    outfile.clear();
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