#pragma once
#include<iostream>

#define DefaultSize 50

using namespace std;

template<class T>
class Queue
{
public:
	Queue();
	Queue(int n);
	~Queue();

	//��������ȡԪ��
	T pop();
	T get();
	void push(T data);//�����β�����Ԫ��
	void print();//��ӡ������Ԫ��

	int size = 0;//���е�ǰ��С
	int head=0;//ͷԪ��λ��
	int max_size=0;//������󳤶�

	//�ж϶����Ƿ��������Ƿ�Ϊ��
	bool isEmpty();
	bool isFull();
private:
	T* queue;
};

template<class T>
Queue<T>::Queue() {
	queue = new T[DefaultSize];
}

template<class T>
Queue<T>::Queue(int n) {
	queue = new T[n];
}

template<class T>
Queue<T>::~Queue() {
	delete []queue;
}

template<class T>
bool Queue<T>::isEmpty() {
	return (size == head) ? true : false;
}

template<class T>
bool Queue<T>::isFull() {
	return (size == max_size) ? true : false;
}

template<class T>
T Queue<T>::pop() {
	if (isEmpty()) {
		cerr << "����Ϊ�������¼�飡";
		exit(-1);
	}
	else {
		size--;
		return queue[size - 1];
	}
}

template<class T>
T Queue<T>::get() {
	if (isEmpty()) {
		cerr << "������Ԫ����ȫ������ȡ��";
		exit(-1);
	}
	else {
		head++;
		return queue[head - 1];
	}
}

template<class T>
void Queue<T>::push(T data) {
	if (isFull()) {
		cerr << "�����������������룡";
		exit(-1);
	}
	else {
		queue[size] = data;
		size++;
	}
}


template<class T>
void Queue<T>::print() {
	if (!isFull()) {
		cerr << "���л�û�����������룡";
		exit(-1);
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << queue[i] << ' ';
		}
	}
}