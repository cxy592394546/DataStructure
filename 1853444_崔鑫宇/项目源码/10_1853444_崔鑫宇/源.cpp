#include <iostream>
#include <time.h>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <string>
#include "Heap.h"
using namespace std;

vector<int> vec1;

//�ж��Ƿ�Ϊ����
bool isPositive(string s)
{
	for (unsigned int i = 0; i < s.size(); i++) {
		if (i = s.size() - 1 && s[i] <= '9' && s[i] >= '0') {
			return true;
		}
		else if (!(s[i] <= '9' && s[i] >= '0'))
			return false;
		else continue;
	}
}

template<typename type>
void swap(vector<type> vec, type m, type n) {
	type temp = vec[m];
	vec[m] = vec[n];
	vec[n] = temp;

}
//ð������
void BubbleSort(vector<int>& vec, int n, long long& compare_times) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			compare_times++;
			if (vec[j] > vec[j + 1]) {
				swap(vec, j, j + 1);
			}
		}
	}
}

//ѡ������
void SelectionSort(vector<int>& vec, int n, long long& swap_times) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			swap_times++;
			if (vec[j] < vec[min]) {
				min = j;
			}
		}
		swap(vec, i, min);
	}
}

//��������
void InsertionSort(vector<int>& vec, int n, long long& swap_times) {
	int temp;
	for (int i = 1; i < n; i++) {
		temp = vec[i];
		for (int j = i - 1; j >= 0; j--) {

			if (j == 0) {
				vec[j] = temp;
			}
	
			if (temp < vec[j]) {
				vec[j + 1] = vec[j];
				swap_times++;
			}
			else {
				vec[j + 1] = temp;
				break;
			}
		}
	}
}

//ϣ������
void ShellSort(vector<int>& vec, int n, long long& swap_times) {
	int gap = (int)(n / 2);
	while (gap) {
		for (int i = gap; i < n; i++) {
			for (int j = i; j >= gap && vec[j] < vec[j - gap]; j -= gap) {
				swap(vec, j, j - gap);
				swap_times++;
			}
		}
		gap = gap == 2 ? 1 : (int)(gap / 2.2);
	}
}

//��������
void QuickSort(vector<int>& vec, const int left, const int right, long long& swap_times) {

	if (left < right) {
		int pivotPos = left;
		int pivot = vec[left];
		for (int i = left + 1; i <= right; i++) {
			swap_times++;
			if (vec[i] < pivot) {
				pivotPos++;
				if (pivotPos != i) {
					swap(vec, pivotPos, i);

				}
			}
		}
		vec[left] = vec[pivotPos];
		vec[pivotPos] = pivot;
		QuickSort(vec, left, pivotPos - 1, swap_times);
		QuickSort(vec, pivotPos + 1, right, swap_times);
	}
}

//������
void HeapSort(vector<int>& vec, int size, long long& swap_times) {
	Heap maxHeap = Heap(vec, size, swap_times);
	for (int i = size - 1; i > 0; i--) {
		maxHeap.swap(0, i);
		swap_times++;
		maxHeap.OrderDown(0, i - 1, swap_times);
	}
}

//�鲢����
void merge(vector<int>& L1, vector<int>& L2, const int left, const int mid, const int right, long long& compare_times) {

	for (int i = left; i <= right; i++) {
		L2[i] = L1[i];
	}
	int s1 = left;
	int s2 = mid + 1;
	int t = left;
	while (s1 <= mid && s2 <= right) {
		compare_times++;
		if (L2[s1] <= L2[s2]) {
			L1[t++] = L2[s1++];
		}
		else {
			L1[t++] = L2[s2++];
		}
	}
	while (s1 <= mid) {
		compare_times++;
		L1[t++] = L2[s1++];
	}
	while (s2 <= right) {
		compare_times++;
		L1[t++] = L2[s2++];
	}
}

//�鲢����
void MergeSort(vector<int>& L1, vector<int>& L2, int left, int right, long long& compare_times) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(L1, L2, left, mid, compare_times);
		MergeSort(L1, L2, mid + 1, right, compare_times);
		merge(L1, L2, left, mid, right, compare_times);
	}
}

int MaxBit(vector<int> B, int n) {
	int max = B[0];
	for (int i = 1; i < n; i++) {
		if (max < B[i]) {
			max = B[i];
		}
	}
	int d = 1;
	int p = 10;
	while (max >= p) {
		max = max / 10;
		d++;
	}
	return d;
}

//��������
void RadixSort(vector<int>& vec, int size, long long& swap_times) {
	int d = MaxBit(vec, size);
	int* temp = new int[size];
	int count[10];

	int radix = 1;

	for (int i = 1; i <= d; i++) {
	
		for (int j = 0; j < 10; j++) {
			count[j] = 0;
		}
		for (int j = 0; j < size; j++) {
			int k = (vec[j] / radix) % 10;
			count[k]++;
		}
		for (int j = 1; j < 10; j++) {
			count[j] = count[j - 1] + count[j];
		}

		for (int j = size - 1; j >= 0; j--) {
			int k = (vec[j] / radix) % 10;
			temp[count[k] - 1] = vec[j];
			count[k]--;
		}
		for (int j = 0; j < size; j++) {
			vec[j] = temp[j];
		}
		radix *= 10;
	}
}

vector<int> copyVector(int n) {
	vector<int> vec2;
	for (int i = 0; i < n; i++) {
		vec2.push_back(vec1[i]);
	}
	return vec2;
}

//������������Ԫ�ص������Ƿ����Ҫ��
int checkInput(string input, int& num) {
	if (!isPositive(input)) {
		cout << "������1-1000000֮���һ��������!";
		return 0;
	}
	num = stoi(input);
	if (num > 1000000 || num == 0) {
		cout << "���������1-1000000֮��";

		return 0;
	}
	return 1;
}

int main()
{
	cout << "**" << setw(10) << ' ' << "�����㷨�Ƚ�" << setw(10) << ' ' << "**" << endl;
	cout << "====================================" << endl;
	cout << "**" << setw(9) << ' ' << "1 --- ð������" << setw(9) << ' ' << "**" << endl;
	cout << "**" << setw(9) << ' ' << "2 --- ѡ������" << setw(9) << ' ' << "**" << endl;
	cout << "**" << setw(9) << ' ' << "3 --- ֱ�Ӳ�������" << setw(5) << ' ' << "**" << endl;
	cout << "**" << setw(9) << ' ' << "4 --- ϣ������" << setw(9) << ' ' << "**" << endl;
	cout << "**" << setw(9) << ' ' << "5 --- ��������" << setw(9) << ' ' << "**" << endl;
	cout << "**" << setw(9) << ' ' << "6 --- ������" << setw(11) << ' ' << "**" << endl;
	cout << "**" << setw(9) << ' ' << "7 --- �鲢����" << setw(9) << ' ' << "**" << endl;
	cout << "**" << setw(9) << ' ' << "8 --- ��������" << setw(9) << ' ' << "**" << endl;
	cout << "**" << setw(9) << ' ' << "9 --- �˳�����" << setw(9) << ' ' << "**" << endl;
	cout << "====================================" << endl;
	string input;
	int num;
	int i = 1;
	while (i != 0) {
		cout << "������Ҫ����������ĸ���: ";
		cin >> input;


		//���������������Ƿ�ϸ�
		if (!checkInput(input, num)) {
			cout << endl << endl;
		}
		else {
			i = 0;
		}
	}

	//���������
	srand((unsigned)time(NULL));
	for (int i = 0; i < num; i++) {
		int item = rand();
		vec1.push_back(item);
	}

	i = 1;
	vector<int> vec2, vec3;
	long long swap_times, compare_times;
	
	while (i != 9) {
		cout << endl << "��ѡ�������㷨��";
		cin >> i;
		unsigned long long  time_start, time_end;


		switch (i) {
		case 1:
			vec2 = copyVector(num);
			swap_times = 0;
			time_start = GetTickCount64();
			BubbleSort(vec2, num, swap_times);
			time_end = GetTickCount64();
			cout << "ð����������ʱ�䣺" << (time_end - time_start) << "ms" << endl;
			cout << "ð�����򽻻�������" << swap_times << endl;
			break;
		case 2:
			vec2 = copyVector(num);
			swap_times = 0;
			time_start = GetTickCount64();
			SelectionSort(vec2, num, swap_times);
			time_end = GetTickCount64();
			cout << "ѡ����������ʱ�䣺" << (time_end - time_start) << "ms" << endl;
			cout << "ѡ�����򽻻�������" << swap_times << endl;
			break;
		case 3:
			vec2 = copyVector(num);
			swap_times = 0;
			time_start = GetTickCount64();
			InsertionSort(vec2, num, swap_times);
			time_end = GetTickCount64();
			cout << "ֱ�Ӳ�����������ʱ�䣺" << (time_end - time_start) << "ms" << endl;
			cout << "ֱ�Ӳ������򽻻�������" << swap_times << endl;
			break;
		case 4:
			vec2 = copyVector(num);
			swap_times = 0;
			time_start = GetTickCount64();
			ShellSort(vec2, num, swap_times);
			time_end = GetTickCount64();
			cout << "ϣ����������ʱ�䣺" << (time_end - time_start) << "ms" << endl;
			cout << "ϣ�����򽻻�������" << swap_times << endl;
			break;
		case 5:
			vec2 = copyVector(num);

			swap_times = 0;
			time_start = GetTickCount64();
			QuickSort(vec2, 0, num - 1, swap_times);
			time_end = GetTickCount64();
			cout << "������������ʱ�䣺" << (time_end - time_start) << "ms" << endl;
			cout << "�������򽻻�������" << swap_times << endl;
			break;
		case 6:
			vec2 = copyVector(num);

			swap_times = 0;
			time_start = GetTickCount64();
			HeapSort(vec2, num, swap_times);
			time_end = GetTickCount64();
			cout << "����������ʱ�䣺" << (time_end - time_start) << "ms" << endl;
			cout << "�����򽻻�������" << swap_times << endl;
			break;
		case 7:
			vec2 = copyVector(num);
			vec3 = copyVector(num);

			compare_times = 0;
			time_start = GetTickCount64();
			MergeSort(vec2, vec3, 0, num - 1, compare_times);
			time_end = GetTickCount64();

			cout << "�鲢��������ʱ�䣺" << (time_end - time_start) << "ms" << endl;
			cout << "�鲢����Ƚϴ�����" << compare_times << endl;
			break;
		case 8:
			vec2 = copyVector(num);

			swap_times = 0;
			time_start = GetTickCount64();
			RadixSort(vec2, num, compare_times);
			time_end = GetTickCount64();

			cout << "������������ʱ�䣺" << (time_end - time_start) << "ms" << endl;
			cout << "�������򽻻�������" << swap_times << endl;
			break;
		case 9:
			break;
		default:
			cerr << "������1��9���һ��������!" << endl;
			break;
		}
	}
}