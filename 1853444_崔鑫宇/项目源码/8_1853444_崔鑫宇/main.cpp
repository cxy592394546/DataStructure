#include "Graph.h"
#include "Heap.h"
#include "MinSpanTree.h"
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

//初始化屏幕(打印菜单)
void printScreen() {
	cout << "**" << setw(15) << ' ' << "电网造价模拟系统" << setw(17) << ' ' << "**" << endl;
	cout << "====================================================" << endl;
	cout << "**" << setw(15) << ' ' << "A --- 创建电网顶点" << setw(15) << ' ' << "**" << endl;
	cout << "**" << setw(15) << ' ' << "B --- 添加电网的边" << setw(15) << ' ' << "**" << endl;
	cout << "**" << setw(15) << ' ' << "C --- 构造最小生成树" << setw(13) << ' ' << "**" << endl;
	cout << "**" << setw(15) << ' ' << "D --- 显示最小生成树" << setw(13) << ' ' << "**" << endl;
	cout << "**" << setw(15) << ' ' << "E --- 退出程序" << setw(19) << ' ' << "**" << endl;
	cout << "====================================================" << endl;
}

//添加点
void addVertexes(Graph<char, int>& G, int& num) {
	cout << "请输入顶点的个数：";
	int n = 0;
	while (n <= 0) {
		cin >> n;
		if (n <= 0) {
			cout << "点的个数应大于0！请重新输入:";
		}
	}
	num = n;
	cout << "请输入各个顶点的名称：";
	for(int i=0;i<n;i++) {
		char name;
		cin >> name;
		G.insertVertice(name);
	}
}

//添加边
void addEdges(Graph<char, int>& G) {
	bool i = 1;

	while (i) {
		cout << "请输入两个顶点及边：";
		char v1,v2;
		int weight;
		cin >> v1 >> v2 >> weight;
		if (v1 == '?' || v2 == '?') {
			i = 0;
			break;
		}

		int v1_pos = G.getVerticePos(v1);
		int v2_pos = G.getVerticePos(v2);

		if (!G.insertEdge(v1_pos, v2_pos, weight)) {
			cerr << "顶点创建失败，请检查后重新输入!" << endl;
		}
	}
}

//用Prim算法构造最小生成树
template<typename T1, typename T2>
void Prim(const T1 x, Graph<T1, T2>& G, MinSpanTree<T1, T2>& MinSizeTree) {

	Node<T1, T2> tn;
	int a, b, count;
	int n = G.getNumVertices();
	int m = G.getNumEdges();
	a = G.getVerticePos(x);
	Heap<T1, T2> H(m);
	 
	bool *v = new bool[n];
	for (int i = 0; i < n; i++) {
		v[i] = false;
	}

	v[a] = true;
	count = 1;
	while (count < n) {
		b = G.getFirstNeighbor(a);
 
		while (b != -1) {
			if (v[b] == false) {
				tn.head = b;
				tn.tail = a;
				tn.key = G.getWeight(a, b);
				H.insert(tn);
			}
			b = G.getNextNeighbor(a, b);
		}
		while (!(H.isEmpty()) && count < n) {
 
			H.extract(tn);
 
			if (v[tn.head] == false) {
				MinSizeTree.InsertNode(tn);
				a = tn.head;
				v[a] = true;
				count++;
				break;
			}
		}
	}
}

int main() {
	printScreen();

	Graph<char, int> G;
	MinSpanTree<char, int> MSTree;
	int numVertices = 0;
	char opt;
	bool i = 1;
	int isBuilt = 0;

	//各种功能的实现
	while (i == 1) {
		cout << endl << "请选择操作：";
		cin >> opt;

		switch (opt) {
		case 'A':
			if (isBuilt == 1) {
				cerr << "不要重复创建电网!" << endl;
			}
			else {
				addVertexes(G, numVertices);
				isBuilt = 1;
			}
			break;
		case 'B':
			if (isBuilt == 0) {
				cerr << "请先创建电网!" << endl;
			}
			else {
				addEdges(G);
			}
			break;
		case 'C':
			if (isBuilt == 0) {
				cerr << "请先创建电网!" << endl;
				break;
			}
			cout << "请输入起始顶点：";
			char begin;
			cin >> begin;
			Prim(begin, G, MSTree);
			cout << "生成Prim最小生成树!" << endl;
			break;
		case 'D': {
			if (isBuilt == 0) {
				cout << "请先创建电网!" << endl;
				break;
			}
			else {
				cout << "最小生成树的顶点及边分别为：" << endl;
				for (int i = 0; i < numVertices - 1; i++) {
					char head = G.getValue(MSTree.value[i].tail);
					char tail = G.getValue(MSTree.value[i].head);
					cout << head << "-<" << MSTree.value[i].key << ">->" << tail;
					if (i != numVertices - 2) {
						cout << "\t";
					}
				}
				cout << endl;
				break;
			}
		}
		case 'E':
			i = 0;
			break;
		default:
			cout << "选项不存在!" << endl;
			break;
		}
	}
}
