/*
192�������ɫ�ĳ���

��Ŀ������
��һ����С��·�ڣ�ÿ��ֻ��ͨ��һ���������糵������ɫֻ��3�֣��ҳ�N���ھ����������ɫ�ĳ�������
������ɫ���Ϊ0,1,2
����������
��һ���������ͨ���ĳ�����ɫ��Ϣ
[0,1,1,2] ����4����ͨ���ĳ�����ɫ�ֱ���0,1,1,2
�ڶ����������ͳ��ʱ�䴰�����ͣ���λΪ��
���������
���ָ��ʱ�䴰�ھ����������ɫ�ĳ�������
����˵����
 ����
ʾ��1
���룺
0 1 2 1
3
�����
2
˵����
��[1,2,1]���3��ʱ�䴰�ڣ�1�����ɫ����2�Σ��������
ʾ��2
���룺
0 1 2 1
2
�����
1
˵����
��2��ʱ�䴰�ڣ�ÿ����ɫ������1��

ʾ����
0 1 0 0 1 2 1 2 2 2 2 1 2 0 1 1 1
6

5
˼·��
˫ָ�뷨��⣺
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	// ����
	vector<int> vec;
	int tmp;
	while (cin >> tmp)
	{
		vec.push_back(tmp);
		if (cin.get() == '\n') break;
	}
	int time;
	cin >> time;
	vector<int> res(3);
	// ˫ָ�뷨����
	int imax = 0;
	int left = 0, right = 0;
	for (int right = time - 1; right < vec.size(); right++)
	{
		res.assign(res.size(), 0);// ����res
		for (int left = right - time + 1; left <= right; left++)
		{
			res[vec[left]]++;
		}
		for (int i : res)
		{
			imax = max(imax, i);
		}
	}
	cout << imax;
}

