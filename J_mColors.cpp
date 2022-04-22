/*
给定无向连通图G和m种不同的颜色，用这些颜色给图的各个顶点着一种颜色，若某种方案使得图中每条边的2个顶点的颜色都不相同，则是一个满足的方案，
找出所有的方案。
输入
第一行有3个正整数n，k和m，分别表示n个顶点，k条边，m种颜色
接下来k行，每行2个正整数，表示一条边的两个顶点
输出
所有不同的着色方案数
样例输入
5 8 4 
1 2
1 3 
1 4
2 3
2 4
2 5
3 4
4 5

样例输出
48
*/
#include<iostream>
using namespace std;
class Color
{
	friend void mcoloring(int n, int m, int** a);  //友元函数
private:
	bool isUsed(int t);  //判断该点能否给一个颜色
	void Backtrack(int i);
	int n; //顶点数
	int m; //颜色数
	int** a; //邻接矩阵
	int* x; //当前解    x[i] 表示 第 i 点颜色
	long sum; //方案数
};

//约束函数，判断顶点 t 与相邻顶点是否存在相同的着色  如果存在就返回false
bool Color::isUsed(int t)  
{
	for (int i = 1; i < t; i++)
		if (a[i][t] == 1 && x[i] == x[t])   //如果两个点直接相连并且 颜色相同 则返回false
			return false;
	return true;
}

//关键处理函数，DFS加剪枝
void Color::Backtrack(int i)
{
	if (i > n)
	{
		sum++;  //满足条件  总方案数++
	}
	else
	{
		for (int j = 1; j <= m; j++)
		{
			x[i] = j;  //尝试给第 i 个 顶点颜色 j
			if (isUsed(i))   // 可以给颜色
				Backtrack(i + 1);
			x[i] = 0;  //回溯，不给颜色
		}
	}
}

//图的m着色的  主调用函数
void mcoloring(int n, int m, int **a)
{
	Color X;
	X.n = n;
	X.m = m;
	X.a = a;
	X.sum = 0;
	int* p = new int[n+1];
	for (int i = 1; i <= n; i++)
		p[i] = 0;  //初始化数组
	X.x = p;  // X.x 存放的是最终解的结构
	X.Backtrack(1);  //从第1个元素开始回溯，  输入的元素也是从1开始的
	delete[]p;
	cout << X.sum;
}

int main()
{
	int n, k, m;
	cin >> n >> k >> m;
	int k1, k2;
	int** a = new int* [n+1];
	for (int i = 1; i <= n; i++)
		a[i] = new int[n + 1];
	for (int i = 1; i <= k; i++)
	{
		cin >> k1 >> k2;
		a[k1][k2] = 1;
	}
	mcoloring(n, m, a);
	return 0;
}
