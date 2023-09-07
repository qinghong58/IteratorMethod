#pragma once
#include<iostream>
#include"Iterator.h"
#include"algorithm.h"
using namespace std;

template <typename T>
class Container
{
private:
	//������󳤶�
	T *data;
	//��ǰ������С
	int size;
	//��ǰ��������
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
		// ��Ҫɾ����Ԫ��֮���Ԫ����ǰ�ƶ�һλ
		for (int i = index; i < size - 1; ++i) {
			data[i] = data[i + 1];
		}

		// ����������С
		--size;
	}
	void Insert(T element, int index)
	{
		if (index < 0 || index > size) {
			return;
		}

		if (size >= capacity) {
			// ������������Ҫ����
			capacity = (capacity == 0) ? 1 : capacity * 2;
			T* new_data = new T[capacity];
			for (int i = 0; i < index; ++i) {
				new_data[i] = data[i];
			}
			// ������Ԫ��
			new_data[index] = element;
			for (int i = index; i < size; ++i) {

				new_data[i + 1] = data[i];
			}

			delete[] data;
			data = new_data;
			++size;
		}
		else {
			// ������Ԫ��
			for (int i = size - 1; i >= index; --i) {
				// ���
				data[i + 1] = data[i];
			}
			data[index] = element;

			++size;
		}
	}
	void Clear()
	{
		// �ͷ�����
		delete[] data;
		size = 0;
		capacity = 0;


		data = nullptr;
	}
	int Find(T element)
	{
		for (int i = 0; i < size; ++i) {
			if (data[i] == element) {
				// ��������
				return i;
			}
		}
		return -1;
	}


	//����º�������
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
				//���ƾ�Ԫ�ص�������
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

