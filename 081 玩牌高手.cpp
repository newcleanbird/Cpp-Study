/*
���Ƹ���

��Ŀ����
����һ������Ϊn���������飬��ʾһ��ѡ����n���ڿ�ѡ������������ѡ�ֻ��ڹ���ѡ�ƣ�

����������ֽ���������Ի�õ�����ܷ�����

ѡ��������£�

��ÿ����ѡ�ֿ���ѡ���ȡ�������棬�����ܷ������ϸ������������Ϊ���µ��ܷ�����
ѡ��Ҳ�ɲ�ѡ��������ֱ��������һ�֣���ʱ����ǰ�ܷ�����ԭΪ3��ǰ���ܷ���������ǰ�ִ�С�ڵ���3�����ڵ�1��2��3��ѡ�������ִΣ������ܷ�����Ϊ0��
ѡ�ֵĳ�ʼ�ܷ���Ϊ0���ұ������βμ�ÿһ�֡�

��������
��һ��Ϊһ��Сд���ŷָ���ַ�������ʾn�ֵ����������1<= n <=20��

����ֵΪ������-100 <= ����ֵ <= 100��

�����Ǹ�ʽ���⡣

�������
�����ֽ�����ѡ�ֻ�õ�����ܷ�����

����
����	1,-5,-6,4,3,6,-2
���	11
˵��	��
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// ����
	string str;
	getline(cin, str);
	vector<int> vec;
	int start = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ',')
		{
			vec.push_back(stoi(str.substr(start, i - start + 1)));
			start = i + 1;
		}
	}
	vec.push_back(stoi(str.substr(start, str.size() - start + 1)));
	
	// ģ��
	int count = 0; // ��ǰ�ܺ�
	vector<int> res(vec.size());
	// ��������ǰ����
	for (int i = 0; i < 3; i++)
	{
		if (count + vec[i] <= 0)
		{
			count = 0;
			res[i] = count;
		}
		else {
			count += vec[i];
			res[i] = count;
		}
	}

	for (int i = 3; i < vec.size(); i++)
	{
		if (res[i - 3] > count + vec[i])
		{
			count = res[i - 3];
			res[i] = count;
		}
		else {
			count += vec[i];
			res[i] = count;
		}
	}
	cout << count;

}
