/*
 无脑博士有三个容量分别是 A,B,C 升的试管，A,B,C分别是三个从 1到 20的整数，最初，A 和 B 试管都是空的，而 C 试管是装满硫酸铜溶液的。有
 时，无脑博士把硫酸铜溶液从一个试管倒到另一个试管中，直到被灌试管装满或原试管空了。当然每一次灌注都是完全的。
 由于无脑博士天天这么折腾，早已熟练，溶液在倒的过程中不会有丢失。
写一个程序去帮助无脑博士找出当 A 试管是空的时候，C 试管中硫酸铜溶液所剩量的所有可能性。
输入
多组测试用例，对于每组测试用例，输入包括一行，为空格分隔开的三个数，分别为整数 A,B,C。
输出
输出包括一行，升序地列出当 A 试管是空的时候，C 试管溶液所剩量的所有可能性。
样例输入
2 5 10

样例输出
5 6 7 8 9 10
*/
/*#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
using namespace std;

int A, B, C;
// res[a][b] 存储A B中液体为a b的情况是否遍历过
int res[21][21];

//深搜 回溯
//参数为A B C 试管的液体总量
void backtrace(int a, int b, int c)
{
    res[a][b] = 1;  //标记为已遍历过
    int a0 = a, b0 = b, c0 = c;
    if (a < A)
    { // A未满
        if (b > 0)
        { // B -> A
            if (b >= A - a)
            { // A倒满
                b = b - A + a;
                a = A;
            }
            else
            { // B倒空
                a += b;
                b = 0;
            }
            if (res[a][b] == 0)  //如果当前的情况 没有遍历过则尝试
                backtrace(a, b, c);
            // 回溯
            a = a0;
            b = b0;
        }
        if (c > 0)
        { // C -> A
            if (c >= A - a)
            { // A倒满
                c = c - A + a;
                a = A;
            }
            else
            { // C倒空
                a += c;
                c = 0;
            }
            if (res[a][b] == 0)
                backtrace(a, b, c);
            a = a0;
            c = c0;
        }
    }
    if (b < B)
    { // B未满
        if (a > 0)
        { // A -> B
            if (a >= B - b)
            { // B倒满
                a = a - B + b;
                b = B;
            }
            else
            { // A倒空
                b += a;
                a = 0;
            }
            if (res[a][b] == 0)
                backtrace(a, b, c);
            a = a0;
            b = b0;
        }
        if (c > 0)
        { // C -> B
            if (c >= B - b)
            { // B倒满
                c = c - B + b;
                b = B;
            }
            else
            { // C倒空
                b += c;
                c = 0;
            }
            if (res[a][b] == 0)
                backtrace(a, b, c);
            b = b0;
            c = c0;
        }
    }
    if (c < C)
    { // C未满
        if (a > 0)
        { // A -> C
            if (a >= C - c)
            { // C倒满
                a = a - C + c;
                c = C;
            }
            else
            { // A倒空
                c += a;
                a = 0;
            }
            if (res[a][b] == 0)
                backtrace(a, b, c);
            a = a0;
            c = c0;
        }
        if (b > 0)
        { // B -> C
            if (b >= C - c)
            { // C倒满
                b = b - C + c;
                c = C;
            }
            else
            { // B倒空
                c += b;
                b = 0;
            }
            if (res[a][b] == 0)
                backtrace(a, b, c);
            b = b0;
            c = c0;
        }
    }
}

int main()
{

    while (~scanf("%d %d %d", &A, &B, &C))
    {
        memset(res,0,sizeof(res));   //错误的原因在于，循环输入时没有将 已经赋值过的res数组置零
        backtrace(0, 0, C);
        for (int i = B; i >= 0; i--)
        {
            // cout << res[0][i] << " ";
            if (res[0][i] == 1) //可能的情况
            {
                cout << C - i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int A, B, C;
int dp[30][30][30];
vector<int> ans;

void solve(int a, int b, int c)
{
    if (dp[a][b][c])
        return; //如果访问过就返回
    dp[a][b][c] = 1;
    if (a == 0)
        ans.push_back(c); //如果A试管为空

    if (a <= B - b)
        solve(0, a + b, c); // a可以全部倒入B中 a倒空
    else
        solve(a + b - B, B, c); //  a 把 b 倒满

    if (b <= A - a)
        solve(a + b, 0, c); // b向 a 倒空
    else
        solve(A, a + b - A, c); // b把a 倒满

    if (a <= C - c)
        solve(0, b, a + c); // a 向 c 倒空
    else
        solve(a + c - C, b, C); // a 把 c 倒满

    if (c <= A - a)
        solve(a + c, b, 0); // c 向 a 倒空
    else
        solve(A, b, a + c - A); // c 把 a倒满

    if (b <= C - c)
        solve(a, 0, b + c); // b 向 c倒空
    else
        solve(a, b + c - C, C); // b 把 c 倒满

    if (c <= B - b)
        solve(a, b + c, 0); // c 向 b倒空
    else
        solve(a, B, b + c - B); // c 把 b倒满
}

int main()
{
    while (scanf("%d%d%d", &A, &B, &C) == 3)
    {
        memset(dp, 0, sizeof(dp));
        ans.clear();
        solve(0, 0, C);
        sort(ans.begin(), ans.end());
        int len = ans.size();
        for (int i = 0; i < len; i++)
            //printf("%d%c", ans[i], i + 1 == len ? '\n' : ' '); //最后一个元素输入换行
            printf("%d%c", ans[i],' ');
        printf("\n");
    }
    return 0;
}