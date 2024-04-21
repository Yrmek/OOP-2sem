#include"LinkedList.h"

using namespace std;

template < class T>
void LinkedList<T>::initialize(const T & data) {
    Node<T>* head = new Node<T>;
    head->data = data;
    head->next = nullptr;
    if (!this->head) {
        this->head = head;
        this->tail = head;
    }
    else {
        tail->next = head;
        this->tail = head;
    }
}


template < class T>
void  LinkedList<T>::add(const T& data) {
    if (!head) {
        initialize(data);
    }
    else {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
}

template < class T>
void LinkedList<T>::print() {
    Node<T>* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template < class T>
Node<T>* LinkedList<T>:: search(const T& key) {
    Node<T>* current = head;
    while (current) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template < class T>
void  LinkedList<T>::clear() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete[] current;
        current = next;
    }
}