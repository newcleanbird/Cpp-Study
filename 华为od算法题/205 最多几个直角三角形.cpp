/*
205����༸��ֱ��������
��Ŀ������
��N���߶Σ����ȷֱ�Ϊa[1]-a[N]����Ҫ���������N���߶���������ϳɼ���ֱ�������Σ�ÿ���߶�ֻ��ʹ��һ�Σ�ÿ�������ΰ��������߶Ρ�

����������
��һ������һ��������T(1 <= T <= 100)����ʾ��T��������ݡ�
����ÿ��������ݣ���������T�У�ÿ�е�һ��������N����ʾ�߶θ�����(3<=N<20)��������N������������ʾÿ���߶γ��ȣ�(0<a[i]<100)��

���������
����ÿ������������һ�У�ÿ�а���һ����������ʾ�������ϵ�ֱ�������θ�����

ʾ��1
���룺
1
7 3 4 5 6 5 12 13
�����
2
˵����
�������2��ֱ�������Σ�3,4,5������5,12,13��

ʾ��2
���룺
1
7 3 4 5 6 6 12 13
�����
1
˵����
�������1��ֱ��������(3,4,5)��(5,12,13)��5ֻ��ʹ��һ�Σ�����ֻ��1����

ʾ��3��
����
3
7 3 4 5 6 5 12 13
7 3 4 5 6 6 12 13
9 3 4 5 5 12 13 7 24 25
���
1
2
3

˼·��������⣬�����ظ�
ʹ�û���/dfs

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int max_triangle(const vector<int>& vec, vector<bool>& used, int index)
{
	int res = 0;
	for (int i = index; i < vec.size(); i++)
	{
		if (used[i]) continue;
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (used[j]) continue;
			for (int k = j + 1; k < vec.size(); k++)
			{
				if (used[k]) continue;
				if (vec[i] * vec[i] + vec[j] * vec[j] == vec[k] * vec[k])
				{
					used[i] = true;
					used[j] = true;
					used[k] = true;
					res = max(res, max_triangle(vec, used, index + 1) + 1);
					used[i] = false;
					used[j] = false;
					used[k] = false;
				}
			}
		}
	}
	return res;
}

int main()
{
	// ����
	int total_test;
	cin >> total_test;
	vector<vector<int>> vec(total_test);
	int tmp;
	vector<int> v_res;
	for (int i = 0; i < total_test; i++)
	{
		int num_size;
		cin >> num_size;
		for (int j = 0; j < num_size; j++)
		{
			cin >> tmp;
			vec[i].push_back(tmp);
		}
		sort(vec[i].begin(), vec[i].end());			// ����
		vector<bool> used(num_size, false);			// ���ʹ������
		int max = max_triangle(vec[i], used, 0);	// ��0��ʼ����
		v_res.push_back(max);
	}

	for (auto i : v_res)
	{
		cout << i << endl;
	}

}