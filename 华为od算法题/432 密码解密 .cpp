/*
432�� �������

��Ŀ������
����һ��"����"�ַ���s,�����ַ����Ǿ���"���뱾"ӳ��ģ�����Ҫ��"����"���ܲ������
   ӳ��Ĺ��� ��'a'-'i')�ֱ���('1'-'9')��ʾ��('j'-'z')�ֱ���('10*'-'26*')��ʾ
   Լ����ӳ��ʼ��Ψһ

����������
�����ġ��ַ���

���������
�����ַ���

����˵����
�������ı��ĳ�����100����

ʾ��1
���룺
20*19*20*
�����
tst
˵����
*/

#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	string res;
	//// ����
	//for (auto i : str)
	//{
	//	if (i >= 'a' && i <= 'i')
	//	{
	//		res += to_string((int)(i- 'a' + 1));
	//	}
	//	else {
	//		int tmp = (int)(i - 'a' + 1);
	//		res += to_string(tmp);
	//		res += '*';
	//	}
	//}
	// ����
	queue<int> que;
	for (auto i : str)
	{
		if (i == '*')
		{
			while (que.size() > 2)
			{
				char tmp = que.front() + 'a' - '1';
				que.pop();
				res += tmp;
			}
			int c1 = que.front() - '0'; que.pop();
			int c2 = que.front() - '0'; que.pop();
			int n = c1 * 10 + c2;
			res += 'a' + n - 1;
		}
		else {
			que.push(i);
		}
	}
	while (que.size() != 0)
	{
		char tmp = que.front() + 'a' - '1' + 1;
		que.pop();
		res += tmp;
	}
	cout << res;
}