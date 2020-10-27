#pragma once
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

void MakeSchedule(string CourseInformation[38][5], int num_of_course,int course_arranged) {
	
	string* ClassName = new string[num_of_course];
	int* ClassTime = new int[num_of_course];
	ofstream Outfile;
	Outfile.open("�α�(���ź�).txt", ios::app);
	
	for (int i = 0; i < num_of_course; i++) {
		//��ȡ��ѧ�ڵ�num_of_course�ڿγ���Ϣ
		//����ĳ�ÿ���ѧʱ������ClassTime*�У��γ�����ClassName*��		
		ClassName[i] = CourseInformation[course_arranged + i][1];
		ClassTime[i] = (int)(CourseInformation[course_arranged + i][2][0] - '0');
	}

	string Schedule[4][5];
	//���α���ÿ��Ԫ�س�ʼ��Ϊһ���ո����ڽ��������ſα���Ϊ
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			Schedule[i][j] = " ";
		}
	}

	//�ſα�
	for (int i = 0; i < num_of_course; i++) {
		int temp = 0;
		if (ClassTime[i] == 3) {//��ѧʱ�Ŀγ̵��ſα���
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
		else if (ClassTime[i] == 4) {//��ѧʱ�Ŀγ̵��ſα���
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
		else if (ClassTime[i] == 5) {//��ѧʱ�Ŀγ̵��ſα���
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
		else if (ClassTime[i] == 6) {//��ѧʱ�Ŀγ̵��ſα���
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

	//��Ŀ���ļ��д�ӡĳһѧ�ڵĿα�
	for (int i = 0; i < 4; i++) {
		Outfile << "��" << i + 1 << "���";
		for (int j = 0; j < 5; j++) {
			Outfile << setw(20) << Schedule[i][j];
		}
		Outfile << endl;
	}
	
	delete []ClassName;
	delete []ClassTime;
	Outfile.close();
}

