#pragma once
#include "interfaces.h"


class Exception {};


template <class T> class MyQueue 
{
	struct node
	{
		T elem;
		node* next;
	};

private:
	node* ptr;

public:
	MyQueue(void);

	~MyQueue();

	virtual void put(const T& fact);

	virtual T take();
	
	virtual T get(int i) const;
    
	virtual int size() const;
};

template <class T> MyQueue<T>::MyQueue() : ptr(nullptr)            // Отдельный конструктор копирования и оператор присваивания не требуются, 
{                                                                  // достаточно и побитового переноса.
} 

template <class T> MyQueue<T>::~MyQueue()                          // Уничтожаю указатель и создаю пустой.
{
	delete ptr;
	ptr = nullptr;
}

template <class T> void MyQueue<T>::put(const T& fact)             // Если элементов не было, то создаю новый указатель и оставляю указатель на него.
{                                                                  // Если элементы были, то передаю указатель на остальные элементы новому элементу.
	node* newel = new node();                                  // А начальный указатель перенаправляю на новый элемент.
	newel->elem = fact;
	if (ptr)                                            
	{
		newel->next = ptr->next;
		ptr->next = newel;
		ptr = ptr->next;
	}
	else
	{
		ptr = newel;
		ptr->next = ptr;
	}
	return;
}

template <class T> T MyQueue<T>::take()                            // Если элемент один, то передаю верхний и чищу указатель
{                                                                  // Если же несколько, то передаю верхний и удаляю указатель на него и его значение.
	if (!ptr)
	{
		Exception();
	}
	T tmpel = ptr->next->elem;
	if (ptr->next == ptr)
	{
		delete ptr;
		ptr = nullptr;
		return tmpel;
	}
    node* newel = ptr->next;
	ptr->next = newel->next;
	delete newel;
	newel = nullptr;
	return tmpel;
}

template <class T> T MyQueue<T>::get(int i) const                 // Переход по указаталю *next, пока не получим i-ый элемент.
{
	if ((size() <= i) || (!ptr))
	{
		throw Exception();
	}
	int count = 0;
	node* top = ptr;
	while (count != i)                                       // Сложность - О(N).
	{
		count++;
		top = top->next;
	}
	return top->next->elem;
}

template <class T> int MyQueue<T>::size() const                 // Проверяю на наличие элементов, после чего перехожу
{                                                               // по указателям с счетчиком, пока не дойду до конца
	if (!ptr)                                               // И передаю счетчик.
	{
		return 0;
	}
	int count = 0;
	const node* snode = ptr->next;
    do                                                          // Сложность - О(N).
	{
		count++;
		snode = snode->next;
	} while (snode != ptr->next);
	return count;
}
