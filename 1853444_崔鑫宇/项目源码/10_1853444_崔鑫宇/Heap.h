#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
	Heap(vector<int>& A, int size, long long& swap_times);//
	~Heap();

	void OrderDown(int start, int end, long long& swap_times);

	int length();
	bool isEmpty();

	void swap(int m, int n);

private:
	int* heap;//堆的指针
	int Size;//堆的大小
};

Heap::Heap(vector<int>& A, int size, long long& swap_times) {
	heap = new int[size];
	if (heap == NULL) {
		cerr << "内存分配失败" << endl;
		exit(1);
	}
	for (int i = 0; i < size; i++) {
		heap[i] = A[i];
	}
	Size = size;

	int currentPos = (Size - 2) / 2;
	while (currentPos >= 0) {
		OrderDown(currentPos, Size - 1, swap_times);
		currentPos--;
	}
}

Heap::~Heap() {
	delete []heap; 
}

void Heap::OrderDown(int start, int end, long long& swap_times) {
	int temp = heap[start];
	int i = start;
	int j = 2 * i + 1;
	while (j <= end) {
		swap_times++;

		if (heap[j] < heap[j + 1] && j < end)
			j++;
		swap_times++;
		if (temp >= heap[j])
			break;
		else {
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
}

void Heap::swap(int m, int n) {
	int temp = heap[m];
	heap[m] = heap[n];
	heap[n] = temp;
}

int Heap::length() {
	return Size;
}

bool Heap::isEmpty() {
	return (Size == 0) ? true : false;
}