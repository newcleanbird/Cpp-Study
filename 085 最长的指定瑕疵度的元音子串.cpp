/*
���ָ��覴öȵ�Ԫ���Ӵ�

��Ŀ������
��ͷ�ͽ�β����Ԫ����ĸ��aeiouAEIOU�����ַ���Ϊ Ԫ���ַ��� �����л��ӵķ�Ԫ����ĸ����Ϊ�� 覴ö� ������:
��         ��a�� �� ��aa����Ԫ���ַ�������覴öȶ�Ϊ0
��         ��aiur������Ԫ���ַ�������β����Ԫ���ַ���
��         ��abira����Ԫ���ַ�������覴ö�Ϊ2
����һ���ַ��������ҳ�ָ��覴öȵ��Ԫ���ַ��Ӵ���������䳤�ȣ�����Ҳ�������������Ԫ���ַ��Ӵ������0��
�Ӵ����ַ�����������������ַ���ɵ������г�Ϊ���ַ������Ӵ���

����������
����������һ����������ʾԤ�ڵ�覴ö�flaw��ȡֵ��Χ[0, 65535]��
������һ����һ�������ַ�a-z��A-Z��ɵ��ַ������ַ�������(0, 65535]��

���������
���Ϊһ����������������������Ԫ���ַ��Ӵ��ĳ��ȡ�

����˵����

ʾ��1
���룺
0
asdbuiodevauufgh
�����
3
˵����
�����������Ԫ���ַ��Ӵ����������ֱ�Ϊuio��auu������Ϊ3��

ʾ��2
���룺
2
aeueo
�����
0
˵����
û������������Ԫ���ַ��Ӵ������0

ʾ��3
���룺
1
aabeebuu
�����
5
˵����
�����������Ԫ���ַ��Ӵ����������ֱ�Ϊaabee��eebuu������Ϊ5

˼·��ֱ������forѭ���������
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool is_vowel(char ch)
{
	vector<int> vowel{ 'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	if (find(vowel.begin(), vowel.end(), ch) != vowel.end())
	{
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	int flaw;	// ���Ҷ�
	string str;	// �����ַ���
	cin >> flaw;
	cin.get();
	getline(cin, str);
	vector<int> vec(str.size());
	for (int i = 0; i < str.size(); i++)
	{
		if (is_vowel(str[i]))
		{
			vec[i] = 0;
		}
		else {
			vec[i] = 1;
		}
	}
	int max = 0;
	int left = 0;
	int right = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == 0)
		{
			int count = 0;
			for (int j = i + 1; j < vec.size(); j++)
			{
				if (vec[j] == 1)
				{
					count++;
				}
				if (count == flaw)
				{
					max = max < (j - i + 1) ? (j - i + 1) : max;
				}
			}
		}
	}
	cout << max;
}