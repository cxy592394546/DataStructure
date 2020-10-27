#include<iostream>
#include<string>
#include"Queue.h"

using namespace std;

//判断数字是否是偶数
bool isOdd(int i) {
	return (i % 2 == 1) ? true : false;
}

//判断数字是否是奇数
bool isEven(int i) {
	return (i % 2 == 0) ? true : false;
}

//判断元素是否为数字
bool isNum(char ch) {
	return((ch - '0') >= 0 && (ch - '0') <= 9) ? true : false;
}

void BuildQueue() {
	cout << "输入为一行正整数，其中第一数字N（N<=1000）为顾客总数，后面跟着N位顾客的编号。" << endl;
	string str;

	getline(cin, str);

	int sum = 0;
	int n = 0;
	int num_of_odd = 0, num_of_even = 0;

	//提取出输入序列中的第一个数字（顾客个数）
	while (isNum(str[n])) {
		sum = (int)(str[n] - '0') + 10 * sum;
		n++;
	}

	//奇数队列、偶数队列以及最终用于输出的队列
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
				if (isOdd(sum)) {//将奇数置入奇数队列中并记录个数
					A.push(sum);
					num_of_odd++;//记录奇数个数
					sum = 0;
				}
				else if (isEven(sum)) {//将偶数置入偶数队列中并记录个数
					B.push(sum);
					num_of_even++;//记录偶数个数
					sum = 0;
				}
			}
		}
	}

	//重置A、B队列的元素个数
	A.max_size = num_of_odd;
	B.max_size = num_of_even;

	int Remain_odd = num_of_odd, Remain_even = num_of_even;
	
	while (Remain_odd > 1 && Remain_even > 0) {//每次奇数队列先输出两个元素偶数队列再输出一个元素
		Out.push(A.get());
		Out.push(A.get());
		Out.push(B.get());
		Remain_odd -= 2;
		Remain_even--;
	}

	//考虑奇数剩余不足2个或偶数剩余不足1个的情况
	if (Remain_even == 1 && Remain_odd == 1) {//奇偶各剩一个元素
		Out.push(A.get());//奇数偶数剩余的一个元素先后输出
		Out.push(B.get());
	}
	else if (Remain_even == 0 && Remain_odd != 0) {//偶数剩余个数为0但奇数剩余个数不等于0
		while (!A.isEmpty()) {//输出偶数队列内剩余所有元素
			Out.push(A.get());
		}
	}
	else if (Remain_even != 0 && (Remain_odd == 0 || Remain_odd == 1)) {//奇数剩余个数为0或1但偶数剩余个数不等于零
		if (Remain_odd == 1) {
			Out.push(A.get());
		}
		while (!B.isEmpty()) {//输出奇数队列内剩余所有元素
			Out.push(B.get());
		}
	}

	Out.print();
}

int main() {
	BuildQueue();

	return 0;
}