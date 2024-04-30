/*
402����Ŀ��������һ�����У�ÿ���ڵ����һ����ͥ��Ա���ڵ�����ֱ�ʾ����˵ĲƸ�ֵ��һ���ڵ㼰��ֱ���������ӽڵ㱻����Ϊһ��С��ͥ��
�ָ���һ�������������ԣ��С��ͥ�ĲƸ��͡�
������������һ��Ϊһ����N����ʾ��Ա��������Ա���1-N��1<=N<=1000
�ڶ���ΪN���ո�ָ���������ʾ���1-N�ĳ�Ա�ĲƸ�ֵ��0<=�Ƹ�ֵ<=1000000
������N-1�У�ÿ�������ո�ָ�������(N1,N2)����ʾN1��N2�ĸ��ڵ㡣
���������
�ԣ��С��ͥ�ĲƸ���
����˵����

ʾ��1
���룺
4
100 200 300 500
1 2
1 3
2 4
�����

700
˵����
��Ա1,2,3��ɵ�С��ͥ�Ƹ�ֵΪ600
��Ա2,4��ɵ�С��ͥ�Ƹ�ֵΪ700

ʾ��2
���룺
4
100 200 300 500
1 2
1 3
1 4
�����
1100
˵����
��Ա1,2,3,4��ɵ�С��ͥ�Ƹ�ֵΪ1100

˼·��
����Ӧ����ô�Ҽ�ͥ��
�������һ����Ǯ
����������ͥ��ϵ

*/
#include<iostream>
#include<vector>

using namespace std;

// û����
struct mem
{
	int num;
	int father;
	int wealth;
};

int main()
{
	int n;
	cin >> n;
	int num = n;
	vector<int> wealth(n+1, 0);
	int tmp;
	for(int i = 1; i <= n; i++)
	{
		cin >> tmp;
		wealth[i] = tmp;
	}
	vector<int> father(n+1, 0);
	int fa, me;
	for(int i = 1; i < n; i++)
	{
		cin >> fa >> me;
		father[me] = fa;
	}
	vector<int> result(n, 0); // ������ÿ����Ϊ���׵ļ�ͥ��Ǯ
	int max_family_wealth = 0;
	for (int i = 1; i <= n; i++)
	{
		int family_wealth = 0;
		family_wealth += wealth[i];
		for (int j = 1; j <= n; j++)
		{
			if (i == father[j])	// ����ýڵ�ĸ�����i����˵����ͬһ����
			{
				family_wealth += wealth[j];
			}
		}
		max_family_wealth = max_family_wealth > family_wealth ? max_family_wealth : family_wealth;
	}
	cout << max_family_wealth;
	
}