/*
450�������ַ���������·������

��Ŀ������

���������ַ������ֱ�Ϊ�ַ���A���ַ���B������A�ַ���ΪABCABBA��B�ַ���ΪCBABAC���Եõ���ͼm*n�Ķ�ά���飬����ԭ��Ϊ(0, 0)���յ�Ϊ(m, n)��ˮƽ�봹ֱ��ÿһ���߾���Ϊ1��ӳ�������ϵ����ͼ��

��ԭ��(0, 0)��(0, A)Ϊˮƽ�ߣ�����Ϊ1����(0, A)��(A, C)Ϊ��ֱ�ߣ�����Ϊ1�����������ַ���ͬһλ�õ������ַ���ͬ�������һ��б�ߣ���(A, C)��(B, B)��̾���Ϊб�ߣ�����ͬ��Ϊ1��

�������е�б������ͼ��(0, 0)��(B, B)�ľ���Ϊ 1��ˮƽ�� + 1����ֱ�� + 1��б�� = 3��
���ݶ����֪��ԭ�㵽�յ����̾���·������ͼ���߱�ǣ���̾���Ϊ9��

����������
�ո�ָ�������ַ���A���ַ���B���ַ�����Ϊ���մ������ַ���ʽ�����������[A-Z]���ַ������� < 10000
���������
ԭ�㵽�յ����̾���

ʾ��1
���룺
ABC ABC
�����
3
˵����

ʾ��2
���룺
ABCABBA CBABAC
�����
9
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	vector<vector<int>> map(str1.size()+1, vector<int>(str2.size()+1));
	// ��ʼ��
	for (int i = 0; i <= str1.size(); i++)
	{
		map[i][0] = i;
	}
	for (int j = 0; j <= str2.size(); j++)
	{
		map[0][j] = j;
	}
	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				map[i][j] = min(min(map[i - 1][j], map[i][j - 1]), map[i-1][j-1]) + 1;
			}
			else {
				map[i][j] = min(map[i - 1][j], map[i][j - 1]) + 1;
			}
		}
	}
	/*for (auto i : map)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}*/
	cout << map[str1.size()][str2.size()];
}