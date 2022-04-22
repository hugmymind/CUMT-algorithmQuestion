/*
 请考虑一个被空格分隔的，由1到N的整数组成的递增数列：1 2 3 ...N。现在请在数列中插入表示加的“+”，或者表示减“-”，亦或者表示空白的“ ”
 (例如1-2 3就等于1-23)，来将每一对数字组合成一个表达式（第一个数字前无空格）。计算该表达式的结果并判断其值是否为0。
 请你写一个程序找出所有产生和为零的长度为N的数列。
输入
输入为一行，包含一个整数N，3≤N≤9。
输出
输出为所有在每对数字间插入“+”, “-”, 或 “ ”后能得到和为零的数列，并按照字典（ASCII码）序排列。  字典序：先空格再加号再减号
样例输入
7

样例输出
1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7
*/
#include<iostream>
using namespace std;
char s[20];
int n;

void dfs(int curPos, int preSum, int curValue) {  //三个参数为 当前位置，不含当前位置的和  当前位置的值
    //递归出口
    if (curPos == n) {
        if (preSum + curValue == 0) {
            cout << s << endl;
        }
        return;
    }
    //先 试着填入 " "
    s[curPos * 2 - 1] = ' ';
    if (curValue > 0) {
        dfs(curPos + 1, preSum, curValue * 10 + curPos + 1);  //下一个搜索的值  位数扩展了，cuurPos + 1
    } else {
        dfs(curPos + 1, preSum, curValue * 10 - (curPos + 1)); //如果当前位置值为负，例如：1-2 3-4 5+6 7  -2和3 变为 -23
    }
    s[curPos * 2 - 1] = '+';  //试着填入 +
    dfs(curPos + 1, preSum + curValue, curPos + 1);   // +则求和，下一个数的值 为 curPos + 1
    s[curPos * 2 - 1] = '-';
    dfs(curPos + 1, preSum + curValue, -(curPos + 1)); //负数，下一个值为 -(curPos + 1)
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        s[i * 2] = i + '1';
    }
    dfs(1, 0, 1);
    return 0;
}

