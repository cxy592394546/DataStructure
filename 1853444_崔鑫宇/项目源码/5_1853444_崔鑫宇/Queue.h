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

	//弹出与提取元素
	T pop();
	T get();
	void push(T data);//向队列尾后添加元素
	void print();//打印队列中元素

	int size = 0;//队列当前大小
	int head=0;//头元素位置
	int max_size=0;//队列最大长度

	//判断队列是否已满或是否为空
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
		cerr << "队列为空请重新检查！";
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
		cerr << "队列中元素以全部被提取！";
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
		cerr << "队列已满，请检查输入！";
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
		cerr << "队列还没满，请检查输入！";
		exit(-1);
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << queue[i] << ' ';
		}
	}
}