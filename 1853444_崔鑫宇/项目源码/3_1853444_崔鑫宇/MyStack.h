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
	int size();//栈的大小

	MyStack() = default;
	~MyStack() = default;

	T top();//返回栈顶元素

	void push(T);//向栈尾打入元素
	void pop();//弹出栈尾元素

private:
	container StackBuilt;//栈的存储容器
};

//弹出栈尾元素
template<class T, class container>
void MyStack<T, container>::pop() {
	StackBuilt.pop_back();
}

//向栈中推入元素
template<class T, class container>
void MyStack<T, container>::push(T data) {
	StackBuilt.push_back(data);
}

//返回栈的大小
template<class T, class container>
int MyStack<T, container>::size() {
	return StackBuilt.size();
}

//返回栈的堆顶元素
template<class T, class container>
T MyStack<T, container>::top() {
	return StackBuilt[StackBuilt.size() - 1];
}