/*
437��̰�ĸ���
��Ŀ������
һ������׼����A��ȥB�ǲμ��ݳ���
1) ���պ�ͬ����������T���ڸϵ���
2) ���ֲ��������ߡ�
3) ÿ��������֮����Ҫ��������������ǰ��֪��
4) ������ÿ�����ж�������·������׬Ǯ���������У�������ǰ��֪��ÿ����������������Ԥ�ڣ������һ�����е�һ����������׬M������ÿ�����������D���ڶ���׬��Ǯ��M �C D����������M-2D����������������0�Ͳ��������ˡ�
5) ���ֵ����ĵڶ�����ܿ�ʼ����������������������ڶ�����ܳ�����

̰�ĵĸ���������׬����Ǯ��

����������
��һ���������� T��N���м��ÿո������
T������������
N����·�Ͼ���N�����У�
0 < T < 1000, 0 < N < 100
�ڶ���N+1�����֣��м��ÿո������
����ÿ��������֮��ķѵ�ʱ�䡣
���ܺ�<=T��
������N�У�ÿ����������M��D���м��ÿո������
����ÿ�����е�����Ԥ�ڡ�
0 < M < 1000, 0 < D < 100

���������һ�����֡��������������׬����Ǯ���Իس�������

ʾ��1
���룺
10 2
1 1 2
120 20
90 10

�����540

˵����
�ܹ�10�죬·�Ͼ���2�����С�
·�Ϲ���1+1+2=4�졣
ʣ��6����õļƻ����ڵ�һ�����д�3�죬�ڵڶ������д�3�졣
�ڵ�һ������׬��Ǯ��120+100+80= 300.
�ڵڶ�������׬��Ǯ��90+80+70 =240.
һ��300 + 240 = 540��

˼·��̰�� or ���ȶ���
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct income
{
	int M;	// ��һ������
	int D;	// ����˥��

	bool operator<(const income& b) const
	{
		return this->M == b.M ? this->D > b.D : this->M < b.M;
	}
	bool operator>(const income& b) const
	{
		return this->M == b.M ? this->D > b.D : this->M > b.M;
	}
};

bool cmp(income& a, income& b)
{
	if (a.M != b.M)
	{
		return a.M > b.M;
	}
	else
	{
		return a.D > b.D;
	}
}

int main()
{
	// ����
	int t, n;	// t:���������� N����·�Ͼ���N�����У�
	cin >> t >> n;
	cin.get();
	vector<int> days(n + 1);	// ÿ��������֮��ķѵ�ʱ��
	int tmp;
	int count_day = 0;
	for (int i = 0; i < n + 1; i++)
	{
		cin >> tmp;
		days[i] = tmp;
		count_day += tmp;
	}
	cin.get();
	int m, d;
	vector<income> vec(n);	// ÿ�����е�����
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].M >> vec[i].D;
	}
	// ����
	int remain_time = t - count_day;	// ʵ�ʿ��õ�ʱ��
	int income_count = 0;	// ������
	priority_queue<income, vector<income>,  less<income>> q(vec.begin(), vec.end());
	while (remain_time--)
	{
		income_count += q.top().M;
		income tmp = q.top();	q.pop();
		tmp.M -= tmp.D;
		q.push(tmp);
	}
	cout << income_count;
}
