/*
412��ѧ�����������ܳɼ���
��Ŀ������
С������ĳѧУ����ʦ����Ҫ��ѧ���������ֻܷ򵥿Ʒ����������������ܰ������

����������
��1����������������ѧ������n�Ϳ�Ŀ����m��0<n<100,0<m<10
��2������m����Ŀ���ƣ��˴�֮���ÿո��������Ŀ����ֻ��Ӣ����ĸ���ɣ��������Ȳ�����10���ַ�����Ŀ�ĳ���˳��ͺ��������ѧ���ɼ�һһ��Ӧ����������ظ��Ŀ�Ŀ���ơ�
��3�п�ʼ��n�У�ÿ�а���һ��ѧ���������͸���m����Ŀ�ĳɼ����ո��������ѧ������������ѧ������ֻ��Ӣ����ĸ���ɣ����Ȳ�����10���ַ����ɼ���0~100�����������ζ�Ӧ��2��������Ŀ�Ŀ��
��n+2�У��������������Ŀ�Ŀ���ơ�����Ŀ�����ڣ����ֽܷ�������

���������
���һ�У����ɼ�������ѧ�����֣��ո�������ɼ���ͬ�İ���ѧ�������ֵ�˳������

ʾ��1
���룺
3 2
yuwen shuxue
fangfang 95 90
xiaohua 88 95
minmin 100 82
shuxue
�����
xiaohua fangfang minmin
˵����
��shuxue�ɼ�������������xiaohua��fangfang��minmin

ʾ��2
���룺
3 2
yuwen shuxue
fangfang 95 90
xiaohua 88 95
minmin 90 95
zongfen
�����
fangfang minmin xiaohua
˵����

�����Ŀ�����ڣ����ܷ�����fangfang��minmin�ܷ���ͬ�����������ֵ�˳��fangfang����ǰ��
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

struct student
{
	string name;
	vector<int> subject;
	int total_score;
};

int index = -1; // ������±�

bool cmp(student student1, student student2)
{
	if (index != -1)
	{
		int score1 = student1.subject[index];
		int score2 = student2.subject[index];
		if (score1 != score2)
		{
			return score1 > score2;
		}
		else {
			return student1.name < student2.name;
		}
	}
	else {
		return student1.total_score > student2.total_score;
	}
}

int main()
{
	int n, m; //ѧ������n ��Ŀ����m
	cin >> n >> m;
	vector<string> subject(m);	// �ɼ�
	for (int i = 0; i < m; i++)
	{
		cin >> subject[i];
	}
	vector<student> students(n);
	for (int i = 0; i < n; i++)
	{
		cin >> students[i].name;
		int tmp;
		int score = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			students[i].subject.push_back(tmp);
			score += tmp;
		}
		students[i].total_score = score;
	}
	string cmp_name;
	cin >> cmp_name;
	for (int i = 0; i < m; i++)
	{
		if (subject[i] == cmp_name)
		{
			index = i;
		}
	}
	sort(students.begin(), students.end(), cmp);
	for (auto i : students)
	{
		cout << i.name << " ";
	}
}
