/*
469����������ִ�мƻ�
��Ŀ������
ĳ����Ʒ��ǰ������������N�����ԣ� F1,F2,.......FN����Ҫ���и��ǲ��ԣ�ÿ�����Զ��������˶�Ӧ�����ȼ�������ʹ����ID��Ϊ�±���б�ʶ��
�����M������������T1,T2......,TM ����ÿ��������Ӧ��һ���������Եļ��ϣ���������ʹ����ID��Ϊ�±���б�ʶ���������������ȼ�����Ϊ�串�ǵ����Ե����ȼ�֮�͡�
�ڿ�չ����֮ǰ����Ҫ�ƶ�����������ִ��˳�򣬹���Ϊ�����ȼ����������ִ�У�����������ȼ���ͬ������������IDС����ִ�С�

����������
��һ������ΪN��M��N��ʾ���Ե�������M��ʾ���������������� 0��N��100,
0��M��100 ֮��N�б�ʾ����ID=1������ID=N�����ȼ���
�ٽ�����M�б�ʾ��������ID=1����������ID=M���������Ե�ID���б�

���������
����ִ��˳�����ȼ��Ӵ�С���������������ID��ÿ��һ��ID��
�����������ǵ�ID���ظ���

ʾ��1
���룺
5 4
1
1
2
3
5
1 2 3
1 4
3 4 5
2 3 4

�����
3
4
1
2
˵�����������������ȼ��������£�

T1=Pf1+Pf2+Pf3=1+1+2=4
T2=Pf1+Pf4=1+3=4
T3=Pf3+Pf4+Pf5=2+3+5=10
T4=Pf2+Pf3+Pf4=1+2+3=6

�������ȼ���С�����Լ���ͬ���ȼ���IDС����ִ�еĹ���ִ��˳��ΪT3,T4,T1,T2

ʾ��2
���룺
3 3
3
1
5
1 2 3
1 2 3
1 2 3

�����
1
2
3

˵�����������������ȼ��������£�
T1=Pf1+Pf2+PF3=3+1+5=9
T2=Pf1+Pf2+PF3=3+1+5=9
T3=Pf1+Pf2+PF3=3+1+5=9
ÿ�����ȼ�һ��������ID��С����ִ�У�ִ��˳��ΪT1,T2,T3
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct task
{
	int prior_level;	// ���ȼ�
	int No;				// ���
};

bool cmp(task& a, task& b)
{
	if (a.prior_level != b.prior_level)
	{
		return a.prior_level > b.prior_level;
	}
	else {
		return a.No < b.No;
	}
}

int main()
{
	int n, m;	// N��ʾ���Ե�������M��ʾ��������������
	cin >> n >> m;
	vector<int> prior_level(n+1);	// �������ȼ�
	for (int i = 1; i <= n; i++)
	{
		cin >> prior_level[i];
	}
	vector<task> tasks(m);	// ��������ID=1����������ID=M���������Ե�ID���б�
	for (int i = 0; i < m; i++)
	{
		int tmp;
		while (cin >> tmp)
		{
			tasks[i].No = i+1;
			tasks[i].prior_level += prior_level[tmp];
			if (cin.get() == '\n') break;
		}
	}

	sort(tasks.begin(), tasks.end(), cmp);
	for (auto i : tasks)
	{
		cout << i.No << endl;
	}







}