#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include"LinkList.h"

using namespace std;

Candidate DistributeUnit(string str){

	stringstream input(str);
	string unit;

	string id, name, age, gender, major;

	input >> id >> name >> gender >> age >> major;

	Candidate mem(id, name, gender, age, major);

	return mem;
}

LinkList BuildList(){

	LinkList list;
	bool loop = true;
	int n;
	cout << "首先请建立考生信息系统！" << endl;

	while (loop) {
		cout << "请输入考生人数：";
		cin >> n;
		if (n > 0) {
			loop = false;
		}
		else {
			cerr << "错误:人数只能是正整数！" << endl;
			exit(-1);
		}
	}

	cout << "请依次输入考生的考号， 姓名， 性别， 年龄及报考类别！" << endl;
	string str;
	getchar();
	for (int i = 0; i < n; i++){
		getline(cin, str);
		Candidate mem = DistributeUnit(str);
		list.Insert(mem);
	}
	return list;
}

void Search(LinkList& list){

	cout << "请选择要查找的考生的考号： ";
	string id;
	cin >> id;
	if (!list.Exist(id)) {
		cout << "该考生不存在!\n";
	}
	else
	{
		Candidate* mem = list.Search(id);
		mem = mem->next;
		cout << setw(15) << "考号" << setw(15) << "姓名" << setw(15) << "性别" << setw(15) << "年龄" << setw(15) << "报考类别" << endl;
		mem->print();
	}
	cout << endl;
}

void Insert(LinkList& list){

	int pos;
	cout << "请选择要插入的考生的位置： ";
	cin >> pos;

	if (pos < 0) {
		cerr << "请输入一个正整数!" << endl;
	}
	else if (pos > list.getLength() + 1 || pos != (int)pos) {
		cerr << "无法插入此位置!" << endl;
	}
	else {
		cout << "请依次输入该考生的考号，姓名，性别，年龄以及报考类别！" << endl;
		string unit;
		getchar();
		getline(cin, unit);
		Candidate mem = DistributeUnit(unit);
		list.Insert(mem, pos);
	}
	cout << endl;
}

void Delete(LinkList& list){

	string id;
	cout << "请选择要删除的考生的考号： ";
	cin >> id;

	if (!list.Exist(id)) {
		cerr << "不存在考号为" << id << "的考生!" << endl << endl;
	}
	else {
		Candidate* mem = list.Delete(id);
		cout << "你删除的考生的考号信息是： ";
		mem->print();
		cout << endl;
	}
	cout << endl;
}

void Change(LinkList& list){

	cout << "请选择要修改的考生的考号： ";
	string id;
	cin >> id;

	if (!list.Exist(id)) {
		cerr << "该考号不存在！" << endl;
	}
	else {
		Candidate* mem = list.Search(id);
		mem = mem->next;
		cout << "你要修改的考生的考号信息是： ";
		mem->print();
		cout << "请依次输入新的考号， 姓名， 性别， 年龄及报考类别！" << endl;

		string unit;
		getchar();
		getline(cin, unit);

		Candidate New = DistributeUnit(unit);
		mem->id = New.id;
		mem->name = New.name;
		mem->gender = New.gender;
		mem->age = New.age;
		mem->major = New.major;
	}

	cout << endl;
}

int main(){

	LinkList list = BuildList();
	list.Statistic();

	int opt;
	bool n = true;
	cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）" << endl << endl;

	while (n){

		cout << "请选择您要进行的操作：";
		cin >> opt;

		switch (opt){
		case(0):
			n = false;
			break;
		case(1):
			Insert(list);
			list.Statistic();
			break;
		case(2):
			Delete(list);
			list.Statistic();
			break;
		case(3):
			Search(list);
			list.Statistic();
			break;
		case(4):
			Change(list);
			list.Statistic();
			break;
		case(5):
			list.Statistic();
			break;
		default:
			cout << "操作码错误!请重新输入!" << endl << endl;
			break;
		}
	}
}