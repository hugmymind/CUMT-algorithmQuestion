/*
现在要求你用下面给定的方法对数据实现加密。给定长度为n的字符串S（1<=n<=2000,S中只有大写字母）作为明文，
要求构造一个字符串T作为密文，起初T是一个空串，之后反复执行以下任意操作
1.从S的头部删除一个字符，加入到T的尾部
2.从S的尾部删除一个字符，加入到T的尾部

最后S会变成空串，T会变成一个长度为n的字符串作为密文。当然并非所有的构造方案都是符合条件的，我们要求构造出的密文T的字典序尽可能小，
输入
输入包含多组数据，每组数据占两行，第一行为一个整数n（1<=n<=2000）代表字符串S的长度，第二行为一个长度为n的字符串S代表明文，
保证S中只有大写字母
输出
对每组数据，输出一行字符串，代表构造出的字典序最小的密文T
样例输入
6
ACDBCB

样例输出
ABCBCD
*/
#include <iostream>
using namespace std;
//%c是个较为特殊的说明符。%c前没空格，scanf()将读取第一个字符，%c前有空格，scanf()则读取标准输入流中第一个非空白字符，屏蔽了空白字符。
int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        char a[n], ans[n];
        for (int i = 0; i < n; i++)
        {
            scanf(" %c", &a[i]); //这里%c前有空格，
        }
        int p = 0, q = n - 1; // p 和 q一个指向头，一个指向尾
        int index = 0;
        while (p <= q)
        {
            bool left = true; //是否从左边取，true取最左边，false取最右边
            int mid = (p + q) >> 1;
            for (int i = 0; i < mid; i++)
            { //判断当前字符是否相等，如果相等，比较下一对
                // 左边字典序小
                if (a[p + i] < a[q - i])
                {
                    left = true;
                    break;
                }
                else if (a[p + i] > a[q - i])
                {
                    left = false;
                    break;
                }
            }
            if (left)
            { //如果从左边取，将其计入到 ans结果里
                ans[index++] = a[p++];
            }
            else
            {
                ans[index++] = a[q--];
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%c", ans[i]);
        }
        cout << "\n";
    }
    return 0;
}