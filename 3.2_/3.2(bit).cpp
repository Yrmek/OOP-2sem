#include <iostream>
#include <fstream>

using namespace std;

void SplitNumbers(const string& infilename, const string& outfilename)
{
    ifstream infile(infilename,ios::binary);
    ofstream outfile(outfilename ,ios::binary);
    outfile.clear();
    int num;
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