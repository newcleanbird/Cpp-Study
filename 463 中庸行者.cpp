/*
463 ��ӹ����
��Ŀ����
����һ��m*n������������Ϊ��ͼ��������ֵΪ���θ߶���ӹ����ѡ���ͼ�е�����һ����Ϊ��㣬�������ϡ��¡������ĸ����ڸ����ƶ�:�ƶ�ʱ������Լ��:
��ӹ����ֻ�����»������£������ߵ��߶���ͬ�ĵ�
�������������»����������£���Ҫ�������
ÿ��λ��ֻ�ܾ���һ�Σ������ظ�����
�������ӹ�����ڱ���ͼ�ڣ��������ƶ�����������

��������
һ��ֻ���������Ķ�ά����
2 2
1 2
4 3
˵����
��һ���������֣��ֱ�Ϊ������ÿ�е�����
��������Ϊ�����ͼ����:
����߳���Χ:[1,8]
���θ߶ȷ�Χ:[0,10^6]

�������
һ��������������ӹ�����ڱ���ͼ�ڣ��������ƶ�����������

����1
����
2 2
1 2
4 3
���
3
˵����3>4>1>2

����2
����
3 3
1 2 4
3 5 7
6 8 9

���
4

˵����6>3>5>2>4
*/
#include<iostream>
#include<vector>

using namespace std;

int res = 0;

vector<int> dx = { -1, 1, 0, 0 }, dy = {0, 0, -1, 1};
void dfs(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& b_map, int count, int dir)
{
	// ���½��
	res = max(res, count);

	b_map[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int a = dx[i] + x, b = dy[i] + y;
		if (a >= 0 && a < map.size() && b >= 0 && b < map[0].size() && b_map[a][b] == false && map[a][b] != map[x][y])
		{
			int cur_dir = map[a][b] > map[x][y];
			if (cur_dir != dir)
			{
				dfs(a, b, map, b_map, count+1, cur_dir);
			}
		}
	}
	// ����
	b_map[x][y] = false;
}

int main()
{
	// ����
	int n, m;	// ����������
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			vector<vector<bool>> b_map(n, vector<bool>(m, false));
			dfs(i, j, map, b_map, 0, -1);
		}
	}
	cout << res;
}