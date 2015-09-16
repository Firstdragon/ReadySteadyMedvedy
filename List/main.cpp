#include "list.h"
#include <iostream>

int main()
{
	IList<int> list;

	list.add(1);
	list.add(2);
	list.add(3);
	list.add(2);
	list.add(1);
	list.add(2);

	list.size();

	list.numberOf(2);

	list.removeAll(1);

	list.size();

	return 0;
}