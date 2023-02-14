#pragma once
#include<iostream>
#include <vector>

using namespace std;

class heap {
	vector<int> v;
public:
	bool min_heap = true;
	heap(int start_size=10) {
		v.reserve(start_size);
		v.push_back(-1);
	}

	void insert(int next) {
		v.push_back(next);
		int index = v.size() - 1;
		int parent = index / 2;

		if(min_heap == true){
			while ((v[index] < v[parent]) and (index > 1)) {
				swap(v[index], v[parent]);
				index = parent;
				parent = index / 2;
			}
		}
		else {
			while ((v[index] > v[parent]) and (index > 1)) {
				swap(v[index], v[parent]);
				index = parent;
				parent = index / 2;
			}
		}
	}

	int get_min() {
		return v[1];
	}

	void heapify(int i) {
		int left = 2 * i;
		int right = 2 * i + 1;
		int min_indx = i;
		if (right > v.size() - 1) {
			return;
		}
		
		if(min_heap == true){
			if ((v[left] < v[i]) and (v[left] < v[right]))
				min_indx = left;
			else
				min_indx = right;
			if (min_indx != i) {
				swap(v[min_indx], v[i]);
				heapify(min_indx);
			}
		}
		else {
			if ((v[left] > v[i]) and (v[left] > v[right]))
				min_indx = left;
			else
				min_indx = right;
			if (min_indx != i) {
				swap(v[min_indx], v[i]);
				heapify(min_indx);
			}
		}
	}

	void remove_top() {
		swap(v[1], v[v.size() - 1]);
		v.pop_back();
		heapify(1);
	}

	bool isEmpty(){
		return v.size() == 1;
	}
};