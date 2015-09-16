#include "queue.h"
#include <iostream>

int main(void)
{
	MyQueue<char> test1;
	MyQueue<char> test2(4);
	test2.put('h');
	test2.put('h');
	test2.put('h');
	test2.put('h');
	test1.put('h');
	test1.put('h');
	test1.put('h');
	std::cout << test1.size() << test1.take() << test2.get(2) << std::endl;
	return 0;
}
