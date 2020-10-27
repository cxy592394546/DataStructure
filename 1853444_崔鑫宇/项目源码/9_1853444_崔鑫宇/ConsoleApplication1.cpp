#include"MakeSchedule.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

int main() {
	int sum = 0;
	int num_per_term[8] = { 0 };
	
	//8个学期课程总数为38科，所以先检测8个学期课程数是否符合要求
	while (sum != 38) {
		cout << "请依次输入每个学期所开的课程数:";
		for (int i = 0; i < 8; i++) {
			cin >> num_per_term[i];
			sum += num_per_term[i];
		}
		if (sum != 38) {
			cerr << "8个学期课程数总和应为38！请重新输入！" << endl;
			sum = 0;
			//课程总数如果不为38科，要求重新输入
		}
		else {
			cout << "输入成功，请等待！" << endl;
			//课程总数为38科，进入排课模式
		}
	}
	sum = 0;

	ifstream Infile;
	Infile.open("课表.txt");
	ofstream Outfile;
	Outfile.open("课表(已排好).txt", ios::app);

	int times = 0;//读取课程信息次数
	int recorded = 0;//记录已读取课程数
	string CourseInformation[38][5];
	int arranged = 0;

	for (int i = 0; i < 8; i++) {
		while (times != num_per_term[i] * 5) {
			Infile >> CourseInformation[recorded][times % 5];
			//从文件中读取课程信息至38*5的数组中
			if (times % 5 == 4) {
				recorded++;
			}
			times++;
		}
		times = 0;
	}
	for (int i = 0; i < 8; i++) {
		//打印课表
		Outfile << setw(50) << "第" << i + 1 << "学期" << endl;

		Outfile << setw(25) << "Mon" << setw(20) << "Tues" << setw(20) << "Wen" << setw(20) << "Thur" << setw(20) << "Fri" << endl;
		MakeSchedule(CourseInformation, num_per_term[i], arranged);
		
		arranged += num_per_term[i];
		Outfile << endl;
		Outfile << endl;
	}

	cout << "排课成功，请检验成果！" << endl;//出现这句话则表示排课已完成
	
	Infile.close();
	Outfile.close();
	return 0;
}