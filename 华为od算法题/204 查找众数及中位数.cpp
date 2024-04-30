/*
��Ŀ��
������ָһ�������г��ִ���������Ǹ��������������Ƕ����
��λ����ָ��һ�����ݴ�С�������У����м���Ǹ���������������ݵĸ����������������м��Ǹ�������λ��������������ݵĸ���Ϊż�����ǾͰ��м��������֮�ͳ���2�����õĽ��������λ����

��������������Ԫ�ص����������һ���µ����飬�����������λ����
��������
����һ��һά�������飬�����Сȡֵ��Χ
0��N��1000��������ÿ��Ԫ��ȡֵ��Χ
0��E��1000

�������
���������ɵ����������λ��

ʾ��1
�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
10 11 21 19 21 17 21 16 21 18 15
���
21

ʾ��2
�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
2 1 5 4 3 3 9 2 7 4 6 2 15 4 2 4
���
3

ʾ��3
�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
5 1 5 3 5 2 5 5 7 6 7 3 7 11 7 55 7 9 98 9 17 9 15 9 9 1 39
���
7
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include <numeric> 

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second > p2.second;
}

int main()
{
	map<int, int> imap;
	int tmp;
	while (cin >> tmp)
	{
		imap[tmp]++;
		if (cin.get() == '\n') break;
	}
	vector<pair<int, int>> vec(imap.begin(), imap.end());
	sort(vec.begin(), vec.end(), cmp);
	
	vector<int> res;
	int max = (*vec.begin()).second;
	for (auto i : vec)
	{
		if (i.second == max)
		{
			res.push_back(i.first);
		}
	}
	cout << accumulate(res.begin(), res.end(), 0) / res.size();
}