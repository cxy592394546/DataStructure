#include"GenealogyManagement.h"
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//绘制菜单选项
void PrintOption() {
	for (int i = 0; i < 96; i++) {
		cout << '*';
	}
	cout << endl;
	cout << "请输入你要进行的操作：A-完善家谱、B-添加家庭成员、C-解散局部家庭、D-更改家庭成员姓名、E-退出程序" << endl;
	for (int i = 0; i < 96; i++) {
		cout << '*';
	}
	cout << endl;

}


int main() {
	PrintOption();
	cout << "首先请建立一个家谱！" << endl;
	string name;
	cout << "请输入祖先的姓名：";
	cin >> name;
	cout << "此家谱的祖先是：" << name << endl;
	cout << endl;

	Members* root = new Members;
	root->name = name;
	GenealogyManagement Genealogy;

	char option = 'A';
	while (option == 'A' || option == 'B' || option == 'C' || option == 'D') {
		cout << "请选择要执行的操作：";
		cin >> option;
		switch (option) {
		case 'A':Genealogy.buildGenealogy(root); break;//建立家谱
		case 'B':Genealogy.addMember(root); break;//添加成员
		case 'C':Genealogy.deleteBranch(root); break;//删除分支
		case 'D':Genealogy.changeName(root); break;//修改姓名
		default: break;
		}
	}
	delete root;
	return 0;
}