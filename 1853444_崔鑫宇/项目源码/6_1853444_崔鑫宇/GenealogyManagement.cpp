#include "GenealogyManagement.h"

using namespace std;

GenealogyManagement::GenealogyManagement() {
	;
}

GenealogyManagement::~GenealogyManagement() {
	;
}

void GenealogyManagement::addSonNode(Members* parent,string addName) {
	if (parent->FirstChildNode == NULL) {//若上一辈子节点为空添加一新结点在他的子结点上
		Members* childNode = new Members;
		parent->FirstChildNode = childNode;
		childNode->name = addName;//否则在他的子节点的兄弟节点上添加一个新结点
	}
	else
		addBrotherNode(parent->FirstChildNode, addName);
}
//成员函数：添加子节点

void GenealogyManagement::addBrotherNode(Members* brother, string addName) {
	if (brother->NextBrotherNode == NULL) {//寻找第一个空的兄弟节点
		Members* BrotherNode = new Members;
		brother->NextBrotherNode = BrotherNode;
		BrotherNode->name = addName;
	}
	else
		addBrotherNode(brother->NextBrotherNode, addName);
}
//成员函数：添加兄弟节点

Members* GenealogyManagement::findParentNode(Members* parent, string NameToFind) {
	if (parent != NULL) {
		if (parent->name == NameToFind) {//如果姓名相同返回该节点
			return parent;
		}
		else {
			return findParentNode(parent->FirstChildNode, NameToFind);
			return findParentNode(parent->NextBrotherNode, NameToFind);
		}
	}
}
//成员函数：寻找目的节点

void GenealogyManagement::buildGenealogy(Members* root) {
	string name;
	parent = new Members;
	parent = findParentNode(root, name);//创建首节点
	parent->FirstChildNode = NULL;
	parent->NextBrotherNode = NULL;

	int num;
	cout << "请输入要建立家庭的人的姓名：";
	cin >> name;
	cout << "请输入" << name << "的儿女人数：";
	cin >> num;
	cout << "请依次输入" << name << "的儿女的姓名：";
	string* childName = new string[num];

	for (int i = 0; i < num; i++) {
		cin >> childName[i];
		addSonNode(root, childName[i]);
	}
	cout << name << "的第一代子孙是：";
	for (int i = 0; i < num; i++) {
		cout << childName[i] << ' ';
	}

	cout << endl;
	cout << endl;
}
//成员函数：建立家谱系统

void GenealogyManagement::addMember(Members* root) {
	cout << "请输入要添加儿子（或女儿）的人的姓名：";
	string ParentName, ChildName;
	cin >> ParentName;

	cout << "请输入" << ParentName << "新添加的儿子（或女儿）的姓名：";
	cin >> ChildName;

	parent = new Members;
	parent = findParentNode(root, ParentName);
	addSonNode(parent, ChildName);

	Members* NewChild = new Members;
	cout << ParentName << "第一代子孙是：" << ChildName;

	cout << endl;
	cout << endl;
}
//成员函数：添加成员

void GenealogyManagement::deleteBranch(Members* root) {
	cout << "请输入要解散的家庭的人的姓名：";
	string ParentName;
	cin >> ParentName;
	cout << "要解散家庭的人是：" << ParentName << endl;

	parent = new Members;
	parent = findParentNode(root, ParentName);//找到要删除的成员节点

	parent = NULL;
	
	cout << endl;
	cout << endl;
}
//成员函数：删除某一分支

void GenealogyManagement::changeName(Members* root) {
	cout << "请输入要更改姓名的人的目前姓名：";
	string MemberName;
	cin >> MemberName;

	parent = new Members;
	parent = findParentNode(root, MemberName);//找到要修改姓名的成员节点

	cout << "请输入更改后的姓名：";
	string MemberName_New;
	cin >> MemberName_New;

	cout << MemberName << "已更名为" << MemberName_New<<endl;
	parent->name = MemberName_New;

	cout << endl;
}
//成员函数：修改某一成员姓名
