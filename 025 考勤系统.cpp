/*
��Ŀ������

��˾��һ���ַ�������ʾԱ���ĳ�����Ϣ��
absent��ȱ��
late���ٵ�
leaveearly������
present�������ϰ�
�������Ա��������Ϣ���жϱ����Ƿ��ܻ�ó��ڽ����ܻ�ó��ڽ����������£�
ȱ�ڲ�����һ�Σ�û�������ĳٵ�/���ˣ���������7�ο��ڣ�ȱ��/�ٵ�/���˲�����3��
����������

�û��Ŀ��������ַ�������¼���� >= 1�������ַ�������<10000�������ڷǷ�����
�磺

2
present
present absent present present leaveearly present absent

���������
���ݿ��������ַ���������ܵõ����ڽ������"true"���������"false"����������ʾ���Ľ��ӦΪ��

true false

ʾ��1

���룺

2
present
present present
�����

true true
˵����

ʾ��2

���룺

2
present
present absent present present leaveearly present absent
�����

true false
˵����

*/

#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

bool isPrice(string &str1)
{
	

	// ����vector<string> ��
	vector<string> vec;
	istringstream is(str1);
	string str;
	while (is >> str)
	{
		vec.push_back(str);
	}

	// �ж�
	int absent = 0;		// ȱ��
	int present = 0;	// �����ϰ�
	string preRecord = "";
	for (int i = 0; i < vec.size(); i++)
	{
		// ���ܴ�������7ʱ���ƶ����ڣ���������ߵĴ򿨼�¼���д���
		if (i > 7)
		{
			if (vec[i - 7] == "present")
			{
				present--;
			}
		}
		// �жϵ�ǰ�Ĵ����
		if (vec[i] == "absent")
		{
			if (++absent > 1) return false;
		}
		else if (vec[i] == "late" || vec[i] == "leaveearly")
		{
			if (preRecord == "late" || preRecord == "leaveearly")
			{
				return false;
			}
		}
		else if (vec[i] == "present")
		{
			present++;
		}
		// ����7�δ򿨳���3��������
		int window_len = min(i + 1, 7);
		if (window_len - present > 3) return false;
	}
	return true;
}

int main()
{
	int count = 0;
	cin >> count;
	string str;
	cin.get();

	vector<bool> res;
	while (count--)
	{
		getline(cin, str);
		res.push_back(isPrice(str));
	}
	for (auto i : res)
	{
		if(i == true)cout << "true" << " ";
		else cout << "false" << " ";
	}

}