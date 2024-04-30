/*
224�����ֵ���ĩ 200��
��Ŀ������
С����СΪ�Ǻ�Ҫ�õ����ѣ�����Լ����ĩһ��Է���ͨ���ֻ������������ڵ�ͼ��ѡ���˶���۲͵ص㣨������Ȼ���ε�ԭ�򣬲��־۲͵ص㲻�ɴ����С����СΪ���ܵ���ľ۲͵ص��ж��ٸ���

����������
��һ������m��n��m�����ͼ�ĳ��ȣ�n�����ͼ�Ŀ�ȡ�
�ڶ��п�ʼ���������ͼ��Ϣ����ͼ��Ϣ������
0 Ϊͨ���ĵ�·
1 Ϊ�ϰ���ҽ�1Ϊ�ϰ��
2 ΪС������СΪ����ͼ�бض����ҽ���2�� �����ϰ��
3 Ϊ��ѡ�еľ۲͵ص㣨���ϰ��

���������
���Ա�����������ľ۲͵ص���������ĩ�޿ո�
����˵����
��ͼ�ĳ���Ϊm��n�����У�
4 <= m <= 100
4 <= n <= 100
�۲͵ĵص�����Ϊ k����
1< k <= 100

ʾ��1
���룺
4 4
2 1 0 3
0 1 2 1
0 3 0 0
0 0 0 0
�����
2
˵����
��һ�������ͼ�ĳ���Ϊ3��4��
�ڶ��п�ʼΪ����ĵ�ͼ�����У�3����С����С��ѡ��ľ۲͵ص㣻2����С������С����ȷ����2������0�������ͨ�е�λ�ã�1��������ͨ�е�λ�á�
��ʱ�����ܶ��ܵ���ľ۲�λ����2��

ʾ��2
���룺
4 4
2 1 2 3
0 1 0 0
0 1 0 0
0 1 0 0
�����
0
˵����
��һ�������ͼ�ĳ���Ϊ4��4��
�ڶ��п�ʼΪ����ĵ�ͼ�����У�3����С����С��ѡ��ľ۲͵ص㣻2����С������С����ȷ����2������0�������ͨ�е�λ�ã�1��������ͨ�е�λ�á�
����ͼ��С����СΪ֮���и��������ʱ��û�����˶��ܵ���ľ۲͵�ַ���ʶ�����0
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int m, n; // m�����ͼ�ĳ��ȣ�n�����ͼ�Ŀ�ȡ�

// ����������
struct point2
{
	int x;
	int y;
};

// �����ĸ�������ƶ�����
const vector<pair<int, int>> DIRECTIONS = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void if_reach(const vector<vector<int>>& map, vector<vector<bool>>& visited, const point2& start)	// �жϴ�x1,y2 -> x2,y2�Ƿ�ɴ�
{
	queue<point2> q;
	// vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));	// ��¼�ѷ��ʵĽڵ�
	// ��ʼ��
	q.push({ start.x, start.y });
	visited[start.x][start.y] = true;

	while (!q.empty())
	{
		point2 current = q.front(); q.pop();	// �Ӷ��г��ӵ�ǰ�����Ľڵ�
		for (auto i : DIRECTIONS)
		{
			int newX = current.x + i.first;
			int newY = current.y + i.second;
			if (newX >=0 && newX < n && newY >=0 && newY < m && map[newX][newY] != 1 && visited[newX][newY] == false)	// �����Ľڵ�ɴ���δ����
			{
				q.push({ newX, newY });
				visited[newX][newY] = true;
			}
		}
	}
}

int main()
{
	cin >> m >> n;
	vector<vector<int>> map(n, vector<int>(m));			// �ܵĵ�ͼ
	vector<point2> restaurant;	// ����
	vector<point2> people;		// С����СΪ��λ��
	/*  0 Ϊͨ���ĵ�·
		1 Ϊ�ϰ���ҽ�1Ϊ�ϰ��
		2 ΪС������СΪ����ͼ�бض����ҽ���2�� �����ϰ��
		3 Ϊ��ѡ�еľ۲͵ص㣨���ϰ��*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 3)
			{
				restaurant.push_back({ i, j });
			}
			if (map[i][j] == 2)
			{
				people.push_back({ i, j });
			}
		}
	}
	//bfs����
	vector<vector<bool>> if_reach_1(n, vector<bool>(m, false));
	vector<vector<bool>> if_reach_2(n, vector<bool>(m, false));
	if_reach(map, if_reach_1, people[0]);
	if_reach(map, if_reach_2, people[1]);

	// �ж�
	int res = 0;
	for (auto i : restaurant)
	{
		if (if_reach_1[i.x][i.y] && if_reach_2[i.x][i.y]) res++;
	}
	cout << res;





}