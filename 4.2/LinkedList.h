#pragma once
#include <iostream>
using namespace std;

template < class T>
class LinkedList {
public:
    struct Node {
        T data;
        Node* next;
    };
	Node* head;

	//конструкторы
LinkedList() : head(nullptr) { cout << "Test constructor by default: OK" << endl; }
	LinkedList(const T& data){
		Node* head = new Node;
		head->data = data;
		head->next = nullptr;
        this->head = head;
        cout << "Test constructor with one parameter: OK" << endl;
	}

    LinkedList(const LinkedList& other) : head(nullptr) {
        if (other.head != nullptr) {
            Node* current = other.head;
            while (current != nullptr) {
                add(current->data);
                current = current->next;
            }
            cout << "Test copy constructor: OK" << endl;
        }
    } //конструктор копирования

    LinkedList& operator= (const LinkedList& other) { // оператор копирования 
        if (this != &other) {
            head = nullptr;
            if (other.head != nullptr) {
                Node* current = other.head;
                while (current != nullptr) {
                    add(current->data);
                    current = current->next;
                }
            }
        }
        cout << "Test operator by copy: OK" << endl;
        return *this;
    }

    LinkedList(LinkedList&& other) : head(other.head) { // конструктор перемещения
        other.head = nullptr;
        cout << "Test move constructor: OK" << endl;
    }

    LinkedList& operator=(LinkedList&& other) { //оператор перемещения
        if (this != &other) {
            swap(head, other.head);
        }
        cout << "Test operator by move: OK" << endl;
        return *this;
    }

	//деструктор
	~LinkedList() {
		Node* current = head;
		while (current) {
			Node* next = current->next;
			delete current;
			current = next;
		}
        cout << "Test destructor : OK" << endl;
	}
    void initialize(const T& data) {
        Node* head = new Node;
        head->data = data;
        head->next = nullptr;
        this->head = head;
    }

    void add(const T& data) {
        if (!head) {
            initialize(data);
        }
        else {
            Node* newNode = new Node;
            Node* buf = head;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
        }
    }

    void remove(const T& key) {
        Node* current = head;
        Node* prev = nullptr;

        while (current) {
            if (current->data == key) {
                if (prev) {
                    prev->next = current->next;
                }
                else {
                    head = current->next;
                }
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }
    }
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node* search(const T& key) {
        Node* current = head;
        while (current) {
            if (current->data == key) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete[] current;
            current = next;
        }
    }
};
