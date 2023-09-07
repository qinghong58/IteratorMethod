#pragma once
#include<iostream>
#include"Counter.h"
using namespace std;
template<typename T>
class SmartPoint
{
private:
	//成员变量
	Counter* ct;
	T* ptr;
public:
	//无参构造
	SmartPoint() :ct(nullptr), ptr(nullptr) {};

	//有参构造
	SmartPoint(T* _ptr) :ct(new Counter), ptr(_ptr)
	{
		ct->sharePtrCount = 1;
	}

	//析构函数
	~SmartPoint()
	{
		if (ct!=nullptr)
		{
			--(ct->sharePtrCount);
		}
		if (ct->sharePtrCount==0)
		{
			delete ptr;
		}
		ptr = nullptr;
	}

	//拷贝构造
	SmartPoint(const SmartPoint& sp) :ct(sp.ct), ptr(sp.ptr)
	{
		if (ct!=nullptr)
		{
			++(ct->sharePtrCount);
		}
	}
	//拷贝赋值
	SmartPoint& operator=(const SmartPoint& sp)
	{
		if (&sp==this)
		{
			return *this;
		}
		if (ct!=nullptr)
		{
			--(ct->sharePtrCount);
			if (ct->sharePtrCount == 0)
			{
				delete ptr;
				ptr = nullptr;
			}

		}
		ptr = sp.ptr;
		ct = sp.ct;
		if (ct!=nullptr)
		{
			++(ct->sharePtrCount);
		}
		return *this;

	}

	//移动构造
	SmartPoint(SmartPoint&& sp)noexcept :
		ptr(exchange(sp.ptr, nullptr)),
		ct(exchange(sp.ct, nullptr)) {};

	//移动赋值
	SmartPoint& operator=(SmartPoint&& sp)noexcept
	{
		if (&sp==this)
		{
			return *this;
		}
		if (ptr!=nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}
		ptr = exchange(sp.ptr, nullptr);
		ct = exchange(sp.ct, nullptr);

		return *this;
	}

	T* get()
	{
		return ptr;
	}
	bool unique()
	{
		return ct->sharePtrCount == 1;
	}
	T& operator*()
	{
		return *ptr;
	}
	T* operator->()
	{

		return ptr;
	}
	size_t use_count()
	{
		return ct ? ct->sharePtrCount : 0;
	}
};

template<typename T>
auto make_SmartPoint(T v)
{
	return SmartPoint<T>{new T(v)};
}
