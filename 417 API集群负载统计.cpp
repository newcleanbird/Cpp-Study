/*
417��API��Ⱥ����ͳ��
��Ŀ������
ĳ����Ʒ��RESTful API���ϲ����ڷ�������Ⱥ�Ķ���ڵ��ϣ����ڶԿͻ��˷�����־�����˲ɼ�����Ҫͳ�Ƹ���API�ķ���Ƶ�Σ������ȵ���Ϣ�ڷ������ڵ�֮�������ؾ��⣬������Ҫʵ���ȵ���Ϣͳ�Ʋ�ѯ���ܡ�
RESTful API���ɶ���㼶���ɣ��㼶֮��ʹ�� / ���ӣ��� /A/B/C/D �����ַ��A���ڵ�һ����B���ڵڶ�����C���ڵ�������D���ڵ��ļ���
���ڸ��ؾ���ģ����Ҫ֪�������㼶��ĳ�����ֳ��ֵ�Ƶ�Σ�δ���ֹ���0�α�ʾ��ʵ��������ܡ�

����������
��һ��ΪN����ʾ������ʷ��־��������0<N<=100��
������N�У�ÿһ��Ϊһ��RESTful API��URL��ַ��Լ����ַ�н�����Ӣ����ĸ�����ӷ�/�����㼶Ϊ10��ÿ�㼶�ַ�����󳤶�Ϊ10��
���һ��Ϊ�㼶L��Ҫ��ѯ�Ĺؼ��֡�

���������
��������㼶�ϣ��ؼ��ֳ��ֵ�Ƶ�Σ�ʹ����ȫƥ�䷽ʽ����Сд���У���

ʾ��1
���룺
5
huawei/computing/no/one
huawei/computing
huawei
huawei/cloud/no/one
huawei/wireless/no/one
2 computing
�����
2
˵����
�ڵڶ��㼶�ϣ�computing������2�Σ�������2.

ʾ��2
���룺
5
huawei/computing/no/one
huawei/computing
huawei
huawei/cloud/no/one
huawei/wireless/no/one
4 two
�����
0
˵����
���ڵ��Ĳ㼶��URL�ϣ�û�г���two�����Ƶ����0

�ѵ㣺���ͳ�ƽṹ
vector<vector<pair<string, int>>>

*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	// ����
	int n;
	cin >> n;
	vector<string> apis(n);
	for (int i = 0; i < n; i++)
	{
		cin >> apis[i];
	}
	int level;
	string key;
	cin >> level >> key;

	// ͳ��
	//vector<vector<pair<string, int>>> record;	// ���Բ�ͳ�ƣ�ֱ�Ӱ���Ҫ�����
	int count = 0;
	for (auto str : apis)
	{
		int cur_l = 0;
		int l, r;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '/')
			{
				cur_l++;
			}
			if (cur_l == level)
			{
				string tmp = str.substr(i, key.size());
				if (tmp == key)
				{
					count++;
				}
			}
		}
	}
	cout << count;


}