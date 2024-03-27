#include "Vector.h"
#include <iostream>
#include <time.h>
using  namespace std;

void Vector::SetSize(int s) {
    this->size = s;
	delete[] elements;
	this->elements = new int[size];
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