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

int& Vector:: operator[](int index) {
    if (index < 0 || index >= size) {
        throw ("Index out of Bounds");
    }
    return elements[index];
}

ostream& operator<<(ostream& os, Vector& vec) {
    for (int i = 0; i < vec.size; ++i) {
        os << vec.elements[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, Vector& vec) {
    for (int i = 0; i < vec.size; ++i) {
        is >> vec.elements[i];
    }
    return is;
}
Vector& Vector::operator=(Vector&& other) {  // оператор перемещения
    if (this != &other) {
        swap(size, other.size);
        swap(capacity, other.capacity);
        swap(elements, other.elements);
    }
    return *this;
}

Vector& Vector::operator=(const Vector& other) {  // оператор копировния
    if (this != &other) {
        delete[] elements;
        size = other.size;
        capacity = other.capacity;
        elements = new int[capacity];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}