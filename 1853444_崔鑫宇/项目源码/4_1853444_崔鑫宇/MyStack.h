#pragma once
#include <iostream>  
using namespace std;

#define MAXLEN  100

template <class T>
class MyStack {
public:
	MyStack();
	~MyStack() = default;

	bool isEmpty();//判断栈是否为空  
	bool isFull();//判断栈是否为满  

	bool get_top(T& x);//提取栈顶元素  
	bool push(T x);//将元素推入栈  
	bool pop();//删除栈顶元素

private:
	int count;//统计栈中数字
	T data[MAXLEN];//存储数据
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