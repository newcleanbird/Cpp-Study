/*
�ض���С��ͣ����������cars[]��ʾ������1��ʾ�г���0��ʾû����
������С��һ��С��ռһ����λ������1��������ռ������λ������2��������ռ������λ������3����
ͳ��ͣ�������ٿ���ͣ�������������ؾ������Ŀ

����
�����ַ�������cars[]������1��ʾ�г���0��ʾû�������鳤��С��1000��

���
���������ַ�������ʾ����ͣ����Ŀ

����
1,0,1

���
2

˵��:
1��С��ռ��1����λ���ڶ�����λ�գ�1��С��ռ��3����λ��������������

����
1,1,0,0,1,1,1,0,1


���
3

˵��:
1������ռ��1��2����λ����3��4����λ�գ�1������ռ��5��6��7����λ
��8����λ�գ�1��С��ռ��9����λ������3����

˼·��
	Ƕ��if���������

ע�⣺if�ı߽�������ע���ж�����е� == ��Ҫд�� =
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	// ����
	string input;
	getline(cin, input);
	vector<int> vec;
	int start = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == ',')
		{
			string str = input.substr(start, i - start);
			int tmp = stoi(str);
			vec.push_back(tmp);
			start = i + 1;
		}
	}
	vec.push_back(stoi(input.substr(start)));


	// ��������ͣ�µ�����
	int count = 0;
	int i = 0;
	int size = vec.size();
	while(i < size){
		if (vec[i] == 1) {
			if (i + 2 < size && vec[i + 2] == 1 && vec[i + 1] == 1) {
				count++;
				i = i + 3;
			}
			else if (i + 1 < size && vec[i + 1] == 1) {
				count++;
				i = i + 2;
			}
			else {
				count++;
				i = i + 1;
			}
		}
		else {
			i = i + 1;
		}
	}
	cout << count << endl;
}