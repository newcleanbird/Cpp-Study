/*
���N��������СN�����ĺ�

��Ŀ������
����һ�����飬��дһ�������������������N��������СN�����ĺ͡�����Ҫ���������ȥ�ء�

˵����

���������ַ�Χ[0, 1000]

���N��������СN�����������ص��������ص�������Ƿ�����-1

����Ƿ�����-1

��������:

��һ������M�� M��ʶ�����С\n�ڶ�������M��������ʶ��������

����������N��N�����Ҫ����������СN����

�������:

������N��������СN�����ĺ͡�

ʾ��1

�������ʾ���������ԣ���̨��������һ�㲻����ʾ��

����

5

95 88 83 64 100

2

���

342

˵��

���2����[100,95],��С2����[83,64], ���Ϊ342��

ʾ��2

�������ʾ���������ԣ���̨��������һ�㲻����ʾ��

����

5
3 2 3 4 2
2

���

-1

˵��

���2����[4,3],��С2����[3,2], ���ص����Ϊ-1��

˼·��
		���룺�������뵽vector�У������ʱ����в���
		��vector��������
		Ȼ�����μ���ͣ����ж��Ƿ�Խ��
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int size;
	cin >> size;
	vector<int> vec;
	int tmp;
	while (size--)
	{
		cin >> tmp;
		if (find(vec.begin(), vec.end(), tmp) != vec.end())
		{
			continue;
		}
		vec.push_back(tmp);
	}
	int num;
	cin >> num;
	int min = 0;
	int sum_min = 0;
	int max = 0;
	int sum_max = 0;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < num; i++)
	{
		min = vec[i];
		sum_min += vec[i];
	}
	int vec_size = vec.size();
	for (int i = 0; i < num; i++)
	{
		max = vec[vec_size - i - 1];
		sum_max += vec[vec_size - i - 1];
	}
	if (min >= max)
	{
		cout << -1;
	}
	else {
		cout << sum_min + sum_max;
	}
	
}