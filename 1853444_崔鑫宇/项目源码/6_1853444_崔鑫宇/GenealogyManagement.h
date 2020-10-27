#pragma once
#include<string>
#include<iostream>

using namespace std;

struct Members {//存储成员信息的单元
	string name = "";
	Members* FirstChildNode = NULL;
	Members* NextBrotherNode = NULL;
};

class GenealogyManagement
{public:
	GenealogyManagement();
	~GenealogyManagement();

	void buildGenealogy(Members*);
	//成员函数：建立家谱系统
	
	void addMember(Members*);
	//成员函数：添加成员
	
	void deleteBranch(Members*);
	//成员函数：删除某一分支

	void changeName(Members*);
	//成员函数：修改某一成员姓名

	Members* findParentNode(Members*, string);
	//成员函数：寻找目的节点
	
	void addSonNode(Members*, string);
	//成员函数：添加子节点

	void addBrotherNode(Members*, string);
	//成员函数：添加兄弟节点

private:
	Members* parent = NULL;
};

