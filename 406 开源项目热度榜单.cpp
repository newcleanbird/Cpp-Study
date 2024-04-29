/*
406����Դ��Ŀ�ȶȰ�
��Ŀ����
ĳ����Դ����ϣ��������ȶȱȽϸߵĿ�Դ��Ŀ�����񵥣��Ƽ�����������Ŀ����ߡ�

����ÿ����Դ��Ŀ�������߿��Խ��й�ע(watch)���ղ�(star)��fork���ύissue���ύ�ϲ�����(MR)��

���ݿ�����ͳ����ÿ����Դ��Ŀ��ע���ղء�fork��issue��MR����������Դ��Ŀ���ȶȸ����� 5 ��ά�ȵļ�Ȩ��ͽ�������
H = W(watch)x #watch + W(star)x #star + W(fork)x #star + W(issue)x #issue + W(mr)x #mr

H ��ʾ�ȶ�ֵ
W(watch)��W(star)��W(fork)��W(issue)��W(mr)�ֱ��ʾ 5 55 ��ͳ��ά�ȵ�Ȩ��
#watch��#star��#star��#issue��#mr�ֱ��ʾ 5 ��ͳ��ά�ȵ�ͳ��ֵ
�񵥰����ȶ�ֵ�������򣬶����ȶ�ֵ��ȵģ�������Ŀ����ת��ΪȫСд��ĸ����ֵ�������('a','b','c',...,'x','y','z')

��������
��һ������Ϊ N ����ʾ��Դ��Ŀ�ĸ�����0 < N < 100
�ڶ�������ΪȨ��ֵ�б�һ�� 5 ������ֵ���ֱ��Ӧ��ע���ղء�fork��issue��MR ��������������ȡֵ 0 < n r �� 1000
�����п�ʼ�������� N ��Ϊ��Դ��Ŀ��ͳ��ά�ȣ�ÿһ�еĸ�ʽΪ
name nr_watch nr_star nr_fork nr_issue nr_mr
���� name Ϊ��Դ��Ŀ�����֣���Ӣ����ĸ��ɣ����� �� 50,���� 5 ������ֵ�ֱ�Ϊ�ÿ�Դ��Ŀ��ע���ղء�fork��issue��MR ��������������ȡֵ 0 < nr �� 1000��

�������
�����ȶȽ��������Դ��Ŀ�����֣���Ӣ����ĸ��ɣ������ȶ�ֵ��ȵģ�������Ŀ����ת��ΪȫСд����ֵ�����(��a��>��b��>��c��>��>��x��>��y��>��z��)��

����
����
4
8 6 2 8 6
camila 66 70 46 158 80
victoria 94 76 86 189 211
anthony 29 17 83 21 48
emily 53 97 1 19 218

���
victoria
camila
emily
anthony
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct project
{
	string name;
	string lower_name;
	int focus;
	int selection;
	int fork;
	int issue;
	int MR;
	int H;
};

bool cmp(project& project1, project& project2)
{
	if (project1.H == project2.H)
	{
		return project1.lower_name < project2.lower_name;
	} 
	else {
		return project1.H > project2.H;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> weight(5, 0);
	int tmp;
	for (int i = 0; i < 5; i++)
	{
		cin >> tmp;
		weight[i] = tmp;
	}
	vector<project> projects;
	string name;
	int focus;
	int selection;
	int fork;
	int issue;
	int MR;
	int H;
	while (n--)
	{
		cin >> name >> focus >> selection >> fork >> issue >> MR;
		string lower_name = name;
		transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);  // ���ڵ�����ת��ΪСд��ʽ

		H = focus * weight[0] + selection * weight[1] + fork * weight[2] + issue * weight[3] + MR * weight[4];
		projects.push_back({ name, lower_name, focus, selection, fork, issue, MR, H});
	}
	sort(projects.begin(), projects.end(), cmp);
	for (auto i : projects)
	{
		//cout << i.name << endl;
		cout << "name:" << i.name << " H = " << i.H << endl;
	}
}