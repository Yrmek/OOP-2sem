#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Vector {
	int* elements;
	int size;
public:
	Vector() : elements(nullptr), size(0) {} //конструкторы

	Vector(int s) : size(s) {
		elements = new int[size];
	}
    Vector(int s, const int f) : size(s) {
        elements = new int[size]{f};
    }

	~Vector() { delete[] elements; } // деструктор 

    // правило 5

    Vector(const Vector& other) : size(other.size) { // конструктор копирования
        elements = new int[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }

    Vector& operator=(const Vector& other) {  // оператор копировния
        if (this != &other) {
            delete[] elements;
            size = other.size;
            elements = new int[size];
            for (int i = 0; i < size; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    Vector(Vector&& other) : elements(other.elements), size(other.size) { // конструктор перемещения 
        other.elements = nullptr;
        other.size = 0;
    }

    Vector& operator=(Vector&& other)  {  // оператор перемещения
        if (this != &other) {
            swap(size, other.size);
            swap(elements, other.elements);
        }
        return *this;
    }

    // методы
    void SetSize(int s);
    int GetSize();
    void FillRand();

    // перегрузка операторов
    
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw;
        }
        return elements[index];
    }

    friend ostream& operator<<(ostream& os, Vector& vec) {
        for (int i = 0; i < vec.size; ++i) {
            os << vec.elements[i] << " ";
        }
        return os;
    }

    friend istream& operator>>(istream& is, Vector& vec) {
        for (int i = 0; i < vec.size; ++i) {
            is >> vec.elements[i];
        }
        return is;
    }
};