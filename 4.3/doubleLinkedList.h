#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

template < class T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    //конструкторы
    DoubleLinkedList() : head(nullptr), tail(nullptr) {
        cout << "Test constructor by default: OK" << endl;
    }
    DoubleLinkedList(const T& data) {
        Node<T>* head = new Node<T>;
        head->data = data;
        head->next = nullptr;
        head->prev = nullptr;
        this->head = head;
        this->tail = head;
        cout << "Test constructor with one parameter: OK" << endl;
    }

    DoubleLinkedList(const DoubleLinkedList& other) : head(nullptr) {
        if (other.head != nullptr) {
            Node<T>* current = other.head;
            while (current != nullptr) {
                add(current->data);
                current = current->next;
            }
            cout << "Test copy constructor: OK" << endl;
        }
    } //конструктор копирования



    DoubleLinkedList(DoubleLinkedList&& other) : head(other.head) { // конструктор перемещения
        other.head = nullptr;
        cout << "Test move constructor: OK" << endl;
    }

    DoubleLinkedList& operator= (const DoubleLinkedList& other) {
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

    DoubleLinkedList& operator=(DoubleLinkedList&& other) {
        if (this != &other) {
            swap(head, other.head);
        }
        cout << "Test operator by move: OK" << endl;
        return *this;
    }

    Node<T>* getHead() const {
        return head;
    }

    Node<T>* getTail() const {
        return tail;
    }

    Node<T>*& getHeadRef() {
        return head;
    }

    Node<T>*& getTailRef() {
        return tail;
    }

    void initialize(const T& data) {
        Node<T>* head = new Node<T>;
        head->data = data;
        head->next = nullptr;
        head->prev = nullptr;
        if (!this->head) {
            this->head = head;
            this->tail = head;
        }
        else {
            tail->next = head;
            head->prev = tail;
            this->tail = head;
        }
    }

    void add(const T& data) {
        if (!head) {
            initialize(data);
        }
        else {
            Node<T>* newNode = new Node<T>;
            newNode->data = data;
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
  
    void print() {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node<T>* search(const T& key) {
        Node<T>* current = head;
        while (current) {
            if (current->data == key) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void  clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete[] current;
            current = next;
        }
    }

    //деструктор
    ~DoubleLinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
};
