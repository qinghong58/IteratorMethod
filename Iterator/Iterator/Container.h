#pragma once
#include<iostream>
#include"Iterator.h"
#include"algorithm.h"
using namespace std;

template <typename T>
class Container
{
private:
	//容器最大长度
	T *data;
	//当前容器大小
	int size;
	//当前容器容量
	int capacity;

	Iterator<T> iterator;

public:
	Container() :data(nullptr), size(0),capacity(0) {};

	~Container()
	{
		delete[] data;
	}
	void Remove(int index)
	{
		if (index < 0 || index >= size) {
			return;
		}
		// 将要删除的元素之后的元素向前移动一位
		for (int i = index; i < size - 1; ++i) {
			data[i] = data[i + 1];
		}

		// 更新容器大小
		--size;
	}
	void Insert(T element, int index)
	{
		if (index < 0 || index > size) {
			return;
		}

		if (size >= capacity) {
			// 容器已满，需要扩容
			capacity = (capacity == 0) ? 1 : capacity * 2;
			T* new_data = new T[capacity];
			for (int i = 0; i < index; ++i) {
				new_data[i] = data[i];
			}
			// 插入新元素
			new_data[index] = element;
			for (int i = index; i < size; ++i) {

				new_data[i + 1] = data[i];
			}

			delete[] data;
			data = new_data;
			++size;
		}
		else {
			// 插入新元素
			for (int i = size - 1; i >= index; --i) {
				// 向后
				data[i + 1] = data[i];
			}
			data[index] = element;

			++size;
		}
	}
	void Clear()
	{
		// 释放容器
		delete[] data;
		size = 0;
		capacity = 0;


		data = nullptr;
	}
	int Find(T element)
	{
		for (int i = 0; i < size; ++i) {
			if (data[i] == element) {
				// 返回索引
				return i;
			}
		}
		return -1;
	}


	//传入仿函数对象
	template <typename Compared = sort<T>>
	void Sort(const Compared& comp = Compared())
	{
		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size - i - 1; ++j) {
				if (comp(data[j + 1], data[j])) {
					std::swap(data[j], data[j + 1]);
				}
			}
		}
	}


	void Add(T element)
	{
		if (size >= capacity) {
			capacity = (capacity == 0) ? 1 : capacity * 2;

			T* new_data = new T[capacity];
			for (int i = 0; i < size; ++i)
			{
				//复制旧元素到新数组
				new_data[i] = data[i];
			}
			delete[] data;
			data = new_data;
		}
		data[size++] = element;
	}

	Iterator<T> begin()
	{
		return Iterator<T>(data);
	}
	Iterator<T> end()
	{
		return Iterator<T>(data+size);
	}
};

