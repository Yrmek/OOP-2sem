#include "LinkedList.h"
using namespace std;


#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void print_list(LinkedList<char>& );
void fill_list(LinkedList<char>&, int);

void deleteSublist(LinkedList<char>& top, LinkedList<char>& top1)
{
	Node<char>* current;
	current = top.getHead();
	Node<char>* prev = nullptr;

	while (current != nullptr)
	{
		if (current->data == top1.getHead()->data)
		{
			Node<char>* tempMain = current;
			Node<char>* tempSub = top1.getHead();

			while (tempMain != nullptr && tempSub != nullptr && tempMain->data == tempSub->data)
			{
				tempMain = tempMain->next;
				tempSub = tempSub->next;
			}

			if (tempSub == nullptr)
			{
				if (prev == nullptr)
				{
					top.getHeadRef() = tempMain;
					current = top.getHead();
				}
				else
				{
					prev->next = tempMain;
					current = prev;
				}
			}
		}
		prev = current;
		if (current != nullptr)
		{
			current = current->next;
		}
	}
	
}

int main()
{
	/*TestClass();*/
	srand(time(NULL));
	cout << "Enter quantity of elements in lists" << endl;
	int quantity;
	int quantity1;
	cin >> quantity >> quantity1;

	LinkedList<char> top_l;
	LinkedList<char> top_l1;

	fill_list(top_l, quantity);
	cout << "List L:" << endl;
	print_list(top_l);

	fill_list(top_l1, quantity1);
	cout << "List L1:" << endl;
	print_list(top_l1);

	deleteSublist(top_l, top_l1);
	cout << "Transformed list L without data of L1:" << endl;
	print_list(top_l);
	return 0;
}

void fill_list(LinkedList<char>& top, int quantity)
{
	Node<char>* current = top.getHead();
	Node<char>* newNode = NULL;
	for (int i = 0; i < quantity; i++) {
		newNode = new Node<char>;
		cin >> newNode->data; //rand() % 25 + 65;
		newNode->next = NULL;
		if (!current) {
			top.getHeadRef() = newNode;
			current = top.getHead();
		}
		else {
			current->next = newNode;
			current = newNode;
		}
	}
}

void print_list(LinkedList<char>& top)
{
	Node<char>* current = top.getHead();
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}