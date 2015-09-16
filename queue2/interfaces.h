#pragma once


template <class T> class IQueue
{
public:
	virtual void put(const T& elem) = 0;

	virtual T take() = 0;

	virtual T get(int i) const = 0;

	virtual int size() const = 0;
};
