#include <iostream>
#include <fstream>

using namespace std;

void SplitNumbers(const string& infilename, const string& outfilename)
{
    fstream infile(infilename, ios::binary |ios::in|ios::out);
    ofstream outfile(outfilename ,ios::binary);
    outfile.clear();
    int num;

    int data[] = { 1, 2, 3, 4, 5 ,6 ,7 ,8 , 1 , 2 ,3};
    infile.write(reinterpret_cast<const char*>(&data), sizeof(data));
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