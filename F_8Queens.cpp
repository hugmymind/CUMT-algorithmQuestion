/*
8 皇后的规则就是不能有任何棋子同行或者同列或者同斜线，在满足这个规则的同时，王位继承者还需要让 8 个皇后所在的位置的数字的和是最大的。
输入
输入一个数字 k(k≤20)，代表棋盘的数量。

接下来有 k 个棋盘，每个棋盘有 64 个数字，分成 8 行 8 列输入，具体可见样例，每一个数字均小于 100。
输出
每一个棋盘对应输出最大的数值， 一共输出 k行
样例输入
1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64

样例输出
260
*/

#include <iostream>
#include <cstring>
using namespace std;
int Max;                       // 存最大数
int map[9][9];                     // 存放键盘
int check[3][17]; // 存放列和两个对角线的使用情况 对于元素在左下到右上对角线上的元素满足 i + j 为定值  左上到右下满足 i - j 为定值
int qpos[9];      //标记皇后的位置为(i, tmp[i])
void DFS(int i)
{
    if (i > 8)
    {
        int x = 0;
        for (int j = 1; j <= 8; j++)
        {
            x += map[j][qpos[j]];
        }
        if (x > Max)
            Max = x;
    }
    for (int j = 1; j <= 8; j++)
    {
        if (check[0][j] != 1 && check[1][i + j] != 1 && check[2][i - j + 8] != 1)
        {
            qpos[i] = j;
            // 走过的路都标记为 1
            check[0][j] = check[1][i + j] = check[2][i - j + 8] = 1;
            DFS(i + 1);
            // 返回上一次状态
            check[0][j] = check[1][i + j] = check[2][i - j + 8] = 0;
        }
    }
}
int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        // 初始化
        Max = 0;
        //memset(tmp, 0, 10);
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                cin >> map[i][j];
            }
        }
        // 回溯
        DFS(1);
        cout << Max << endl;
    }
    return 0;
}
