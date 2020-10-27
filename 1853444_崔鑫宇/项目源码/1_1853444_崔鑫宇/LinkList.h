#pragma once
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Candidate{

	string id;//����
	string name;//��������
	string gender;//�����Ա�
	string age;//��������
	string major;//��������

	Candidate* next;//��һ���ڵ�

	//��ʼ��
	Candidate(Candidate* ptr = NULL) { next = ptr; }
	Candidate(string i, string n, string g, string a, string t, Candidate* ptr = NULL){
		id = i;
		name = n;
		gender = g;
		age = a;
		major = t;
		next = ptr;
	}

	//��ӡһ��������Ϣ
	void print(){
		cout << setw(15) << id << setw(15) << name << setw(15) << gender << setw(15) << age << setw(15) << major << endl;
	}
};

class LinkList {
public:
	LinkList();
	~LinkList() = default;
	
	LinkList& operator=(LinkList& l);
	bool isEmpty() { return length == 0; }//�ж������Ƿ�ΪΪ��
	//����Ԫ��
	void Insert(Candidate& mem, int pos);
	void Insert(Candidate& mem) { Insert(mem, length + 1); }
	//����Ԫ��
	Candidate* Search(string id);

	//ǰ��Ŀ��λ��
	Candidate* LocatePos(int pos);
	Candidate* Delete(string id);//ɾ��ָ��Ԫ��
	void Statistic();//ͳ�ƹ���
	int getLength() { return length; }//ȡ��������
	
	bool Exist(string id);//�ж�Ŀ�꿼�ſ����Ƿ����

private:
	int length;//������
	Candidate* head;//ͷ�ڵ�

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

	//ǰ��Ŀ��λ��
	Candidate* current = head;
	while (pos > 1){
		current = current->next;
		--pos;
	}
	return current;
}

void LinkList::Insert(Candidate& mem, int pos){

	Candidate* p = new Candidate(mem.id, mem.name, mem.gender, mem.age, mem.major);
	
	//����ڵ�
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
		cerr << "û�ҵ�����Ϊ" << id << "�Ŀ�����";
	}
	else
		return mem;
}

Candidate* LinkList::Delete(string id){

	Candidate* p = Search(id);

	//ɾ���ڵ�
	Candidate* mem = p->next;
	p->next = mem->next;
	Candidate* store = mem;
	length--;

	return store;
}

void LinkList::Statistic(){

	cout << endl;
	if (head->next == NULL) {//�������Ϊ��
		cout << "(��)" << endl;
	}
	else {//����
		cout << setw(15) << "����" << setw(15) << "����" << setw(15) << "�Ա�" << setw(15) << "����" << setw(15) << "�������" << endl;
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