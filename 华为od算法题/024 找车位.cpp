/*
* 024 �ҳ�λ
ͣ������һ���ų�λ��0����û��ͣ����1�����г�������ͣ��һ�����ڳ�λ�ϣ�Ҳ������һ����λû��ͣ����Ϊ�˷��в䣬��Ϊͣ�����ҵ�һ����λ��ʹ�þ�ͣ���˵ĳ�����ĳ����ľ��������ģ����ش�ʱ�������롣
��������
1.һ���ð�Ƕ��ŷָ��ͣ����ʶ�ַ�����ͣ����ʶΪ0��1��0Ϊ��λ��1Ϊ��ͣ����
2.ͣ��λ���100����
�������
���һ��������¼������
ʾ��1:
�����
1,0,0,0,0,1,0,0,1,0,1
���:
2
*/

#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
	// ��������
	string str_input;
	getline(cin, str_input);
	int str_size = str_input.size();
	int start = 0;
	vector<int> vec;
	for (int i = 0; i < str_size; i++)
	{
		if (str_input[i] == ',')
		{
			vec.push_back(stoi(str_input.substr(start, i - start)));
			start = i + 1;
		}
	}
	vec.push_back(stoi(str_input.substr(start)));

	// �ҵ�����0�ĳ���
	int dist = 0;
	int max_dist = 0;
	int i = 0;
	while(i < vec.size())
	{
		if (vec[i] == 0)
		{
			dist++;
			max_dist = dist > max_dist ? dist : max_dist;
			i++;
		}
		else
		{
			dist = 0;
			i++;
		}
	}
	cout << max_dist / 2;
}
