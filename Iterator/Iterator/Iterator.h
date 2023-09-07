#pragma once
#include<iostream>

template <typename T>
class Iterator
{
private:
	T* ptr;

public:
	Iterator() {};
	explicit Iterator(T* _ptr) :ptr(_ptr) {};

	//*ÔËËã·û
	T operator*()const 
	{
		return *ptr;
	}

	Iterator& operator++()
	{
		++ptr;
		return *this;
	}

	bool operator!= (const Iterator& other)const
	{
		return ptr != other.ptr;
	}
};

