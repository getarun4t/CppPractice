#pragma once

#include<iostream>

using namespace std;

template <typename T>
class Vector {
	int currSize;
	int maxSize;
	T* arr;
public:
  Vector(initializer_list<T> values) : currSize(values.size()), maxSize(values.size()+1) {
		arr = new T[maxSize];
		int index = 0;
		for (auto value: values)
			arr[index++] = value;
	}

	Vector() :Vector({}) {};

	Vector(Vector& v)  {
		this->currSize = v.currSize;
		this->maxSize = v.maxSize;
		this->arr = new T[maxSize];
		int index = 0;
		for (auto value : v.arr)
			this->arr[index++] = value;
	}
  
	void push_back(T val) {
		if (currSize == maxSize) {
			T* oldArray = arr;
			arr = new T[maxSize * 2];
			for (int i = 0; i < maxSize; ++i) {
				arr[i] = oldArray[i];
			}
			maxSize *= 2;
			delete[] oldArray;
		}
		arr[currSize] = val;
		currSize++;
	}

	void print_all() {
		cout << "=======================" << endl;
		cout << "Current vector contents" << endl;
		for (int i = 0; i < currSize; ++i) {
			cout << arr[i] << endl;
		}
		cout << "Current size: " << currSize << endl;
		cout << "Current max size: " << maxSize << endl << endl;
	}

	void push_front(T val) {
		T* oldArray = arr;
		if (currSize == maxSize) {
			arr = new T[maxSize * 2];
			arr[0] = val;
			for (int i = 0; i < currSize; ++i) {
				arr[i+1] = oldArray[i];
			}
			maxSize *= 2;
		}
		else {
			arr = new T[maxSize];
			arr[0] = val;
			for (int i = 0; i < currSize; ++i) {
				arr[i + 1] = oldArray[i];
			}
		}
		delete[] oldArray;
		++currSize;
	}

	void delete_back() {
		T* oldArray = arr;
		arr = new T[maxSize];
		--currSize;
		for (int i = 0; i < currSize; ++i) {
			arr[i] = oldArray[i];
		}
		delete[] oldArray;
	}

	T operator[](int indx) {
		if (indx > currSize) {
			cout << "Index out of bound" << endl;
			return arr[0];
		}
		return arr[indx];
	}
};
