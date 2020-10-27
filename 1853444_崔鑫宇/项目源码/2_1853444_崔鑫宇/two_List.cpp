#include <iostream>
#include <sstream>
#include <string>
#include "LinkList.h"

using namespace std;
//判断是否为数字
bool isNumber(char ch) {
	return (ch >= '0' && ch <= '9') ? true : false;
}

//处理链表序列
void ManageList(LinkList<int> list, string str){

	stringstream ss(str);
	string s;

	while (ss >> s) {//当提取到-1时结束提取工作
		if (stoi(s) == -1)
			break;
		else//否则正常进行提取工作
			list.append(stoi(s));
	}
}

//找到两个链表中的相等的值
bool FindEqualValue(LinkList<int> l1, LinkList<int> l2){

	int num = 0;
	
	LNode<int>* p1 = l1.FindHead();
	LNode<int>* p2 = l2.FindHead();
	LNode<int>* pre = p1;
	
	p1 = p1->next;
	p2 = p2->next;
	
	if (p1 == NULL || p2 == NULL) {
		return false;
	}
	else {
		while (p1 != NULL && p2 != NULL) {
			if (p1->data > p2->data) {
				//如果p2当前元素小于p1当前元素则让p2指向下一个元素
				p2 = p2->next;
			}
			else if (p1->data < p2->data) {
				//如果p1当前元素小于p2当前元素则让p1指向下一个元素
				pre->next = p1->next;
				p1 = p1->next;
			}
			else{
				p1 = p1->next;
				pre = pre->next;
				p2 = p2->next;
				num++;
			}
		}

		if (p2 == NULL) {
			pre->next = NULL;
		}
		if (num == 0) {
			return false;
		}
		else {
			return true;
		}
	}
}

int main() {

	LinkList<int> list1, list2;
	string s1, s2;

	cout << "请输入第一串序列（以-1结尾！）:";
	getline(cin, s1);//输入第一个链表

	cout << "请输入第二串序列（以-1结尾！）:";
	getline(cin, s2);//输入第二个链表

	ManageList(list1, s1);//处理第一个链表
	ManageList(list2, s2);//处理第二个链表


	//确认两个链表为非降序链表
	if (!(list1.isOrdered() && list2.isOrdered())) {
		cerr << "输入的序列不符合要求,请检查输入！";
		exit(-1);
	}
	//确认两个链表是否为正整数序列（除标志位-1）
	else if ((!isNumber(s1[0])) || (!isNumber(s2[0]))) {
		cerr << "请输入正整数序列(除标志位-1)!";
		exit(-1);
	}
	else {
		if (FindEqualValue(list1, list2)) {
			list1.print();
		}
		else {
			cout << "NULL";
		}
	}
}