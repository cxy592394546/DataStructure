#include<iostream>
#include<string>
#include"Queue.h"

using namespace std;

//�ж������Ƿ���ż��
bool isOdd(int i) {
	return (i % 2 == 1) ? true : false;
}

//�ж������Ƿ�������
bool isEven(int i) {
	return (i % 2 == 0) ? true : false;
}

//�ж�Ԫ���Ƿ�Ϊ����
bool isNum(char ch) {
	return((ch - '0') >= 0 && (ch - '0') <= 9) ? true : false;
}

void BuildQueue() {
	cout << "����Ϊһ�������������е�һ����N��N<=1000��Ϊ�˿��������������Nλ�˿͵ı�š�" << endl;
	string str;

	getline(cin, str);

	int sum = 0;
	int n = 0;
	int num_of_odd = 0, num_of_even = 0;

	//��ȡ�����������еĵ�һ�����֣��˿͸�����
	while (isNum(str[n])) {
		sum = (int)(str[n] - '0') + 10 * sum;
		n++;
	}

	//�������С�ż�������Լ�������������Ķ���
	Queue<int> A, B, Out;

	A.max_size = sum;
	B.max_size = sum;
	Out.max_size = sum;

	sum = 0;
	for (unsigned int i = n + 1; i < str.size(); i++) {
		if (isNum(str[i])) {
			sum = (int)(str[i] - '0') + 10 * sum;
			if (str[i + 1] && isNum(str[i + 1])) {
				continue;
			}
			else {
				if (isOdd(sum)) {//�������������������в���¼����
					A.push(sum);
					num_of_odd++;//��¼��������
					sum = 0;
				}
				else if (isEven(sum)) {//��ż������ż�������в���¼����
					B.push(sum);
					num_of_even++;//��¼ż������
					sum = 0;
				}
			}
		}
	}

	//����A��B���е�Ԫ�ظ���
	A.max_size = num_of_odd;
	B.max_size = num_of_even;

	int Remain_odd = num_of_odd, Remain_even = num_of_even;
	
	while (Remain_odd > 1 && Remain_even > 0) {//ÿ�������������������Ԫ��ż�����������һ��Ԫ��
		Out.push(A.get());
		Out.push(A.get());
		Out.push(B.get());
		Remain_odd -= 2;
		Remain_even--;
	}

	//��������ʣ�಻��2����ż��ʣ�಻��1�������
	if (Remain_even == 1 && Remain_odd == 1) {//��ż��ʣһ��Ԫ��
		Out.push(A.get());//����ż��ʣ���һ��Ԫ���Ⱥ����
		Out.push(B.get());
	}
	else if (Remain_even == 0 && Remain_odd != 0) {//ż��ʣ�����Ϊ0������ʣ�����������0
		while (!A.isEmpty()) {//���ż��������ʣ������Ԫ��
			Out.push(A.get());
		}
	}
	else if (Remain_even != 0 && (Remain_odd == 0 || Remain_odd == 1)) {//����ʣ�����Ϊ0��1��ż��ʣ�������������
		if (Remain_odd == 1) {
			Out.push(A.get());
		}
		while (!B.isEmpty()) {//�������������ʣ������Ԫ��
			Out.push(B.get());
		}
	}

	Out.print();
}

int main() {
	BuildQueue();

	return 0;
}