///*
//431����������
//��Ŀ������
//��������(�����й�����͹�������)�е����ӣ��߷���ÿ��ֱһ����бһ�񣬼��Ⱥ��Ż�ֱ����һ��Ȼ����б����һ���Խ��ߣ��ɽ����ˣ���Խ���ӽ磬�׳ơ����ߡ��ա��֡�
//����m��n�е����̣�����ͼ����������ֻ�������������е����ӡ���������ÿ�������еȼ�֮�֣��ȼ�Ϊk���������1~k�����ߵķ�ʽ�������С����Ĺ���һ���������Գ�������λ�ã������Ƿ��ܽ�����������ͬһλ�ã�������ڣ����������Ҫ���ܲ�����ÿƥ��Ĳ�����ӣ��������������-1��
//ע������ͬ���������Ĺ���������ͬһλ�ã�����Ϊ(x,y)������һ�ο�������������Ϊ(x+1, y+2), (x+1, y-2), (x+2, y+1), (x+2, y-1), (x-1, y+2), (x-1, y-2), (x-2, y+1), (x-2, y-1),�ĸ���ϣ����ǲ����Գ������̷�Χ��
//
//����������
//��һ������m,n����m��n�е�����ͼ����(1 �� m, n �� 25)��
//����������m��n�е�����ͼ���̣������i��,��j�е�Ԫ��Ϊ��.������˸��û�����ӣ����Ϊ����k��1<=k<=9��������˸����ڵȼ�Ϊk�ġ�����
//
//���������
//���������Ҫ���ܲ�����ÿƥ��Ĳ�����ӣ��������������-1��
//
//����˵����
//ʾ��1
//���룺
//3 2
//..
//2.
//..
//�����
//0
//˵����
//ֻ��һƥ������Ҫ����
//
//ʾ��2
//���룺
//3 5
//47.48
//4744.
//7....
//�����
//17
//˵����
//
//0,0 1,2 2,1 3,3
//*/
//#include<iostream>
//#include<vector>
//#include<string>
//#include<queue>
//
//using namespace std;
//
//vector<int> x_inc = { 1, 2, 2, 1, -1, -2, -2, -1,  };
//vector<int> y_inc = { 2, 1,-1,-2, -2, -1,  1,  2,  };
//
//struct Chess
//{
//	int x;
//	int y;
//	int k;
//	Chess(int x, int y, int k) : x(x), y(y), k(k)
//	{
//
//	}
//};
//
//void bfs(const vector<vector<int>>& map, vector<vector<int>>& vis, Chess start, int n)	// bΪ��ǰ���Ĳ���
//{
//	queue<Chess> q;
//	q.push({start.x, start.y, 0});
//	while (!q.empty())
//	{
//		// ����
//		Chess cur = q.front(); q.pop();
//		// �Ըýڵ���в���
//		vis[cur.x][cur.y] = cur.k;	// ��Ǹýڵ���Ҫ������Ծ����
//		for (int i = 0; i < 8; i++)
//		{
//			int x = cur.x + x_inc[i];
//			int y = cur.y + y_inc[i];
//			if (x >= 0 && x < map.size() && y >= 0 && y < map[0].size() && vis[x][y] == -1) // δԽ��,δ����
//			{
//				if (cur.k + 1 > n) continue;
//				Chess tmp = { x, y, cur.k + 1 };
//				q.push(tmp);
//			}
//		}
//	}
//}
//
//int main()
//{
//	// ����
//	int m, n; // m��n�е�����ͼ����
//	cin >> m >> n;
//	cin.get();
//	vector<vector<int>> map(m, vector<int>(n));
//	int chess_num = 0; // ��¼ͼ���ж�������
//	vector<Chess> chesses;
//	for (int i = 0; i < m; i++)
//	{
//		string str;
//		getline(cin, str);
//		int j = 0;
//		for (int j = 0; j < str.size(); j++)
//		{
//			if (str[j] == '.')
//			{
//				map[i][j] = 0;
//			}
//			else {
//				map[i][j] = str[j] - '0';
//				chess_num++;
//				chesses.push_back(Chess(i, j, map[i][j]));
//			}
//		}
//	}
//
//	vector<vector<vector<int>>> vis(chess_num, vector<vector<int>>(m, vector<int>(n, -1)));	// �洢�Ƿ�ɴ�
//	for (int i = 0; i < chesses.size(); i++)
//	{
//		bfs(map, vis[i], chesses[i], chesses[i].k);
//	}
//	
//	// ͳ��
//	vector<vector<int>> res(m, vector<int>(n, 0));
//	for (auto& chess : vis)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (res[i][j] == -1)
//				{
//					continue;
//				}
//				if (chess[i][j] == -1)	// �������ڸõ㲻�ɴ�
//				{
//					res[i][j] = -1;
//				}
//				else {
//					res[i][j] += chess[i][j];
//				}
//			}
//		}
//	}
//	int count = 0;
//	int minn = INT_MAX;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (res[i][j] != -1)
//			{
//				count++;
//				minn = min(minn, res[i][j]);
//			}
//
//		}
//	}
//
//	if (count == 0)
//	{
//		cout << -1;
//	}
//	else {
//		cout << minn;
//	}
//
//}