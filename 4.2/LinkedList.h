#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node* next;
};

template < class T>
class LinkedList {
private:
	Node<T>* head;
    Node<T>* tail;
public:
	//конструкторы
LinkedList() : head(nullptr) { cout << "Test constructor by default: OK" << endl; }
	LinkedList(const T& data){
		Node<T>* head = new Node<T>;
		head->data = data;
		head->next = nullptr;
        this->head = head;
        cout << "Test constructor with one parameter: OK" << endl;
	}

    LinkedList(const LinkedList& other) : head(nullptr) {
        if (other.head != nullptr) {
            Node<T>* current = other.head;
            while (current != nullptr) {
                add(current->data);
                current = current->next;
            }
            cout << "Test copy constructor: OK" << endl;
        }
    } //конструктор копирования

    

    LinkedList(LinkedList&& other) : head(other.head) { // конструктор перемещения
        other.head = nullptr;
        cout << "Test move constructor: OK" << endl;
    }

    LinkedList& operator= (const LinkedList& other) { 
        if (this != &other) {
            head = nullptr;
            if (other.head != nullptr) {
                Node<T>* current = other.head;
                while (current != nullptr) {
                    add(current->data);
                    current = current->next;
                }
            }
        }
        cout << "Test operator by copy: OK" << endl;
        return *this;
    }

    LinkedList& operator=(LinkedList&& other) { 
        if (this != &other) {
            swap(head, other.head);
        }
        cout << "Test operator by move: OK" << endl;
        return *this;
    }


    Node<T>* getHead() const {
        return head;
    }

    Node<T>*& getHeadRef() {
        return head;
    }

    void initialize(const T& data);
    void add(const T& data);
    void print();
    Node<T>* search(const T& key);
    void clear();

	//деструктор
	~LinkedList() {
		Node<T>* current = head;
		while (current) {
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
        cout << "Test destructor : OK" << endl;
	}
};
