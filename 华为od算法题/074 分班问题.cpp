/*
74�� �ְ�����
��Ŀ
�׶�԰�������С�������Ŷ�ʱ������һ��ÿλС���Ѷ�֪���Լ��Ƿ���ǰ��һλС����ͬ�࣬�����æ��ͬ���С�����ҳ�����
С���ѵı������������ǰһλС����ͬ����Y��ʾ����ͬ����N��ʾ��
ѧ����ŷ�Χ(0,999]��������벻�Ϸ����ӡERROR��
����������

����Ϊ�ո�ֿ���С���ѱ�ź��Ƿ�ͬ���־��
���������

���Ϊ���У�ÿһ�м�¼һ����С���ѵı�ţ�����ÿո�ֿ����ң�
1.����谴���������С�
2.��ֻ��һ�����С���ѣ��ڶ���Ϊ���С�
ʾ��1 �������ʾ���������ԣ���̨��������һ�㲻����ʾ��

����
1/N 2/Y 3/N 4/Y

���
1 2
3 4

ʾ��2 �������ʾ���������ԣ���̨��������һ�㲻����ʾ��

����
1/N 2/Y 3/N 4/Y 5/Y

���
1 2
3 4 5

˼·��һ��ֻ�������࣬
	ÿ�δ����� / Ϊ�ֽ��ߣ�б��ǰ����������Ϊ�洢��ţ�б�ܺ���ַ�Ϊ�жϱ�־��
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	vector<int> class1;	// һ��
	vector<int> class2;	// ����
	bool isFiest = false;// ���ñ�־λ
	string seq;
	int num;
	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			seq.append(1, str[i]);
		}
		else if (str[i] == '/')
		{
			num = stoi(seq);
			seq.clear();
			i++;
			if (str[i] == 'N')
			{
				isFiest = !isFiest;
			}
			else {
				// ��ȡ��
			}
			if (isFiest == true)
			{
				class1.push_back(num);
			}
			else {
				class2.push_back(num);
			}
		}
	}

	// ������
	for (auto i : class1)
	{
		cout << i << " ";
	}
	cout << endl;
	for (auto i : class2)
	{
		cout << i << " ";
	}
	


}