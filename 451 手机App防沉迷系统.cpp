/*
451�� �ֻ�App������ϵͳ
��Ŀ������
�����ֻ����������������ͬʱ��Ҳ��ռ�����ǲ��ٵ�ʱ�䡣���ֻ�App������ϵͳ���ܹ�������ÿ�����Ĺ滮�ֻ�Appʹ��ʱ�䣬����ȷ��ʱ������ȷ���¡�
���Ĵ��ԭ���������ģ�
1����һ��24Сʱ�ڣ���ע��ÿ��App������ʹ��ʱ�Σ�
2��һ��ʱ��ֻ��ʹ��һ��App������˵��������ͬʱ��09:00-10:00ע��App2��App3��
3��App�����ȼ�����ֵԽ�ߣ����ȼ�Խ�ߡ�ע��ʹ��ʱ��ʱ����������ȼ���Appʱ��͵����ȼ���ʱ���г�ͻ����ϵͳ���Զ�ע�������ȼ���ʱ�Σ����App�����ȼ���ͬ�������ӵ�App����ע�ᡣ

����1��
��1��ע��App3ǰ��
��2��App3ע��ʱ�κ�App2�г�ͻ��
��3��App3���ȼ��ߣ�ϵͳ����App3��ע�ᣬ�Զ�ע��App2��ע�᣺

����2��
��1��ע��App4��
��2��App4��App2��App3���г�ͻ�����ȼ���App2�ߣ�����App3�ͣ����ֳ�����App4ע�᲻�ϣ����յ�ע��Ч�����£�

4��һ��App������һ����ע����ʱ�Ρ�

����ʵ�֣�������������ע��App�������������ʱ��㣬���ظ�ʱ�����õ�App���ƣ������ʱ���û��ע���κ�App���뷵���ַ���"NA"��

����������
�����3���֣���һ�б�ʾע���App��N��N��100�����ڶ����ְ���N�У�ÿ�б�ʾһ��Appע�����ݣ����һ������һ��ʱ��㣬���򼴷��ظ�ʱ���Ŀ���App��
2
App1 1 09:00 10:00
App2 2 11:00 11:30
09:30

����˵�����£�
1��N��ע�������Կո�ָ��������������α�ʾ��App���ơ����ȼ�����ʼʱ�䡢����ʱ��
2�����ȼ�1-5������ֵԽ�����ȼ�Խ��
3��ʱ���ʽHH:MM��Сʱ�ͷ��Ӷ�����λ��������λǰ�油0
4����ʼʱ����С�ڽ���ʱ�䣬����ע�᲻��
5��ע����Ϣ�е�ʱ��ΰ�����ʼʱ��㣬����������ʱ���

���������
���һ���ַ�������ʾApp���ƣ���NA��ʾ����ʱ�䡣

����˵����
1��������֤ʱ�䶼����00:00-24:00֮�䣻
2��������֤���ݸ�ʽ������ȷ�ģ����ÿ���������������������ע����Ϣ���������ַ����Ƿ������ȼ����ޡ�ʱ���ʽ����ȷ�����⡣

ʾ��1
���룺
1
App1 1 09:00 10:00
09:30
�����
App1
˵����
App1ע����9�㵽10��䣬9�����õ�Ӧ������App1

ʾ��2
���룺
2
App1 1 09:00 10:00
App2 2 09:10 09:30
09:20
�����
App2
˵����
App1��App2��ʱ���г�ͻ��App2�����ȼ���App1�ߣ�ע��App2��ϵͳ��App1��ע����Ϣ�Զ�ע����09:20ʱ�̿���Ӧ������App2.

ʾ��3
���룺
2
App1 1 09:00 10:00
App2 2 09:10 09:30
09:50
�����
NA
˵����
App1��ע����09:50ʱ��û��Ӧ��ע�ᣬ������NA��
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct apptime
{
	int hour;
	int minute;
	bool operator>=(apptime& b)
	{
		if (this->hour != b.hour)
		{
			return this->hour >= b.hour;
		}
		else {
			return this->minute >= b.minute;
		}
	}
};

struct app
{
	string name;
	int priority;
	apptime begin;
	apptime end;
};

bool cmp(app& a, app& b)
{
	return a.priority > b.priority;
}

int main()
{
	// ����
	int n;
	cin >> n;
	vector<app> vec(n);
	for (int i = 0; i < n; i++)
	{
		string tbeg, tend;
		cin >> vec[i].name >> vec[i].priority >> tbeg >> tend;
		vec[i].begin.hour = stoi(tbeg.substr(0, 2));
		vec[i].begin.minute = stoi(tbeg.substr(3));
		vec[i].end.hour = stoi(tend.substr(0, 2));
		vec[i].end.minute = stoi(tend.substr(3));
	}
	apptime query_time;
	string stime;
	cin >> stime;
	query_time.hour = stoi(stime.substr(0, 2));
	query_time.minute = stoi(stime.substr(3));


	// ����
	vector<app> res;	// ��¼����ÿ��ʱ�εĽ��
	for (int i = 0; i < vec.size(); i++)
	{
		// ��ý���������к�app[i]��ص�
		vector<int> ids;
		for (int j = 0; j < res.size(); j++)
		{
			if (vec[i].end >= res[j].begin && res[j].end >= vec[i].begin)	// i�����ĺͽ�����е�j�н�������j������Ҫ�жϵĶ���
			{
				ids.push_back(j);
			}
		}
		int priority_max = -1;
		for (int i = 0; i < ids.size(); i++)
		{
			priority_max = max(priority_max, res[ids[i]].priority);
		}
		if (vec[i].priority > priority_max)
		{
			for (int j = ids.size() - 1; j >= 0; j--)
			{
				res.erase(res.begin() + ids[j]);
			}
			res.push_back(vec[i]);
		}
	}
	
	// ��ѯ���
	string ans = "NA";
	for (auto i : res)
	{
		if (query_time >= i.begin && i.end >= query_time)
		{
			ans = i.name;
		}
	}
	cout << ans;
	

}