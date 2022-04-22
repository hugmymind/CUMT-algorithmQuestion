/*
Vigenère 加密在操作时需要注意：
运算忽略参与运算的字母的大小写，并保持字母在明文 MM 中的大小写形式；
当明文 M的长度大于密钥 k的长度时，将密钥 k重复使用。 例如，明文 M=Helloworld，密钥 k=abc时，密文 C=Hfnlpyosnd。
输入
第一行为一个字符串，表示密钥 k，长度不超过 100100，其中仅包含大小写字母。
第二行为一个字符串，表示经加密后的密文，长度不超过 10001000，其中仅包含大小写字母。
输出
输出共 11 行，一个字符串，表示输入密钥和密文所对应的明文。
样例输入
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm

样例输出
Wherethereisawillthereisaway            区分大小写

N=(M+K)mod(26)        N为密文，M为明文，K为密钥
M=(N-K)mod(26)
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	string h;
	cin >> h;
	for (int i = 0; i < h.length(); i++)
	{
		if (h[i] >= 'a' && h[i] <= 'z')
			h[i] = h[i] - 32;   //转换为大写   因为Vigenere的密码表对应的都是大写   CompleteVictory  长度为 15
	}
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			int x = s[i] - 'a';  //忽略参与运算的字母的大小写 但要保持字母在明文的大写形式  Yvqgpxaimmklongnzfwpvxmniytm  长度28
			int y = h[i % h.length()] - 'A';
			s[i] = 'a' + (x - y + 26) % 26;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			int x = s[i] - 'A';   //x=Y - A = 25  对应密文
			int y = h[i % h.length()] - 'A';  // 0%15 = 0  h[0]=C  y=C-A=2
			s[i] = 'A' + (x-y+26) % 26;   // (25-2+26)%26=23    23 + A = W
		}
	}
	for (int i = 0; i < s.length(); i++)
		cout << s[i];
	cout << endl;
}

