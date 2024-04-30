/*
464�� �����С���Ӿ�����С������
��Ŀ������
����һ�����󣬰���N*M����������һ������K�����������顣
����Ҫ���������������һ�������С���Ӿ���Ҫ���Ӿ���������������е�������

����������
��һ����������������N��M����ʾ�����С��
������N��M�б�ʾ�������ݡ�
��һ�а���һ��������K��
��һ�а���K����������ʾ������������飬K���������ܴ����ظ�����
������������С��1000��

���������
�������һ����������ʾ����Ҫ���Ӿ������С��ȣ����Ҳ��������-1.

����˵����
ʾ��1
���룺
2 5
1 2 2 3 1
2 3 2 3 2
3
1 2 3
�����
2
˵����
�����0��3�а�����1��2��3�������3��4�а�����1��2��3

ʾ��2
���룺
2 5
1 2 2 3 1
1 3 2 3 4
3
1 1 4
�����
5
˵����
�����1��2��3��4��5�а�����1��1��4

˼·�������С,��������ľ���
*/
#include<iostream>
#include<vector>
#include<map>

using namespace std;

bool check(map<int, int>& cur_map, map<int, int>& target)
{
	for (auto& i : target)
	{
		if (cur_map[i.first] < i.second)	// �������С��Ŀ��ֵ
		{
			return false;
		}
	}
	return true;
}

int main()
{
	// ����
	int n, m;	// N��M��
	cin >> n >> m;
	vector<vector<int>> vec(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> vec[i][j];
		}
	}
	int k;
	cin >> k;
	map<int, int> target;
	for (int i = 0; i < k; i++)
	{
		int tmp;
		cin >> tmp;
		target[tmp]++;
	}
	map<int, int> cur_map;	// ��ϣ��¼��ǰ��Ҫ������
	for (auto& i : target)
	{
		cur_map[i.first] = 0;
	}

	// �����������
	int min_length = m + 1;
	int l = 0;
	for(int r = 0; r < m; r++)
	{
		// ��������
		for (int i = 0; i < n; i++)
		{
			if (target.find(vec[i][r]) != target.end())
			{
				cur_map[vec[i][r]]++;	// ��¼����
			}
		}
		// �ж��Ƿ������Ҫ������߽粢�ռ�����
		while (check(cur_map, target))
		{
			// �ȸ�����С����
			min_length = min(min_length, r - l + 1);
			cout << "����������l��r:" << l << " " << r << endl;

			// ������߽�
			for (int i = 0; i < n; i++)
			{
				if (target.find(vec[i][l]) != target.end())
				{
					cur_map[vec[i][l]]--;	// ��¼����
				}
			}
			l++;
		}
	}
	cout << min_length;
}