#include<cmath>
#include <iostream>  
#include "MyStack.h"  
using namespace std;

//检测元素是否为数字
bool isNumber(char x) {
	if (x >= '0' && x <= '9')
		return true;
	return false;
}

//判断运算符的优先级  
int priority(char x) {
	if (x == '+' || x == '-')
		return 0;
	else if (x == '*' || x == '/' || x == '%')
		return 1;
	else if (x == '^')
		return 2;
	else if (x == '(' || x == ')')
		return -1;
	else if (x == '#' || x == '=')
		return -2;
}

//完成运算
int calculate(string s) {
	MyStack<int> number;
	MyStack<char> operate;
	char top;
	int a, b;

	operate.push('#');//将栈顶元素置为‘#’方便后续检验


	//完成运算操作
	for (unsigned int i = 0; i < s.size(); ++i) {
		if (isNumber(s[i])) {
			int Temp = 0;
			string temp;

			temp += s[i];
			while (isNumber(s[++i]))
				temp += s[i];
			for (unsigned int j = 0; j < temp.size(); ++j) {
				Temp = Temp * 10 + temp[j] - '0';
			}

			number.push(Temp);
			temp.clear();
		}

		if (!isNumber(s[i])) {//检测表达式是否是非法输入
			if (priority(s[i]) != -1 && s[i + 1] && !isNumber(s[i + 1]) && priority(s[i + 1]) != -1) {
				cerr << "表达式错误！请检查输入";
				exit(-1);
			}

			operate.get_top(top);

			if (priority(s[i]) > priority(top) || s[i] == '(') {
				operate.push(s[i]);
			}//将高优先级的运算符打入栈内  
			else {
				while (priority(s[i]) <= priority(top)) {
					if (top == '#' && s[i] == '=') {
						int sum;

						operate.pop();
						number.get_top(sum);
						cout << sum << endl;
						number.pop();
						return 0;
					}
					else if (top == '(' && s[i] == ')') {
						++i;
					}//当左右括号相遇时，跳过右括号，删除左括号  
					else {
						number.get_top(a);
						number.pop();
						number.get_top(b);
						number.pop();
					}
					if (top == '+') {
						b += a;
						number.push(b);
					}
					else if (top == '-') {
						b -= a;
						number.push(b);
					}
					else if (top == '*') {
						b *= a;
						number.push(b);
					}
					else if (top == '/') {
						b /= a;
						number.push(b);
					}
					else if (top == '%') {
						b %= a;
						number.push(b);
					}
					else if (top == '^') {
						b = pow(b, a);
						number.push(b);
					}

					operate.pop();
					//取前一个运算符，并与当前运算符进行比较  
					operate.get_top(top);
				}
				//将优先级高的运算符实现计算  
				
				operate.push(s[i]);
			}
		}  
	}
}

int main() {
	string expression;
	char ch = 'y';
	while (ch == 'y') {
		cout << "输入表达式:" << endl;
		cin >> expression;
		if (!isNumber(expression[0]) && expression[0] != '+' && expression[0] != '-' && expression[0] != '(' && expression[0] != ')') {
			cerr << "首位元素应该为数字或正负号或括号!";
			exit(-1);
		}

		calculate(expression);
		
		cout << "是否继续(y,n)?";
		cin >> ch;
	}
}