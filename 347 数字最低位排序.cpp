/*
347���������λ����
��Ŀ������
����һ���ǿ�����(�б�)��Ԫ����������Ϊ���ͣ��밴������Ԫ��ʮ�������λ��С�����������
1.ʮ�������λ��ͬ��Ԫ�أ����λ�ñ��ֲ���
2.������Ԫ��Ϊ��ֵʱ��ʮ�������Ϊ��ͬ��ȥ������λ���Ӧʮ����ֵ���λ
��������
����һ���ǿ�����(�б�)
��Ԫ����������Ϊ32λ�з������������鳤��Ϊ[1,1000]
�������
����������
ʾ��1:
����
1,2,5,-21,22,11,55,-101,42,8,7,32
���
1,-21,11,-101,2,22,42,32,5,55,7,8
�������Զ��������������STL���еĿ��ź���sort��ɼ���
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(int n1, int n2)
{
	int l1 = abs(n1 % 10);
	int l2 = abs(n2 % 10);
	if (l1 == l2)
	{
		return false;	// ��sort() �ȼ��� l1 < l2;
	}
	else {
		return l1 < l2;
	}
}

int main()
{
	string str;
	getline(cin, str);
	string tmp;
	vector<int> vec;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ',')
		{
			vec.push_back(stoi(tmp));
			tmp = "";
		}
		else {
			tmp += str[i];
		}
	}
	vec.push_back(stoi(tmp));

	// sort
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
		if (i != vec.size() - 1)
		{
			cout << ",";
		}
	}
}