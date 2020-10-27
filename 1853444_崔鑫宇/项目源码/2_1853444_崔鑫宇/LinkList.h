#pragma once
#include <iostream>

using namespace std;

template<typename T>
struct LNode {

	T data;//�ڵ�����������
	LNode* next=NULL;//������һ���ڵ�
};

template<typename T>
class LinkList{
public:
	LinkList();
	~LinkList() = default;

	LinkList<T>& operator=(const LinkList<T>& l);
	void append(T d);//�������
	void print();//��ӡ����

	bool isEmpty() { return head->next == NULL; }//�ж������Ƿ�Ϊ��
	bool isOrdered();//�ж����������������Ƿ�Ϊ�ǽ�������
	LNode<T>* FindHead() const { return head; }//������ָ�����ص�ͷ�ڵ�

	int size();//���������С

	T top() { return head->data; }//����ͷԪ��
private:
	LNode<T>* head;//ͷ�ڵ�
	int length = 0;//����
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