/*
324 �ַ���ժҪ
һ����Ŀ����
����һ���ַ�����ժҪ�㷨������������ַ�����ժҪֵ��

ȥ���ַ����з���ĸ�ķ��ţ�
������������ַ��������ִ�Сд������������ַ���Сд��+ �������ֵĴ�����
����Ƿ��������ַ��������ִ�Сд������������ַ���Сд��+ ����ĸ֮���ַ����г��ָ��ַ��Ĵ�����
�԰������Ϸ�ʽ��ʾ����ַ�������������ĸ�ͽ����������Ϊһ������������ִ����ǰ��������ͬʱ������ĸ����������ĸС����ǰ��

������������
һ���ַ�����

�����������
ժҪ�ַ�����

�ġ�������
��������:
���ַ���������Ϊ[1,200]

�������:
ժҪ�ַ���

ʾ��һ��
����:
aabbcc
���:
a2b2c2
˵��:
��һ��b��������ĸ������ĸ֮���ַ����л�������2�� (��������Bb) ���������b2a��������3�Σ����a3��c������������ĸ֮���ַ�����û�г��ֹ�c�����c0Bb����2�Σ����b2����b2a3c0b2���������������a3b2b2c0

ʾ������
���룺
bAaAcBb
�����
a3b2b2c0
˵����
bAaAcBb��
��һ�� b ��������ĸ������ĸ֮���ַ����л������� 2 �Σ��������� Bb����������� b2��
a �������� 3 �Σ���� a3��
c ������������ĸ֮���ַ�����û�г��ֹ� c����� c0
Bb ���� 2 �Σ���� b2
�� b2a3c0b2 ��������������� a3b2b2c0

ʾ������
CbAaAcBbA
a3b2b2c1a0c0

�塢����˼·
1������˼·��
�����ǰ��ĸ����һ����ĸ��ͬ������ĸ����������Ϊ+1��
�����ǰ��ĸ����һ����ĸ��ͬ��
�����ǰ�ַ���������������1����ʾ�������ַ���������ɣ�
���ֻ��1������Ҫ��ȡ�����ַ����и��ַ��ĸ�����
��ĸ�ͽ����������Ϊһ������������ִ����ǰ��������ͬʱ������ĸ����������ĸС����ǰ��
2������˼·���£�
����һ���ַ����������ִ�Сд��
����һ������c
*/

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<char, int> p1, pair<char, int> p2)
{
	if (p1.second == p2.second)
	{
		return p1 < p2;
	}
	else
	{
		return p1.second > p2.second;
	}
	
}

int main()
{
	string str;
	getline(cin, str);
	// ȥ���ַ����еķ���ĸ
	string str_1;
	for (int i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]))
		{
			str_1 += tolower(str[i]);
		}
	}
	map<char, int> char_conut_map;
	vector<pair<char, int>> vec;
	char currentChar = str_1[str_1.size()-1];
	int count = 1;
	for (int i = str_1.size() - 2; i >= 0; i--)
	{
		if (str_1[i] == currentChar)	// ������ϸ���ĸ��ͬ����������ĸͳ��
		{
			count++;	// ��ͬ���֣�����+1
		}
		else {
			if (count == 1)	// ��ǰ�ַ����¸��ַ���ͬ�����¸��ַ��ǵ����ַ�����ʱӦ�ý��¸��ַ��Ľ����������
			{
				count = char_conut_map[currentChar];				// ��ѯͳ������
				char_conut_map[currentChar] += count + 1;			// ����ͳ������
				vec.push_back(pair<char, int>(currentChar, count));	// ��������
			}
			else {	// ͳ��������ĸ�ĸ���
				char_conut_map[currentChar] += count;
				vec.push_back(pair<char, int>(currentChar, count));	// ��֮ǰ��������ĸ��������
			}
			// ��ʼ��ͳ�Ƽ�¼
			currentChar = str_1[i];
			count = 1;
		}
		if (i == 0)	// �����һ�εļ�¼��������
		{
			if (count == 1)	// �������ַ�
			{
				count = char_conut_map[str_1[i]];					// ��ѯͳ������
			}
			vec.push_back(pair<char, int>(str_1[i], count));	// ��������
		}
	}
	sort(vec.begin(), vec.end(), compare);
	for (auto i : vec)
	{
		cout << i.first << i.second;
	}


}