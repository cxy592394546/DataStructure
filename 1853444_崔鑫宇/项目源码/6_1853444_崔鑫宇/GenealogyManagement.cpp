#include "GenealogyManagement.h"

using namespace std;

GenealogyManagement::GenealogyManagement() {
	;
}

GenealogyManagement::~GenealogyManagement() {
	;
}

void GenealogyManagement::addSonNode(Members* parent,string addName) {
	if (parent->FirstChildNode == NULL) {//����һ���ӽڵ�Ϊ�����һ�½���������ӽ����
		Members* childNode = new Members;
		parent->FirstChildNode = childNode;
		childNode->name = addName;//�����������ӽڵ���ֵܽڵ������һ���½��
	}
	else
		addBrotherNode(parent->FirstChildNode, addName);
}
//��Ա����������ӽڵ�

void GenealogyManagement::addBrotherNode(Members* brother, string addName) {
	if (brother->NextBrotherNode == NULL) {//Ѱ�ҵ�һ���յ��ֵܽڵ�
		Members* BrotherNode = new Members;
		brother->NextBrotherNode = BrotherNode;
		BrotherNode->name = addName;
	}
	else
		addBrotherNode(brother->NextBrotherNode, addName);
}
//��Ա����������ֵܽڵ�

Members* GenealogyManagement::findParentNode(Members* parent, string NameToFind) {
	if (parent != NULL) {
		if (parent->name == NameToFind) {//���������ͬ���ظýڵ�
			return parent;
		}
		else {
			return findParentNode(parent->FirstChildNode, NameToFind);
			return findParentNode(parent->NextBrotherNode, NameToFind);
		}
	}
}
//��Ա������Ѱ��Ŀ�Ľڵ�

void GenealogyManagement::buildGenealogy(Members* root) {
	string name;
	parent = new Members;
	parent = findParentNode(root, name);//�����׽ڵ�
	parent->FirstChildNode = NULL;
	parent->NextBrotherNode = NULL;

	int num;
	cout << "������Ҫ������ͥ���˵�������";
	cin >> name;
	cout << "������" << name << "�Ķ�Ů������";
	cin >> num;
	cout << "����������" << name << "�Ķ�Ů��������";
	string* childName = new string[num];

	for (int i = 0; i < num; i++) {
		cin >> childName[i];
		addSonNode(root, childName[i]);
	}
	cout << name << "�ĵ�һ�������ǣ�";
	for (int i = 0; i < num; i++) {
		cout << childName[i] << ' ';
	}

	cout << endl;
	cout << endl;
}
//��Ա��������������ϵͳ

void GenealogyManagement::addMember(Members* root) {
	cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�������";
	string ParentName, ChildName;
	cin >> ParentName;

	cout << "������" << ParentName << "����ӵĶ��ӣ���Ů������������";
	cin >> ChildName;

	parent = new Members;
	parent = findParentNode(root, ParentName);
	addSonNode(parent, ChildName);

	Members* NewChild = new Members;
	cout << ParentName << "��һ�������ǣ�" << ChildName;

	cout << endl;
	cout << endl;
}
//��Ա��������ӳ�Ա

void GenealogyManagement::deleteBranch(Members* root) {
	cout << "������Ҫ��ɢ�ļ�ͥ���˵�������";
	string ParentName;
	cin >> ParentName;
	cout << "Ҫ��ɢ��ͥ�����ǣ�" << ParentName << endl;

	parent = new Members;
	parent = findParentNode(root, ParentName);//�ҵ�Ҫɾ���ĳ�Ա�ڵ�

	parent = NULL;
	
	cout << endl;
	cout << endl;
}
//��Ա������ɾ��ĳһ��֧

void GenealogyManagement::changeName(Members* root) {
	cout << "������Ҫ�����������˵�Ŀǰ������";
	string MemberName;
	cin >> MemberName;

	parent = new Members;
	parent = findParentNode(root, MemberName);//�ҵ�Ҫ�޸������ĳ�Ա�ڵ�

	cout << "��������ĺ��������";
	string MemberName_New;
	cin >> MemberName_New;

	cout << MemberName << "�Ѹ���Ϊ" << MemberName_New<<endl;
	parent->name = MemberName_New;

	cout << endl;
}
//��Ա�������޸�ĳһ��Ա����
