#pragma once
#include "Graph.h"

using namespace std;

//节点类
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
	Node<T1, T2>* value;//容器

	MinSpanTree(int sz = DefaultValue - 1) : maxSize(sz), n(0) {
		value = new Node<T1, T2>[sz];
	}

	//插入数据
	bool InsertNode(Node<T1, T2>& node) {
		if (n == maxSize) {
			cerr << "达到可容纳的最大值" << endl;
			return false;
		}
		else {
			value[n] = node;
			n++;
			return true;
		}
	}
private:
	//最小生成树的最大容量
	int maxSize, n;
};
 
