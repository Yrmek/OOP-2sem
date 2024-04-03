#include "Vector.h"
#include <iostream>
#include <time.h>
using  namespace std;

void Vector::SetSize(int s) {
    this->size = s;
    AllocMem(s);
}

int Vector::GetSize() {
    return size;
}

void Vector::FillRand() {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        elements[i] = rand() % 100; // Заполнение случайными числами от 0 до 99
    }
}

void Vector::Print() {
    int vecsize = this->GetSize();
    for (int i = 0; i < vecsize; ++i) {
        cout << " |" << elements[i] << "|";
    }
    cout << endl;
}

void Vector::AllocMem(int newsize) {
    if (newsize > capacity) {
        int newcapacity = newsize * 2;
        int* newelements = new int[newcapacity];
        for (int i = 0; i < size; ++i) {
            newelements[i] = elements[i];
        }
        delete[] elements;
        elements = newelements;
        capacity = newcapacity;
    } 
}

void Vector::Append(int val) {
    AllocMem(size + 1);
    elements[size] = val;
    size++;
}