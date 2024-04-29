/*
462�� ��ĥ�����ߺ���͵�Ӳ��
��Ŀ����
�洢������ʹ�õ�һ����̬Ӳ�̣�����Ӳ��ĥ��ֵ����һ������endurances,������ÿ��Ԫ�ر�ʾ����Ӳ�̵�ĥ���(0��10000֮��)��ĥ���Խ�󣬱�ʾ������Ҫ�����ĸ���Խ�ߡ���Ҫ�ҳ�ĥ�������������±��ĥ�����͵��������±ꡣ
��������
һ��Ӳ��ĥ��ȵ����顣
˵��:
(1) ����endurances�����ظ�ֵ
(2) ����ĳ��ȷ�Χ:[6,200]
(3) ������±��0��ʼ��
�������
��һ��:ĥ�������������±꣬���±�����չʾ
�ڶ���:ĥ�����͵��������±꣬���±�����չʾ

���룺
1 50 40 68 72 86 35 14 87 99 63 75
�����
5 8 9
0 6 7

���룺
23 34 56 12 11 10
�����
0 1 2
3 4 5

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct disk
{
	int val;
	int seq;
};

bool cmp(disk& a, disk& b)
{
	if (a.val != b.val)
	{
		return a.val < b.val;
	}
	else {
		return a.seq < b.seq;
	}
}

int main()
{
	vector<disk> endurances;
	int t_value;
	int i = 0;
	while(cin >> t_value)
	{
		endurances.push_back({ t_value, i++ });
		if (cin.peek() == '\n')
		{
			break;
		}
	}
	sort(endurances.begin(), endurances.end(), cmp);
	vector<int> biggest;	// ����
	vector<int> smallest;	// ����
	for (int i = endurances.size() - 1; i >= endurances.size() - 3; i--)
	{
		biggest.push_back(endurances[i].seq);
	}
	for (int i = 0; i <= 2; i++)
	{
		smallest.push_back(endurances[i].seq);
	}

	sort(biggest.begin(), biggest.end(), less<int>());	// ����
	sort(smallest.begin(), smallest.end(), less<int>());

	for (auto i : biggest) cout << i << " ";
	cout << endl;
	for (auto i : smallest) cout << i << " ";
	cout << endl;


}