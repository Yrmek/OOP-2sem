//9. Даны натуральное число n, действительные числа a1, a2, ..., a2n.Получить
//min(, , ..., ) a1 + a2n a2 + a2n−1 an + an + 1
#include "doubleLinkedList.h"
#include <iostream>
#include <time.h>

using namespace std;


void fill_list(DoubleLinkedList<double>& list, int quantity)
{
	srand(time(NULL));
	double key;
	for (int i = 0; i < quantity; i++)
	{
		key = rand() % 100;
		list.add(key);
	}
}


double find_min_sum(DoubleLinkedList<double>& list)
{
	double min = list.getHead()->data + list.getTail()->data;
	Node<double>* tail = list.getTailRef();
	Node<double>* head = list.getHeadRef();
	do
	{
		if (min > head->data + tail->data) min = head->data + tail->data;
		head = head->next;
		tail = tail->prev;
	} while (head->next != tail);
	return min;
}

int main()
{

	int n = 0;
	cout << "Enter value of n :" << endl;
	cin >> n;
	DoubleLinkedList<double> list;
	fill_list(list, 2 * n);
	list.print();
	cout << endl;
	cout << "Min sum =" << find_min_sum(list);
	return 0;
}