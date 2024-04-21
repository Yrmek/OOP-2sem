#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Vector {
	int* elements;
	int size;
    int capacity;
public:
	Vector() : elements(nullptr), size(0), capacity (0) {} //конструкторы

	Vector(int s) : size(s) , capacity(s) {
		elements = new int[capacity];
	}
    Vector(int s, const int f) : size(s) , capacity (s){
        elements = new int[capacity]{f};
    }

	~Vector() { delete[] elements;  cout << "Test destructor : OK" << endl;} // деструктор 

    // правило 5

    Vector(const Vector& other) : size(other.size), capacity(other.capacity) { // конструктор копирования
        elements = new int[capacity];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
        cout << "Test copy constructor: OK" << endl;
    }

    Vector& operator=(const Vector& other);

    Vector(Vector&& other) : elements(other.elements), size(other.size) , capacity(other.capacity) { // конструктор перемещения 
        other.elements = nullptr;
        other.size = 0;
        other.capacity = 0;
        cout << "Test move constructor: OK" << endl;
    }

    Vector& operator=(Vector&& other);

    // методы
    void SetSize(int s);
    int GetSize();
    void FillRand();
    void Append(int val);
    void AllocMem(int newsize);
    void Print();
    int& operator[](int index);
    friend ostream& operator<<(ostream& os, Vector& vec);
    friend istream& operator>>(istream& is, Vector& vec);
};