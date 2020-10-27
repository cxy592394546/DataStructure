#pragma once
#include <iostream>  
using namespace std;

#define MAXLEN  100

template <class T>
class MyStack {
public:
	MyStack();
	~MyStack() = default;

	bool isEmpty();//�ж�ջ�Ƿ�Ϊ��  
	bool isFull();//�ж�ջ�Ƿ�Ϊ��  

	bool get_top(T& x);//��ȡջ��Ԫ��  
	bool push(T x);//��Ԫ������ջ  
	bool pop();//ɾ��ջ��Ԫ��

private:
	int count;//ͳ��ջ������
	T data[MAXLEN];//�洢����
};

template <class T>
MyStack<T>::MyStack() {
	count = 0;
}

template <class T>
bool MyStack<T>::isEmpty() {
	if (count == 0)
		return true;
	return false;
}

template <class T>
bool MyStack<T>::isFull() {
	if (count == MAXLEN)
		return true;
	return false;
}

template <class T>
bool MyStack<T>::get_top(T& x) {
	if (!isEmpty()) {
		x = data[count - 1];
		return true;
	}
	return false;
}

template <class T>
bool MyStack<T>::push(T x) {
	if (!isFull()) {
		data[count++] = x;
		return true;
	}
	return false;
}

template <class T>
bool MyStack<T>::pop() {
	if (!isEmpty()) {
		--count;
		return true;
	}
	return false;
}