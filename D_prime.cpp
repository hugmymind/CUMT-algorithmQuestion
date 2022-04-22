/*
现在给你n（2<=n<=16）个正整数1,2,3...n，你的任务是把这n个正整数组成一个环，使得任意相邻的两个整数之和为一个素数，输出有多少种合法方案。
只有素数与素数的和是一个素数
输入
多组输入数据，每组数据只有一个正整数n（2<=n<=16）代表有n个正整数 1,2,3...n
输出
对每组数据，输出一个整数，代表有多少种不同的可行方案数。
样例输入
6
8

样例输出
2
4

提示
对于输入样例中的6，有以下2种合法方案（首尾相连构成一个环）
1 4 3 2 5 6
1 6 5 2 3 4
对于输入样例中的8，有以下4种合法方案（首尾相连构成一个环）
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
*/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int n, ans = 0, End, is[40] = {1, 1, 0, 0}, vis[20]; //这里 40 是为了判断 20 + 20
// 素数的判断   并且将对应的情况赋给 is数组  为0表示为素数
void judge()
{
    for (int i = 4; i < 36; i++)
    {
        is[i] = 0;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                is[i] = 1;
                break;
            }
        }
    }
}
void dfs(int x)
{
    // 遍历完后判断是否可以闭环 ，可以即形成环
    if (x == n && is[End + 1] == 0)
    {
        ans++;
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        //判断该数是否纳入环中，并且和现在环中最后一个数的和是否是素数
        if (vis[i] == 0 && is[End + i] == 0)
        {
            int tmp = End; //存储当前的值
            End = i;       //环中最后一个数变为当前的数
            vis[i] = 1;    //纳入环中vis改为1
            dfs(x + 1);    // 探索下一个可以纳入环中的数
            //回溯
            End = tmp;     //回归之前的状态
            vis[i] = 0;    //出环
        }
    }
}
int main()
{
    // memset(is, 0, sizeof(is)); //初始化素数组
    judge();
    while (cin >> n)
    {
        memset(vis, 0, sizeof(vis)); // 初始化访问组
        ans = 0, End = 1;
        dfs(1); //深度递归 ,第一个数1入环
        cout << ans << endl;
    }
    return 0;
}
