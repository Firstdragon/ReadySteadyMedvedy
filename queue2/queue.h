#pragma once
#include "interfaces.h"


const int DEFAULT_CAPACITY = 10;


class ArrException {};


template <class T> class MyQueue 
{
private:
    T* arr;
	int SizeArr;
	int capacity;
public:
	MyQueue();
	MyQueue(int i);
	~MyQueue();

	virtual void put(const T& elem);

	virtual T take();
	
	virtual T get(int i) const;
    
	virtual int size() const;
};

template <class T> MyQueue<T>::MyQueue()
{
	SizeArr = 0;
	capacity = DEFAULT_CAPACITY;
	arr = new T[capacity];
}

template <class T> MyQueue<T>::MyQueue(int i)
{
	if (i <= 0)
		capacity = DEFAULT_CAPACITY;
	else
		capacity = i;
	arr = new T[capacity];
	SizeArr = 0;
}

template <class T> MyQueue<T>::~MyQueue()
{
	delete[] arr;
}

template <class T> void MyQueue<T>::put(const T& elem)
{
	SizeArr++;
	if (SizeArr >= capacity)
	{
		T* NewArr;
		capacity = SizeArr + 1;
		NewArr = new T[capacity];
		for (int i = 0; i < SizeArr; i++)
		{
			NewArr[i] = arr[i];
		}
		delete[] arr;
		arr = NewArr;
	}
	arr[SizeArr - 1] = elem;
	return;
}

template <class T> T MyQueue<T>::take()
{
	if (SizeArr == 0)
	{
		throw ArrException();
	}
	T elem = arr[0];
	SizeArr--;
	for (int i = 0; i < SizeArr; i++)
	{
		arr[i] = arr[i + 1];
	}
	return elem;
}

template <class T> T MyQueue<T>::get(int i) const
{
	if (SizeArr == 0 || i >= SizeArr)
	{
		throw ArrException();
	}
	return arr[i];
}

template <class T> int MyQueue<T>::size() const
{
	return SizeArr;
}
