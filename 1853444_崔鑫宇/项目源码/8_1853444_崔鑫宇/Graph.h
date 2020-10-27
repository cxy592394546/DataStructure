#pragma once

#include <iostream>
using namespace std;

#define DefaultValue 50

//边结构体
template<typename T1, typename T2>
struct Edge {

	T1 dest;

	T2 cost;

	Edge* link;
	Edge() {
		dest = -1;
		cost = 0;
		link = NULL;
	}
	Edge(T1 num, T2 weight) {
		dest = num;
		cost = weight;
		link = NULL;
	}
	bool operator!= (Edge& R) const {
		return (dest != R.dest) ? true : false;
	}
};

//点结构体
template<typename T1, typename T2>
struct Vertices {
	T1 data;
	Edge<T1, T2>* x;
};

template<typename T1, typename T2>
class Graph
{
public:
	Graph();
	~Graph() = default;

	int getNumVertices() { return numVertices; }//取得点
	int getNumEdges() { return numEdges; }//取得边

	//取值
	T1 getValue(int i) {
		return (i >= 0 && i < numVertices) ? NodeTable[i].data : '0';
	}
	//取长度
	T2 getWeight(int v1, int v2);
	
	//插入点
	bool insertVertice(const T1& vertices);
	//插入边
	bool insertEdge(int v1, int v2, T2 cost);

	//取得第一个相邻单位
	int getFirstNeighbor(int v);
	//取得下一个相邻单位
	int getNextNeighbor(int v, int w);
	//取得点的位置
	int getVerticePos(const T1 vertices) {
		for (int i = 0; i < numVertices; i++) {
			if (NodeTable[i].data == vertices) {
				return i;
			}
		}
		return -1;
	}

private:
	Vertices<T1, T2> *NodeTable;
	int numVertices;//点 
	int maxVertices;//最大点数
	int numEdges;//边
};

template<typename T1, typename T2>
Graph<T1, T2>::Graph() {
	maxVertices = DefaultValue;
	numEdges = 0;
	numVertices = 0;
	NodeTable = new Vertices<T1, T2>[maxVertices];
	if (NodeTable == NULL) {
		cerr << "内存分配错误" << endl;
		exit(1);
	}
	for (int i = 0; i < maxVertices; i++) {
		NodeTable[i].x = NULL;
	}
}

template<typename T1, typename T2>
int Graph<T1, T2>::getFirstNeighbor(int v) {
	if (v != -1) {
		Edge<T1, T2>* p = NodeTable[v].x;
		if (p != NULL)
			return p->dest;
	}
	return -1;
}

template<typename T1, typename T2>
int Graph<T1, T2>::getNextNeighbor(int v, int w) {
	if (v != -1) {
		Edge<T1, T2>* p = NodeTable[v].x;
		while (p != NULL && p->dest != w) {
			p = p->link;
		}
		if (p != NULL && p->link != NULL) {
			return p->link->dest;
		}
	}
	return -1;
}

template<typename T1, typename T2>
T2 Graph<T1, T2>::getWeight(int v1, int v2) {
	if (v1 != -1 && v2 != -1) {
		Edge<T1, T2>* p = NodeTable[v1].x;
		while (p != NULL && p->dest != v2) {
			p = p->link;
		}
		if (p != NULL) {
			return p->cost;
		}
	}
	return 0;
}

template<typename T1, typename T2>
bool Graph<T1, T2>::insertVertice(const T1& vertex) {
	if (numVertices == maxVertices) {
		return false;
	}
	else {
		NodeTable[numVertices].data = vertex;
		numVertices++;
		return true;
	}
}

template<typename T1, typename T2>
bool Graph<T1, T2>::insertEdge(int v1, int v2, T2 weight) {
	if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
		Edge<T1, T2>* q;
		Edge<T1, T2>* p = NodeTable[v1].x;

		while (p != NULL && p->dest != v2) {
			p = p->link;
		}
		if (p != NULL) {
			return 0;
		}
		p = new Edge<T1, T2>;
		q = new Edge<T1, T2>;

		p->dest = v2;
		p->cost = weight;
		p->link = NodeTable[v1].x;
		NodeTable[v1].x = p;

		q->dest = v1;
		q->cost = weight;
		q->link = NodeTable[v2].x;
		NodeTable[v2].x = q;
		numEdges++;
		return true;
	}
	else {
		return false;
	}
}