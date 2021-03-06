#include <iostream>
#include <time.h>
#include <iomanip>
#include"MyStack.h"
#define Size 8

using namespace std;

const char BuiltTool[10] = { '#', '#', '#','*','*' ,'*', '*', '*','*','*' };

//用点表示迷宫数组中的各元素的坐标
struct point{
	int x, y, dir;
	point(int x, int y, int dir){
		this->x = x;
		this->y = y;
		this->dir = dir;
	}
	void print(){
		cout << setw(8) << this->x << setw(8) << this->y << setw(8) << this->dir << endl;
	}
};

//定义上下左右四个移动方向
point dir(int d){
	int a = 0, b = 0;
	
	switch (d){
	case(0):a = -1;break;
	case(1):b = 1;break;
	case(2):a = 1;break;
	case(3):b = -1;break;
	default:
		break;
	}
	
	point p0(a, b, d);
	
	return p0;
}

//移动操作
void move(point& p, int i){
	p.x += dir(i).x;
	p.y += dir(i).y;
	p.dir = i;
}

//建造迷宫
char** BuildMaze(){
	 
	char** Maze = new char* [Size];
	for (int i = 0; i < Size; i++) {
		Maze[i] = new char[Size];
	}
 
	srand((unsigned)time(NULL));
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
 
			if ((i == 0) || (i == Size - 1) || (j == 0) || (j == Size - 1)) {
				if (i == 1 && j == 0) {//用‘B’表示迷宫起点
					Maze[i][j] = 'B';
				}
				else if (i == Size - 2 && j == Size - 1) {//用‘E’表示迷宫终点
					Maze[i][j] = 'E';
				}
				else
					Maze[i][j] = BuiltTool[0];
			}
			else if ((i == 1 && j == 0) || (i == 1 && j == 1) || (i == Size - 2 && j == Size - 1) || (i == Size - 2 && j == Size - 2)) {
				Maze[i][j] = BuiltTool[9];
			}
			else
			 
				Maze[i][j] = BuiltTool[rand() % 10];
		}
	}
	return Maze;
}

//打印迷宫
void MazePrint(char** maze)
{
	cout << setw(8) << ' ';
	for (int i = 0; i < Size; i++) {
		cout << setw(4) << i << "行";
	}
	cout << endl << setw(6);
	for (int i = 0; i < Size; i++) {
		cout << i << "列" << setw(5);
		for (int j = 0; j < Size; j++) {
			cout << maze[i][j] << setw(6);
		}
		cout << endl;
	}
}

//用字符数组来模拟迷宫
char Maze[Size][Size];

//寻找相应的点
MyStack<point> Search(char** maze){
	 
	MyStack<point> s;
 
	point p(1, 1, 2);

	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			Maze[i][j] = BuiltTool[9];
		}
	}

	Maze[0][1] = 1;
	Maze[1][1] = 1;
	s.push(p);
	int i = 0;
	 
	while (s.size()!=0)
	{
		while (i < 8)
		{
			int x = p.x + dir(i).x;
			int y = p.y + dir(i).y;
			 
			if (maze[x][y] == '*' && Maze[x][y] == '*') {
				move(p, i);
				s.push(p);
				if (x == Size - 2 && y == Size - 2) {
					return s;
				}
				 
				Maze[x][y] = '#';
				i = 0;
				continue;
			}
			++i;
		}
		s.pop();
		if (s.size()==0) {
			cerr << "该迷宫入口与出口间没有通路！";
		}
		else{
			p = point(s.top().x, s.top().y, s.top().dir);
			i = 0;
		}
	}
}

int main(){
	char **maze = BuildMaze();
	cout << "迷宫地图：" << endl;

	MazePrint(maze);//打印随机生成的迷宫的初始状态
	
	cout << endl;
	MyStack<point> s = Search(maze);
	MyStack<point> out;
	cout << endl;

	while (s.size() != 0) {
		point p = s.top();
		out.push(p);
		s.pop();
	}
	while (out.size() != 0) {
		point q = out.top();
		out.pop();
		if (out.size() == 0) {
			cout << "(" << q.x << "," << q.y << ")" << endl;
			maze[q.x][q.y] = '0';
		}
		else {
			cout << "(" << q.x << "," << q.y << ") ---> ";
			maze[q.x][q.y] = '0';
		}
	}

	cout << endl;
	
	MazePrint(maze);
	//打印描绘出通路的（如存在通路）迷宫的最终状态

	return 0;
}