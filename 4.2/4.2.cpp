#include "LinkedList.h"
using namespace std;

void main()
{
	LinkedList<int> list(10);
	list.add(12);
	list.add(14);
	list.add(16);
	list.add(18);
	list.remove(16);
	list.display();
}