#pragma once
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

void MakeSchedule(string CourseInformation[38][5], int num_of_course,int course_arranged) {
	
	string* ClassName = new string[num_of_course];
	int* ClassTime = new int[num_of_course];
	ofstream Outfile;
	Outfile.open("课表(已排好).txt", ios::app);
	
	for (int i = 0; i < num_of_course; i++) {
		//读取该学期的num_of_course节课程信息
		//其中某堂课周学时数存入ClassTime*中，课程名称ClassName*中		
		ClassName[i] = CourseInformation[course_arranged + i][1];
		ClassTime[i] = (int)(CourseInformation[course_arranged + i][2][0] - '0');
	}

	string Schedule[4][5];
	//将课表中每个元素初始化为一个空格利于接下来的排课表行为
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			Schedule[i][j] = " ";
		}
	}

	//排课表
	for (int i = 0; i < num_of_course; i++) {
		int temp = 0;
		if (ClassTime[i] == 3) {//三学时的课程的排课表方法
			for (int j = 1; j < 4; j += 2) {
				for (int k = 0; k < 5; k++) {
					if (Schedule[j][k] == " ") {
						Schedule[j][k] = ClassName[i];
						j = 4;
						k = 5;
					}
				}
			}
		}
		else if (ClassTime[i] == 4) {//四学时的课程的排课表方法
			for (int j = 0; j < 4; j += 2) {
				for (int k = 0; k < 5; k++) {
					if (Schedule[j][k] == " ") {
						Schedule[j][k] = ClassName[i];
						temp = k;
						j = 4;
						k = 5;
					}
				}
			}
			if (temp == 0) {
				for (int j = 0; j < 4; j += 2) {
					for (int k = 2; k < 5; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 1) {
				for (int j = 0; j < 4; j += 2) {
					for (int k = 3; k < 5; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 2) {
				for (int j = 0; j < 4; j += 2) {
					for (int k = 0; k < 5; k += 4) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 3) {
				for (int j = 0; j < 4; j += 2) {
					for (int k = 0; k < 2; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 4) {
				for (int j = 0; j < 4; j += 2) {
					for (int k = 0; k < 3; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
		}
		else if (ClassTime[i] == 5) {//五学时的课程的排课表方法
			for (int j = 0; j < 4; j += 2) {
				for (int k = 0; k < 5; k++) {
					if (Schedule[j][k] == " ") {
						Schedule[j][k] = ClassName[i];
						temp = k;
						j = 4;
						k = 5;
					}
				}
			}
			if (temp == 0) {
				for (int j = 1; j < 4; j += 2) {
					for (int k = 2; k < 5; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 1) {
				for (int j = 1; j < 4; j += 2) {
					for (int k = 3; k < 5; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 2) {
				for (int j = 1; j < 4; j += 2) {
					for (int k = 0; k < 5; k += 4) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 3) {
				for (int j = 1; j < 4; j += 2) {
					for (int k = 0; k < 2; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 4) {
				for (int j = 0; j < 4; j += 2) {
					for (int k = 0; k < 3; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
		}
		else if (ClassTime[i] == 6) {//六学时的课程的排课表方法
			for (int j = 1; j < 4; j += 2) {
				for (int k = 0; k < 5; k++) {
					if (Schedule[j][k] == " ") {
						Schedule[j][k] = ClassName[i];
						temp = k;
						j = 4;
						k = 5;
					}
				}
			}
			if (temp == 0) {
				for (int j = 1; j < 4; j += 2) {
					for (int k = 2; k < 5; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 1) {
				for (int j = 1; j < 4; j += 2) {
					for (int k = 3; k < 5; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 2) {
				for (int j = 1; j < 4; j += 2) {
					for (int k = 0; k < 5; k += 4) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 3) {
				for (int j = 1; j < 4; j += 2) {
					for (int k = 0; k < 2; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
			else if (temp == 4) {
				for (int j =1; j < 4; j += 2) {
					for (int k = 0; k < 3; k++) {
						if (Schedule[j][k] == " ") {
							Schedule[j][k] = ClassName[i];
							j = 4;
							k = 5;
						}
					}
				}
			}
		}
	}

	//向目标文件中打印某一学期的课表
	for (int i = 0; i < 4; i++) {
		Outfile << "第" << i + 1 << "大节";
		for (int j = 0; j < 5; j++) {
			Outfile << setw(20) << Schedule[i][j];
		}
		Outfile << endl;
	}
	
	delete []ClassName;
	delete []ClassTime;
	Outfile.close();
}

