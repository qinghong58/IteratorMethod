#pragma once
#include<iostream>
#include"Counter.h"
using namespace std;
template<typename T>
class SmartPoint
{
private:
	//��Ա����
	Counter* ct;
	T* ptr;
public:
	//�޲ι���
	SmartPoint() :ct(nullptr), ptr(nullptr) {};

	//�вι���
	SmartPoint(T* _ptr) :ct(new Counter), ptr(_ptr)
	{
		ct->sharePtrCount = 1;
	}

	//��������
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

	//��������
	SmartPoint(const SmartPoint& sp) :ct(sp.ct), ptr(sp.ptr)
	{
		if (ct!=nullptr)
		{
			++(ct->sharePtrCount);
		}
	}
	//������ֵ
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

	//�ƶ�����
	SmartPoint(SmartPoint&& sp)noexcept :
		ptr(exchange(sp.ptr, nullptr)),
		ct(exchange(sp.ct, nullptr)) {};

	//�ƶ���ֵ
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
