#include<iostream>
#include "Heap.h"

using namespace std;

//检查输入块数是否符合要求
void checkInput(int num) {
	if (num <= 0) {
		cerr << "输入数据应大于0！请重新输入:";
	}
	else if (num > 10000) {
		cerr << "输入数据应不大于10000！请重新输入:";
	}
}

int main(){
	int num;
	long long int minCost = 0;//最小花费

	cout << "请输入一个不大于10000的正整数:";
	cin >> num;//块数

	//检查输入
	while (num <= 0 || num > 10000) {
		checkInput(num);
		cin >> num;
	}

	Heap<int> heap(num);

	//输入每块的长度
	for (int i = 0; i < num;i++) {
		int piece;
		cin >> piece;
	
		heap.insert(piece);
	}

	while (heap.length() > 2) {
		int _piece;
		int a = heap.get();
		int b = heap.get();

		_piece = a + b;
		heap.insert(_piece);
		minCost += _piece;
	}

	if (num == 1) {//只有一片的情况
		int piece_1 = heap.get();

		minCost += piece_1;
		cout << minCost;
	}
	else if (num >= 2) {//块数大于等于2的情况
		int piece_2 = heap.get();
		int piece_1 = heap.get();

		minCost += piece_1;
		minCost += piece_2;
		cout << minCost;
	}
}