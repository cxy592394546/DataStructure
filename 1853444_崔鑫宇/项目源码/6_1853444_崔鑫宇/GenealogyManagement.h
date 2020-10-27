#pragma once
#include<string>
#include<iostream>

using namespace std;

struct Members {//�洢��Ա��Ϣ�ĵ�Ԫ
	string name = "";
	Members* FirstChildNode = NULL;
	Members* NextBrotherNode = NULL;
};

class GenealogyManagement
{public:
	GenealogyManagement();
	~GenealogyManagement();

	void buildGenealogy(Members*);
	//��Ա��������������ϵͳ
	
	void addMember(Members*);
	//��Ա��������ӳ�Ա
	
	void deleteBranch(Members*);
	//��Ա������ɾ��ĳһ��֧

	void changeName(Members*);
	//��Ա�������޸�ĳһ��Ա����

	Members* findParentNode(Members*, string);
	//��Ա������Ѱ��Ŀ�Ľڵ�
	
	void addSonNode(Members*, string);
	//��Ա����������ӽڵ�

	void addBrotherNode(Members*, string);
	//��Ա����������ֵܽڵ�

private:
	Members* parent = NULL;
};

