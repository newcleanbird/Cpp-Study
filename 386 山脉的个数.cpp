/*
386��ɽ���ĸ���
����һ�����飬�����е�ÿ��Ԫ�ش����λ�õĺ��θ߶ȡ�0��ʾƽ�أ�>=1ʱ��ʾ����ĳ��ɽ�壬ɽ��Ķ���Ϊ��ĳ��λ�õ����Һ��ξ�С���Լ�ʱ����λ��Ϊɽ�塣������ʼλ�ü���ʱ��ֻ����һ�ߵ���������������һ����������
�������
�������������ɽ��ĸ���
ʾ��1��
���룺
0,1,2,3,2,4
�����
2
ʾ��2��
���룺
3,0,3,4,1
�����
2

0,1,4,3,1,0,0,1,2,3,1,2,1,0
3

1
1

1,1
0

1,2
1

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	// ����
	string str;
	getline(cin, str);
	vector<int> vec;
	string tmp;
	for (int i = 0; i < str.size(); i++)
	{
		if(str[i] == ',')
		{
			vec.push_back(stoi(tmp));
			tmp = "";
		}
		else {
			tmp += str[i];
		}
		if (i == str.size() - 1)
		{
			vec.push_back(stoi(tmp));
		}
	}
	// ����ɽ��
	int count = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.size() == 1)
		{
			count = 1;
			break;
		}
		if (i == 0)
		{
			if (vec[i] > vec[i + 1]) count++;
		}
		else if ( i== vec.size() - 1)
		{
			if (vec[i] > vec[i-1]) count++;
		}
		else if (vec[i - 1] < vec[i] && vec[i] > vec[i + 1])
		{
			count++;
		}
	}
	cout << count;
}