#pragma once
#include <iostream>

using namespace std;

template<typename T>
struct LNode {

	T data;//节点内所存数据
	LNode* next=NULL;//定义下一个节点
};

template<typename T>
class LinkList{
public:
	LinkList();
	~LinkList() = default;

	LinkList<T>& operator=(const LinkList<T>& l);
	void append(T d);//添加数据
	void print();//打印链表

	bool isEmpty() { return head->next == NULL; }//判断链表是否为空
	bool isOrdered();//判断链表内所存数据是否为非降序序列
	LNode<T>* FindHead() const { return head; }//将链表指针条回到头节点

	int size();//返回链表大小

	T top() { return head->data; }//返回头元素
private:
	LNode<T>* head;//头节点
	int length = 0;//长度
};

template<typename T>
LinkList<T>::LinkList() {
	head = new LNode<T>;
}

template<typename T>
LinkList<T>& LinkList<T>::operator=(const LinkList<T>& l){

	LinkList<T> list1 = new LinkList<T>;
	LNode<T>* N1 = l.head;
	LNode<T>* N2 = list1.head;
	while (N1->next != NULL) {
		N2->data;
	}
}

template<typename T>
void LinkList<T>::append(T d) {
	
	LNode<T>* tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	LNode<T>* newNode = new LNode<T>;
	newNode->data = d;
	tail->next = newNode;
	newNode->next = NULL;
	length++;
}

template<typename T>
void LinkList<T>::print() {

	LNode<T>* current = head->next;
	while (current != NULL) {
		cout << current->data << ' ';
		current = current->next;
	}
}

template<typename T>
bool LinkList<T>::isOrdered() {
	if (size() <= 1) { return true; }
	else{
		LNode<T>* pre = head->next;
		LNode<T>* current = pre->next;
		while (current != NULL) {
			if (current->data < pre->data) {
				return false;
			}
			else {
				pre = current;
				current = current->next;
			}
		}
		return true;
	}
}

template<typename T>
int LinkList<T>::size(){
	int len = 0;
	LNode<T>* p = head;

	while (p->next != NULL){
		p = p->next;
		++len;
	}
	return len;
}