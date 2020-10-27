#pragma once
#include<vector>
#include<list>
#include<queue>
#include<deque>

using namespace std;

template<class T, class container = vector<T>>
class MyStack
{
public:
	int size();//ջ�Ĵ�С

	MyStack() = default;
	~MyStack() = default;

	T top();//����ջ��Ԫ��

	void push(T);//��ջβ����Ԫ��
	void pop();//����ջβԪ��

private:
	container StackBuilt;//ջ�Ĵ洢����
};

//����ջβԪ��
template<class T, class container>
void MyStack<T, container>::pop() {
	StackBuilt.pop_back();
}

//��ջ������Ԫ��
template<class T, class container>
void MyStack<T, container>::push(T data) {
	StackBuilt.push_back(data);
}

//����ջ�Ĵ�С
template<class T, class container>
int MyStack<T, container>::size() {
	return StackBuilt.size();
}

//����ջ�ĶѶ�Ԫ��
template<class T, class container>
T MyStack<T, container>::top() {
	return StackBuilt[StackBuilt.size() - 1];
}