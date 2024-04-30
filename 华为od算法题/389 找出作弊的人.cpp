/*
389���ҳ����׵���
��˾��֯��һ�ο���,���ڿ��Խ�������ˣ��뿴һ����û�˴���������Ϊ,����Ա��̫����,��Ҫ�ȶ�Ա������һ�ι���,�ٽ�һ��ȷ���Ƿ����������Ϊ��
���˵Ĺ���Ϊ:�ҵ��ֲ���С��Ա��ID��(p1,p2)�б�,Ҫ��p1<p2
Ա������,ȡֵ����:0<n<100000
Ա��IDΪ����,ȡֵ��Χ:0<=n<=100000
���Գɼ�Ϊ����,ȡֵ��Χ:0<=score<=300

��������
Ա����ID�����Է���
�������
�ֲ���С��Ա��ID��(p1,p2)�б�,Ҫ��p1<p2��ÿһ�д���һ������,ÿ�������ڵ�Ա��ID��˳������,���н��Ҳ��Ա������p1ֵ��С��������(���p1��ͬ��p2����)��

ʾ��1��
����:
5
1 90
2 91
3 95
4 96
5 100
���:
1 2
3 4
˵��:
����: ��һ��ΪԱ������n��������n�е�һ����ֵΪԱ��ID,�ڶ�����ֵΪԱ�����Է������:Ա��1��Ա��2�ķֲ�Ϊ1,Ա��3��Ա��4�ķֲ�ҲΪ1,������ս��Ϊ
1 2
3 4

ʾ��2��
����:
5
1 90
2 91
3 92
4 85
5 86
���:
1 2
2 3
4 5
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

bool cmp1(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.second == p2.second) return p1.first < p2.first;
	else return p1.second < p2.second;
}

bool cmp2(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.first == p2.first) return p1.second < p2.second;
	else return p1.first < p2.first;
}

int main()
{
	int n;
	cin >> n;
	int num;
	int score;
	map<int, int> emp;
	while (n--)
	{
		cin >> num >> score;
		emp.insert(pair<int, int>(num, score));
	}
	vector<pair<int, int>> v_emp(emp.begin(), emp.end());
	sort(v_emp.begin(), v_emp.end(), cmp1);
	vector< pair<int, int>> res;
	int min_dif = 300;
	int dif;
	for (int i = 1; i < v_emp.size(); i++)
	{
		dif = abs(v_emp[i - 1].second - v_emp[i].second);
		if (dif < min_dif)	// �ҵ���С�Ĳ�ֵ
		{
			min_dif = dif;
			res.clear();
			res.push_back(pair<int, int>(v_emp[i - 1].first, v_emp[i].first));
		}
		else if (dif == min_dif)
		{
			res.push_back(pair<int, int>(v_emp[i - 1].first, v_emp[i].first));
		}
	}
	sort(res.begin(), res.end(), cmp2);
	for (auto i : res)
	{
		cout << i.first << " " << i.second << endl;
	}
}