/*
例如，当偏移量是左移3的时候：
明文字母表：ABCDEFGHIJKLMNOPQRSTUVWXYZ
密文字母表：DEFGHIJKLMNOPQRSTUVWXYZABC
使用时，加密者查找明文字母表中需要加密的消息中的每一个字母所在位置，并且写下密文字母表中对应的字母。
需要解密的人则根据事先已知的密钥反过来操作，得到原来的明文。例如：
明文：THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
密文：WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ
现在给定你一个字符串S（长度不会超过1000000）和一个整数k（-1000000000<=k<=1000000000），
分别代表接受者收到的密文和在加密该密文时向后的偏移量，你的任务是计算出原来的明文
注意：只有字母在加密时才会发生偏移，其它字符保持不变
输入
输入包含多组数据，其中第一行为数据组数T（T<=10）
每组数据第一行为一个字符串S，由数字、字母以及常见字符组成（不含空格），
第二行为一个整数k代表加密时向后的偏移量（|S|<=1000000,-1000000000<=k<=1000000000）
输出
对每组数据，输出一行字符串，代表输入中的密文对应的明文。
样例输入
1
DEFGHIJKLMNOPQRSTUVWXYZABC
3
样例输出
ABCDEFGHIJKLMNOPQRSTUVWXYZ
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string h;
        cin >> h;
        int k;
        cin >> k;
        int s = k % 26;
        for (int i = 0; i < h.length(); i++)
        {
            if (h[i] >= 'A' && h[i] <= 'Z')
            {
                int x = h[i] - 'A';
                h[i] = 'A' + (x - s + 26) % 26;
            }
            else if (h[i] >= 'a' && h[i] <= 'z')
            {
                int x = h[i] - 'a';
                h[i] = 'a' + (x - s + 26) % 26;
            }
        }
        for (int i = 0; i < h.length(); i++)
            cout << h[i];
        cout << endl;
    }
}
