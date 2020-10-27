#pragma once
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Candidate{

	string id;//考号
	string name;//考生姓名
	string gender;//考生性别
	string age;//考生年龄
	string major;//考生类型

	Candidate* next;//下一个节点

	//初始化
	Candidate(Candidate* ptr = NULL) { next = ptr; }
	Candidate(string i, string n, string g, string a, string t, Candidate* ptr = NULL){
		id = i;
		name = n;
		gender = g;
		age = a;
		major = t;
		next = ptr;
	}

	//打印一个结点的信息
	void print(){
		cout << setw(15) << id << setw(15) << name << setw(15) << gender << setw(15) << age << setw(15) << major << endl;
	}
};

class LinkList {
public:
	LinkList();
	~LinkList() = default;
	
	LinkList& operator=(LinkList& l);
	bool isEmpty() { return length == 0; }//判断链表是否为为空
	//插入元素
	void Insert(Candidate& mem, int pos);
	void Insert(Candidate& mem) { Insert(mem, length + 1); }
	//搜索元素
	Candidate* Search(string id);

	//前往目标位置
	Candidate* LocatePos(int pos);
	Candidate* Delete(string id);//删除指定元素
	void Statistic();//统计功能
	int getLength() { return length; }//取得链表长度
	
	bool Exist(string id);//判断目标考号考生是否存在

private:
	int length;//链表长度
	Candidate* head;//头节点

};

LinkList::LinkList(){

	head = new Candidate;
	length = 0;
	head->next = NULL;
}

LinkList& LinkList::operator=(LinkList& l){

	LinkList newlist;
	int len = l.length;
	Candidate* from = l.head;
	Candidate* to = newlist.head;
	while (len > 0){

		from = from->next;
		to = to->next;
		to = from;
		--len;
	}
	to->next = NULL;
	return newlist;
}

Candidate* LinkList::LocatePos(int pos){

	//前往目标位置
	Candidate* current = head;
	while (pos > 1){
		current = current->next;
		--pos;
	}
	return current;
}

void LinkList::Insert(Candidate& mem, int pos){

	Candidate* p = new Candidate(mem.id, mem.name, mem.gender, mem.age, mem.major);
	
	//插入节点
	Candidate* pre = LocatePos(pos);
	p->next = pre->next;
	pre->next = p;
	length++;
}

Candidate* LinkList::Search(string id){

	Candidate* mem = head;
	while (mem->next->id != id){
		mem = mem->next;
	}
	if (mem->next == NULL) {
		cerr << "没找到考号为" << id << "的考生！";
	}
	else
		return mem;
}

Candidate* LinkList::Delete(string id){

	Candidate* p = Search(id);

	//删除节点
	Candidate* mem = p->next;
	p->next = mem->next;
	Candidate* store = mem;
	length--;

	return store;
}

void LinkList::Statistic(){

	cout << endl;
	if (head->next == NULL) {//如果链表为空
		cout << "(空)" << endl;
	}
	else {//否则
		cout << setw(15) << "考号" << setw(15) << "姓名" << setw(15) << "性别" << setw(15) << "年龄" << setw(15) << "报考类别" << endl;
		Candidate* mem = head;
		for (int i = 0; i < length; i++){

			mem = mem->next;
			cout << setw(15) << mem->id << setw(15) << mem->name << setw(15) << mem->gender << setw(15) << mem->age << setw(15) << mem->major << endl;
		}
	}
}

bool LinkList::Exist(string id) {

	Candidate* mem = head;
	while (mem->next != NULL) {
		mem = mem->next;
		if (mem->id == id) {
			return true;
		}
	}
	if (mem->next == NULL) {
		return false;
	}
}