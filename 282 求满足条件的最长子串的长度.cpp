/*
282����������������Ӵ��ĳ���
��Ŀ������
����һ���ַ�����ֻ������ĸ�����֣���Ҫ���ҳ��ַ����е�����������Ӵ��ĳ��ȣ��ַ���������������Ӵ����Ӵ�Ҫ��
1�� ֻ����1����ĸ(a~z, A~Z)��������������֣�
2�� ��ĸ�������Ӵ��е�����λ�ã�

����Ҳ�������Ҫ����Ӵ�����ȫ����ĸ��ȫ�����֣��򷵻�-1��
����������
�ַ���(ֻ������ĸ������)

���������
�Ӵ��ĳ���
����˵����
ʾ��1
���룺
abC124ACb
�����
4
˵����
������������Ӵ���C124����124A�����ȶ���4
ʾ��2
���룺
a5
�����
2
˵����
�ַ���������������������Ӵ�������Ϊ2
ʾ��3
���룺
aBB9
�����
2
˵����
�����������Ӵ�ΪB9������Ϊ2
ʾ��4
���룺
abcdef
�����
-1
˵����
û������Ҫ����Ӵ�������-1

�߼�������һ����ĸ���඼�����ֵ��Ӵ��

�Ż���ʹ��if else

ʹ�ã���������
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int max = 0;
	string temp;
	bool has_alpha = false;
	bool has_digit = false;
	for (int i = 0; i < str.size(); i++)
	{
		has_alpha = false;	// ��־λ���Ƿ��и���
		has_digit = false;	// ��־λ���Ƿ�������
		temp.clear();
		for (int j = i; j < str.size(); j++)
		{
			if (isalpha(str[j]))	// ��ĸ
			{
				if (!has_alpha) // �״�������ĸ
				{
					has_alpha = true;
					temp += str[j];
				}
				else if (has_digit)	// �ڶ���������ĸ��������
				{
					max = max > temp.size() ? max : temp.size();
					break;
				}
				else {	 // �ڶ���������ĸ��û������,����������������ĸ
					break;
				}
			}
			else if (isdigit(str[j]))	// ��������
			{
				if (has_alpha)	// ����������ĸ
				{
					temp += str[j];
					max = max > temp.size() ? max : temp.size();
				}
				else {
					has_digit = true;
					temp += str[j];
				}
			}
		}
	}
	if (max == 0)
	{
		cout << -1;
	}
	else {
		cout << max;
	}
	
}