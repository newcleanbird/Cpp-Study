/*
444��������ռ��ʱ��
��Ŀ��
�������ɸ����飬���л��鹲��һ�������ң��������ʾ��������Ŀ�ʼʱ��ͽ���ʱ�䣬��ʽΪ:
[[����1��ʼʱ�䣬����1����ʱ��]��[����2��ʼʱ�䣬����2����ʱ��]]
����������ռ��ʱ��Ρ�

��������
[[����1��ʼʱ�䣬����1����ʱ��]��[����2��ʼʱ�䣬����2����ʱ��]]

��ע
�����Ҹ�����Χ: [1,100]
������ʱ���: [1,24]

�������
�����ʽԤ����һ��,�����뿴����
[[���鿪ʼʱ�䣬�������ʱ��]��[���鿪ʼʱ�䣬�������ʱ��]]

ʾ��1
����:
[[1,4], [2,5],[7,9], [14,18]]
���
[[1,5], [7,9],[14,18]]
˵��:
ʱ���[1,4]��[2,5]�ص����ϲ�Ϊ[1,5]

ʾ��2
����:
[[1,4],[4,5]]
���:
[[1,5]]
����Ϊleetcodeģʽ��ʵ�ָ����ĺ������ɡ�
int[][] merge(int[][] roomTimes) {

˼·���鲢Leetcode 56. �ϲ�����
�ȶ����жΰ���˵����򣬱�֤������Ķε���˵�С���ȱ�������˵㣬Ȼ��ֻ��Ҫ�жϵ�ǰ�����Ķε���˵��Ƿ��merge�õĶ��е��Ҷ˵�С���ɡ�
}
*/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
	if (a[0] != b[0])
	{
		return a[0] < b[0];
	}
	else {
		return a[1] < b[1];
	}
}

int main()
{
	/*string str;
	getline(cin, str);*/
	vector<vector<int>> rooms = { {1,4},{2,5}, {7,9}, {14,18} };
	/*queue<int> q;
	for (auto i : str)
	{
		if (isdigit(i))
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
		rooms.push_back(vector<int>{a, b});
	}*/

	// ����
	sort(rooms.begin(), rooms.end(), cmp);
	vector<vector<int>> merge;
	for (int i = 0; i < rooms.size(); i++)
	{
		int l = rooms[i][0];
		int r = rooms[i][1];
		if (merge.empty() || merge.back()[1] < l)
		{
			merge.push_back({ l, r });
		}
		else {
			merge.back()[1] = max(merge.back()[1], r);
		}
	}
	for (int i = 0; i < merge.size(); i++)
	{
		if (i == 0) cout << "[";
		if (i > 0) cout << ",";
		cout << "[" << merge[i][0] << "," << merge[i][1] << "]"; 
		if (i == merge.size() - 1) cout << "]";
	}

}