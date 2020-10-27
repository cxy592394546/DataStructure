#pragma once
#include<iostream>

using namespace std;

template<class T>
class Heap{

public:
	Heap(int size);//�ѵĹ��캯��
	~Heap();//�ѵ���������

	//�������
	void insert(int item);
	//��ȡ����Ԫ��
	T get();

	//��������Ԫ�ص�λ��
	void OrderDown(int begin, int end);
	void OrderUp(int begin);
	
	//�õ��ѵĳ���
	int length() { return Size; }
	//�ж϶����Ƿ�Ϊ��
	bool isEmpty();

private:
	T* heap;
	int Size;//�ѵĴ�С
};

template<class T>
Heap<T>::Heap(int size) {
	heap = new int[size];
	if (heap == NULL) {
		cerr << "�ڴ����ʧ��" << endl;
		exit(-1);
	}
	Size = 0;
}

template<class T>
Heap<T>::~Heap() {
	delete []heap;
}

template<class T>
T Heap<T>::get() {
	if (isEmpty()) {
		cout << "��Ϊ�գ������¼�飡" << endl;
	}
	int top = heap[0];
	heap[0] = heap[Size - 1];
	Size--;
	OrderDown(0, Size - 1);
	return top;
}

template<class T>
void Heap<T>::insert(int item) {
	heap[Size] = item;
	OrderUp(Size);
	Size++;
}

template<class T>
void Heap<T>::OrderDown(int begin, int end) {
	int temp = heap[begin];
	int i = begin;
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

template<class T>
void Heap<T>::OrderUp(int begin) {
	int temp = heap[begin];
	int j = begin;
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

template<class T>
bool Heap<T>::isEmpty() {
	return (Size == 0) ? true : false;
}

