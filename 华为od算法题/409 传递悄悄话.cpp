/*
409���������Ļ�
��Ŀ������
����һ����������ÿ���ڵ���վ��һ���ˣ��ڵ����ֱ�ʾ���ڵ㵽�ýڵ㴫�����Ļ���Ҫ���ѵ�ʱ�䡣
��ʼʱ�����ڵ�����λ�õ�����һ�����Ļ���Ҫ���ݸ������ˣ�����������нڵ��ϵ��˶����յ����Ļ����ѵ�ʱ�䡣

����������

����������

0 9 20 -1 -1 15 7 -1 -1 -1 -1 3 2

ע��-1��ʾ�սڵ�

���������

�������нڵ㶼���յ����Ļ����ѵ�ʱ��38

����˵����

ʾ��1

���룺

0 9 20 -1 -1 15 7 -1 -1 -1 -1 3 2
�����

38
˵����

*/
#include<iostream>
#include<vector>

using namespace std;

int res = 0;

void dfs(vector<int>& btree, int sum, int index)
{
	if (index >= btree.size() || btree[index] == -1)
	{
		return;
	}
	res = max(res, sum + btree[index]);
	dfs(btree, sum + btree[index], index * 2 + 1);	// ������
	dfs(btree, sum + btree[index], index * 2 + 2);	// ������
}

int main()
{
	// ����
	vector<int> btree;
	int tmp;
	while (cin >> tmp)
	{
		btree.push_back(tmp);
		if (cin.peek() == '\n') break;
	}
	dfs(btree, 0, 0);
	cout << res;


}