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
	Node head;

	//������������
	LinkedList : head(nullptr) {}
	LinkedList(T data) {
		head = new Node;
		head->data = data;
		head->next = nullptr;
	}

    LinkedList(const LinkedList& other) : head(other.head) {} //����������� �����������

    LinkedList& operator= (const LinkedList& other) { // �������� ����������� 
        if (this != &other) {
            this.clear();
            head = other.head;
        }
        return *this;
    }

    LinkedList(LinkedList&& other) : head(other.head) { // ����������� �����������
        other.clear();
    }

    LinkedList& operator=(LinkedList& other) { //�������� �����������
        if (this != &other) {
            swap(head, other.head);
        }
        return *this;
    }

	//����������
	~LinkedList() {
		Node* current = head;
		while (current) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}
    void initialize(T data) {
        head = new Node;
        head->data = data;
        head->next = nullptr;
    }

    void add( T data) {
        if (!head) {
            initialize(data);
        }
        else {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
        }
    }

    void remove(T key) {
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

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << std::endl;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

};