/*
330����λ����
��Ŀ������
�����ڼ���õ���λ����������ĵ��������ܳ�������ͬѧ�����ţ����������һ����λ��
����һ���������� desk ��ʾ��ǰ��λ��ռ������������� 0 �� 1 ��ɣ����� 0 ��ʾû��ռλ��1 ��ʾռλ���ڲ��ı�ԭ����λ��������£����ܰ����������ˣ�
����������
��һ���Ǹ��������ʾ��Ϊռ������������� 0 �� 1 ��ɣ����� 0 ��ʾû��ռλ��1 ��ʾռλ
���������
�����ֵ��ʾ������������
����˵����
1 <= desk.length <= 2 * 104
ʾ��1
���룺
1,0,0,0,1
�����
1
˵����
ֻ��desk[2]��λ�ÿ�����һ����

0,0,0,0,0,0,0,0,0
1,0,1,0,1,0,1,0,1
// ÿ������λ���԰���һ����
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	// ��������
	char ch;
	vector<int> vec;
	while (cin >> ch)
	{
		if (isdigit(ch)) vec.push_back(ch - '0');
		if (cin.peek() == '\n') break;
	}
	int count = 0; 
	int zero = 0;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		if (vec[i] == 0) {
			if (vec.size() == 1)
			{
				count = 1;
				break;
			}
			else if (i == 0 && vec[i + 1] == 0) {
				vec[i] = 1;
				count++;
			}
			else if (i > 0 && vec[i - 1] == 0 && vec[i + 1] == 0) {
				vec[i] = 1;
				count++;
			}
		}
	}
	if(vec[vec.size() - 2] == 0 && vec[vec.size() - 1] == 0) {
		vec[vec.size() - 1] = 1;
		count++;
	}
	cout << count;
}