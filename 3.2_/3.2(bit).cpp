//9. Компоненты файла f – целые числа.Получить файл g из чисел исходного
//файла, в котором записаны сначала все четные числа, затем все нечетные числа.

#include <iostream>
#include <fstream>

using namespace std;

void SplitNumbers(const string& infilename, const string& outfilename)
{
    fstream infile(infilename, ios::binary |ios::in|ios::out);
    ofstream outfile(outfilename ,ios::binary);
    outfile.clear();
    int num;

    int n = 0;
    cout << "Enter amount n of numbers in file :" << endl;
    cin >> n;
    if (n < 0) return;
    for (int i = 0; i < n; ++i)
    {
        infile << rand() % 1000 ;
    }
    infile.clear();
    infile.seekg(0, ios::beg);

    while (infile.read(reinterpret_cast<char*>(&num), sizeof(num)))
    {
        if (num % 2 == 0) outfile.write(reinterpret_cast<char*>(&num), sizeof(num));
    }
    infile.clear();
    infile.seekg(0, ios::beg);

    while (infile.read(reinterpret_cast<char*>(&num), sizeof(num)))
    {
        if (!(num % 2 == 0)) outfile.write(reinterpret_cast<char*>(&num), sizeof(num));
    }
}

int main()
{
    SplitNumbers("input.bin", "output.bin");
    return 0;
}