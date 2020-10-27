#pragma once
#include "Graph.h"

using namespace std;

//�ڵ���
template<typename T1, typename T2>
struct Node {
 
	int tail, head;
	T2 key;
 
	Node(): tail(-1), head(-1), key(0) {}
 
	bool operator<= (Node<T1, T2>& R) { return key <= R.key; }
	bool operator> (Node<T1, T2>& R) { return key > R.key; }
};

template<typename T1, typename T2>
class MinSpanTree
{
public:
	Node<T1, T2>* value;//����

	MinSpanTree(int sz = DefaultValue - 1) : maxSize(sz), n(0) {
		value = new Node<T1, T2>[sz];
	}

	//��������
	bool InsertNode(Node<T1, T2>& node) {
		if (n == maxSize) {
			cerr << "�ﵽ�����ɵ����ֵ" << endl;
			return false;
		}
		else {
			value[n] = node;
			n++;
			return true;
		}
	}
private:
	//��С���������������
	int maxSize, n;
};
 
