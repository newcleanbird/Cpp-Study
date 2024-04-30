/*
422�����Բ�����Ⱦ
��Ŀ������
һ�����������кܶ�̨���ԣ��ֱ��עΪ 1 - N �����֡������ӵĵ��Ծ��벻һ�������Ը�Ⱦʱ�䲻һ������Ⱦʱ����t��ʾ��
����������һ�����Ա�������Ⱦ�����Ⱦ���������еĵ�����Ҫ������Ҫ�೤ʱ�䡣�������е��Բ����Ⱦ���򷵻�-1
����һ������times��ʾһ�����԰����ڵ��Ը�Ⱦ���õ�ʱ�䡣
��ͼ��path[i]= {i,j, t} ��ʾ����i->j ����i�ϵĲ�����Ⱦj����Ҫʱ��t��

����������
4
3
2 1 1
2 3 1
3 4 1
2
���������
2
����˵����
��һ������:�������ڵ��Ը���N 1<=N<=200;
�ڶ����������ܹ���������������
������ 1 2 1 ��ʾ1->2ʱ��Ϊ1
�����У���ʾ�����ʼ���ڵĵ��Ժ�1

ʾ��1
���룺
4
3
2 1 1
2 3 1
3 4 1
2
�����
2
˵����

˼·��Dijkstra ��Դ���·��
*/
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include <climits>

using namespace std;

//�����������
int const INF = INT_MAX;

int dijstra(int start, vector<vector<int>>& map) {
    int n = map.size()-1;   // n���ڵ�
    vector<int> dis(n + 1, INT_MAX);    // ��ǰ�����
    vector<bool> vis(n + 1, false);     // �Ƿ���ʱ�
    dis[start] = 0;                     // ��ʼ����������Ϊ0
    for (int i = 1; i <= n; i++) {
        int minn = INT_MAX;
        int u = -1; 
        for (int j = 1; j <= n; j++) {  // ����Сδ�����ʵ�dist[j]
            if (!vis[j] && dis[j] < minn) { // jδ���������·����
                minn = dis[j];
                u = j;  // u�洢�ҵ��ĵ�ǰ����Ľڵ�
            }
        }
        if (u == -1) break; // δ�ҵ��µı����㷨����
        vis[u] = true;  // ���ҵ��Ľڵ���Ϊ�ѷ���
        for (int j = 1; j <= n; j++) {  // ����dist[j]
            if (!vis[j] && map[u][j] != INF && dis[u] + map[u][j] < dis[j])  // �ڵ�jδ���ʣ���
            {
                dis[j] = dis[u] + map[u][j];
                // dis[j] = min(dis[j], dis[u] + map[u][j]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == INF)
        {
            return -1;
        }
        else {
            res = max(res, dis[i]);
        }
    }
    return res;
}

int main()
{
	int n;      //���Ը���N
	int size;   //�ܹ���������������
	cin >> n >> size;
	vector<vector<int>> network(n+1, vector<int>(n+1, INF));    // �ڵ�����1~n
	for (int i = 0; i < size; i++)
	{
		int x, y, val;
		cin >> x >> y >> val;
		network[x][y] = val;
	}
	int start;	// �������ڵĵ��ԣ���Dijkstra�㷨����ʼ��
	cin >> start;
	// ����
	int res = dijstra(start, network);
	cout << res;
}

