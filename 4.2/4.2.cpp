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
	LinkedList<char>::Node* current;
	current = top.head;
	LinkedList<char>::Node* prev = nullptr;

	while (current != nullptr)
	{
		if (current->data == top1.head->data)
		{
			LinkedList<char>::Node* tempMain = current;
			LinkedList<char>::Node* tempSub = top1.head;

			while (tempMain != nullptr && tempSub != nullptr && tempMain->data == tempSub->data)
			{
				tempMain = tempMain->next;
				tempSub = tempSub->next;
			}

			if (tempSub == nullptr)
			{
				if (prev == nullptr)
				{
					top.head = tempMain;
					current = top.head;
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
void TestClass()
{
	LinkedList<int> list2(42);
	LinkedList<int> list3(list2);
	LinkedList<int> list4(move(list3));
	LinkedList<int> list1(1);
	list1 = list2;
	list1 = move(list2);
}
int main()
{
	TestClass();
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
	for (int i = 0; i < quantity; i++) {
		LinkedList<char>::Node* ppv = NULL;
		LinkedList<char>::Node* nv = new LinkedList<char>::Node;
		cin >> nv->data; //rand() % 25 + 65;
		nv->next = NULL;
		if (!top.head)
			top.head = nv;
		else
		{
			nv->next = top.head;
			top.head = nv;
		}
	}
}

void print_list(LinkedList<char>& top)
{
	LinkedList<char>::Node* current = top.head;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}