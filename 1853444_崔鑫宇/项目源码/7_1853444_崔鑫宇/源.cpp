#include<iostream>
#include "Heap.h"

using namespace std;

//�����������Ƿ����Ҫ��
void checkInput(int num) {
	if (num <= 0) {
		cerr << "��������Ӧ����0������������:";
	}
	else if (num > 10000) {
		cerr << "��������Ӧ������10000������������:";
	}
}

int main(){
	int num;
	long long int minCost = 0;//��С����

	cout << "������һ��������10000��������:";
	cin >> num;//����

	//�������
	while (num <= 0 || num > 10000) {
		checkInput(num);
		cin >> num;
	}

	Heap<int> heap(num);

	//����ÿ��ĳ���
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

	if (num == 1) {//ֻ��һƬ�����
		int piece_1 = heap.get();

		minCost += piece_1;
		cout << minCost;
	}
	else if (num >= 2) {//�������ڵ���2�����
		int piece_2 = heap.get();
		int piece_1 = heap.get();

		minCost += piece_1;
		minCost += piece_2;
		cout << minCost;
	}
}