/*
428 ������ĸ����
��Ŀ����
����һ���ַ�����ֻ������д��ĸ�����ڰ���ͬһ����ĸ���Ӵ��У�
���ȵ�k�����Ӵ��ĳ��ȣ���ͬ��ĸֻȡ����Ǹ��Ӵ���
���Ӵ���ֻ����ͬһ����ĸ���Ӵ���С��k�������-1.

����������
��һ����һ���ַ�����1 < ���� < 100����ֻ������д��ĸ
�ڶ�����һ�����֣���ʾk��ֵ

���������
����������ִ�����k�����ĸ�Ĵ���

ʾ��1��
����
AAAAHHHBBCDHHHH
3
���
2
˵��
ͬһ��ĸ�������ֵ�������A��H��4�Σ�
�ڶ������H��3�Σ�����H�Ѿ�����4���������ˣ��ʲ��ٿ��ǣ�
�¸�����Ӵ���BB���䳤��Ϊ2���������մ�Ӧ�����2

ʾ��2��
����
AABAAA
2
���
1
˵��
ͬһ��ĸ�������ֵ�������A��3�Σ�
�ڶ���Ļ���A�����Σ�����A�Ѿ����ֹ��ˣ��ʲ����ǣ�
�ڶ�����Ӵ���B�����ĳ�����1���������1

ʾ��3��
����
ABC
4
���
-1
˵��
ֻ����3������ͬһ����ĸ���Ӵ���С��k�����-1

ʾ��4��
����
ABC
2
���
1
˵��
�����Ӵ����Ⱦ�Ϊ1�����Դ�ʱk=1��k=2��k=3��������������1

����˼·
1.�û��������������ĸ�����������Ը������齵�����������k��ֵ
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

//bool cmp(pair<char, int>& a, pair<char, int>& b)
//{
//	return a.second > b.second;
//}

int main()
{
	// ����
	string str;
	getline(cin, str);
	int k;
	cin >> k;
	map<char, int> map;
	char last_char = str[0];
	int length = 1;
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] != last_char)
		{
			// �ռ���
			if (map[last_char] == 0)
			{
				map[last_char] = length;
			}
			else {
				if (map[last_char] < length)
				{
					map[last_char] = length;
				}
			}
			// ��ʼ��
			last_char = str[i];
			length = 1;
		}
		else {
			length++;
		}
	}
	vector<int> vec;
	for (auto i : map)
	{
		vec.push_back(i.second);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	// ������
	if (vec.size() < k)
	{
		cout << -1;
	}
	else {
		cout << vec[k - 1];
	}
}