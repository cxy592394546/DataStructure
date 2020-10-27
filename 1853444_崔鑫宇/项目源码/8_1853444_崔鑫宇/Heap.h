#pragma once
#include <iostream>
#include "Graph.h"
#include "MinSpanTree.h"

using namespace std;

template<typename T1, typename T2>
class Heap
{
public:
	Heap(int size = DefaultValue);
	~Heap() { delete[]heap; }
	
	bool insert(const Node<T1, T2>& x);//插入元素
	bool extract(Node<T1, T2>& item);//提取元素
	
	//调整堆中元素的位置
	void siftDown(int start, int end);
	void siftUp(int start);

	int length() { return currentSize; }//返回目前堆的长度
	bool isEmpty() { return currentSize == 0; }//判断是否为空
private:
	Node<T1, T2> *heap;
	int currentSize;//堆的目前大小
	int maxSize;//堆的容量
};

template<typename T1, typename T2>
Heap<T1, T2>::Heap(int size) {
	if (DefaultValue < size) {
		maxSize = size;
	}
	else {
		maxSize = DefaultValue;
	}
	heap = new Node<T1, T2>[maxSize];
	if (heap == NULL) {
		cerr << "内存分配失败" << endl;
		exit(1);
	}
	currentSize = 0;
}


template<typename T1, typename T2>
void Heap<T1, T2>::siftDown(int start, int end) {
	Node<T1, T2> temp = heap[start];
	int i = start;
	int j = 2 * i + 1;
	while (j <= end) {

		if (heap[j] > heap[j + 1] && j < end)
			j++;
		if (temp <= heap[j])
			break;
		else {
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
}

template<typename T1, typename T2>
void Heap<T1, T2>::siftUp(int start) {
	Node<T1, T2> temp = heap[start];
	int j = start;
	int i = (j - 1) / 2;
	while (j > 0) {
		if (heap[i] <= temp)
			break;
		else {
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;
}

template<typename T1, typename T2>
bool Heap<T1, T2>::insert(const Node<T1, T2> &item) {
	if (currentSize == maxSize) {
		cerr << "The heap is full" << endl;
		return false;
	}
	heap[currentSize] = item;
	siftUp(currentSize);
	currentSize++;
	return true;
}

template<typename T1, typename T2>
bool Heap<T1, T2>::extract(Node<T1, T2>& item) {
	if (currentSize == 0) {
		cout << "The heap is empty" << endl;
		return false;
	}
	item = heap[0];
	heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);
	return true;
}

