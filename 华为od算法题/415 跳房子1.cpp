/*
�����ӣ�Ҳ�����ɻ����ǡ��������ԵĶ�ͯ��Ϸ����Ϸ��������Ҫ�ֶ���غϰ�˳��������1��ֱ�����ӵ���󡪸������ӵĹ����У�������ǰ����Ҳ�����������
���跿�ӵ��ܸ�����count��С��ÿ�غϿ����������Ĳ��̶���������steps�У������������Ƿ���һ�ֲ�������ϣ�������С�������غ�������󡪸�?����У��������������С�Ĳ�����ϡ�
ע��:
�����еĲ��������ظ����������е�Ԫ�ز����ظ�ʹ�á��ṩ�����ݱ�֤����������ĿҪ�����ϣ�����������С�Ĳ��������Ψһ��
��������
��һ������Ϊ�����ܸ���count������int�������͡�
�ڶ�������Ϊÿ�غϿ����������Ĳ���������int�����������͡�
�������
������������С������Ҫ��Ĳ������(˳�򱣳�steps��ԭ��˳��
��ע
count �� 1000
0 �� steps.length �� 5000
-100000000 steps �� 100000000

ʾ��1:
���룺
7
1,4,5,2,2
���
5, 2

ʾ��2:
����
8
-1,2,4,9,6
���
-1,9
˵��
�������ж�������������غ��������Ʃ��: [-1,9]��[2,6]������[-1,9]��������Ϊ0+3=3��[2,6]������Ϊ1+4=5��������������С�Ĳ������[-1,9]


// ������ǰ���������������Ѱ��һ����ϣ�ʹ��Ϊ����
��ȷ��һ��ֵ�����С��Ŀ��ֵ��Ѱ����һ��ֵ
�������Ŀ��ֵ��Ѱ�Ҳ�ֵ(��ֵ)
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int count;
	cin >> count;
	cin.get();
	vector<int> steps;
	string str;
	getline(cin, str);
	string tmp;
	for (auto i : str)
	{
		if (i != ',')
		{
			tmp += i;
		}
		else {
			steps.push_back(stoi(tmp));
			tmp.clear();
		}
	}
	steps.push_back(stoi(tmp));
	// ����
	// sort(steps.begin(), steps.end(), less<int>());	// ������
	
	int l = 0, r = steps.size() - 1;
	int dif;
	for (int i = 0; i < steps.size(); i++)
	{
		for (int j = i + 1; j < steps.size(); j++)
		{
			dif = steps[i] + steps[j];
			if (dif == count)
			{
				cout << steps[i] << " " << steps[j];
				break;
			}
			dif = abs(steps[i] - steps[j]);
			if (dif == count)
			{
				cout << steps[i] << " " << steps[j];
				break;
			}
		}
	}
}