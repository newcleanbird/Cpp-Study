/*
038 ȫ������ռ���ַ���.cpp

��Ŀ����
���������ַ����ϣ�һ����ȫ���ַ�����һ������ռ���ַ�������ռ���ַ����е��ַ�������ʹ�á�
Ҫ�����ʣ������ַ�����

��������
����һ���ַ��� һ������@��@ǰΪȫ���ַ��� @���Ϊ��ռ���ַ���
��ռ���ַ����е��ַ�һ����ȫ���ַ����е��ַ�
�ַ����е��ַ����ַ�֮��ʹ��Ӣ�Ķ��Ÿ���
ÿ���ַ�����ʾΪ�ַ�+���ֵ���ʽ��Ӣ��ð�ŷָ�������a:1��ʶһ��a�ַ�
�ַ�ֻ����Ӣ����ĸ�����ִ�Сд
����ֻ���������� ������100
���һ���ַ���û��ռ�� @��ʶ�Դ��ڣ����� a:3,b:5,c:2@

�������
��������ַ���
��ͬ������ַ���֮���ûس�����
ע�� ������ַ�˳��Ҫ�������һ�£������������������b:3,a:2,c:2
���ĳ���ַ���ȫ��ռ�� ����Ҫ�����

����
����
a:3,b:5,c:2@a:1,b:2

���
a:2,b:3,c:2

˵��
ȫ���ַ���Ϊ����a��5��b��2��c
��ռ���ַ���Ϊ1��a��2��b
������ռ���ַ�������ʹ��
���ʣ������ַ�Ϊ2��a��3��b��2��c
������a:2,b:3,c:2

*/



#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
	// ����
	string str;
	getline(cin, str);

	// �ָ��ַ��������δ���
	int seq = str.find('@');
	string str1 = str.substr(0, seq) + ',';
	string str2 = str.substr(seq+1) + ',';

	unordered_map<string, int> ump;
	string t_str;
	int t_i = 0;
	seq = 0;
	// ����
	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] == ':')
		{
			t_str = str1[i - 1];
			seq = i;
		}
		if (str1[i] == ',')
		{
			//string s = str1.substr(seq, i - seq - 1);
			t_i = stoi(str1.substr(seq+1, i - seq - 1));
			ump.insert(pair<string, int>(t_str, t_i));
		}
	}

	// ɾ��
	t_i = 0;
	seq = 0;
	for (int i = 0; i < str2.size(); i++)
	{
		if (str2[i] == ':')
		{
			t_str = str2[i - 1];
			seq = i;
		}
		if (str2[i] == ',')
		{
			t_i = stoi(str2.substr(seq+1, i - seq - 1));
			ump[t_str] -= t_i;
		}
	}

	for (auto i : ump)
	{
		cout << i.first << ":" << i.second << ",";
	}
} 