/*
�ַ����ָ�
��Ŀ������
�����ǿ��ַ���s�������ַ����ָ��һЩ�Ӵ���ʹÿ���Ӵ���ASCII��ֵ�ĺ;�Ϊˮ�ɻ�����
1�����ָ�ɹ����򷵻�0
2�����ָ�ɹ��ҷָ�����Ψһ���򷵻�-1
3�����ָ�ɹ��ҷָ���Ψһ���򷵻طָ���Ӵ�����Ŀ

����������
1�������ַ�������󳤶�Ϊ200
���������
������Ŀ�����������������Ӧ�Ľ��
����˵����
��ˮ�ɻ�������ָһ����λ����ÿλ�����ֵ������͵��ڸ����ֱ�����371�ǡ�ˮ�ɻ���������Ϊ��371 = 3^3 + 7^3 + 1^3
����
ʾ��1
���룺
abc
�����
0
˵����
�ָ�ɹ�

ʾ��2
���룺
f3@d5a8
�����
-1
˵����
�ָ�ɹ����ָ�����Ψһ�����Էָ�Ϊ���飬һ��"f3"��"@d5a8"������һ��"f3@d5"��"a8"

ʾ��3
���룺
AXdddF
�����
2
˵����
�ɹ��ָ��ҷָ���Ψһ�����ԷָAX"(153)��"dddF"(370)�������Ӵ�

˼·��
����n�������֮�͵����⣺
	�ָ����δ֪������жϻ��ݽ����أ�Ӧ������ʼ�㵽���ַ���ĩβ


��Ҫ��������⣺
1. �ָ���ַ�����α�ʾ�ָ�Ǵ洢�ָ����ַ��������Ƿָ�㣿
	����洢�ָ�㣬��ô���ȷ���ָ���ַ��������ټ�һ��������ʾ�ϸ��ָ�㣿������һ�������¼�ָ�㣿
2.
*/

#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

// ��һ����������ͳ�ķָ��ַ����������ж�
bool is_narcissistic(string str)
{
	int num = 0; // ��¼�ַ������ַ�ASCII�ĺ�
	for (auto i : str)
	{
		num += i;
	}
	int sum = 0;
	int ori_num = num;
	while (num > 0)
	{
		sum += pow(num % 10, 3);
		num /= 10;
	}
	if (sum == ori_num) return true;
	else return false;
}

void backtrack(string& str, vector<string>& path, vector<vector<string>>& result, int index)
{
	if (index >= str.size())	// �ɹ��ָ�������
	{
		result.push_back(path);
		return;
	}
	for (int i = index; i < str.size(); i++)
	{
		string tmp = str.substr(index, i - index + 1);	// ��ǰ�жϵ��Ӵ�
		if (is_narcissistic(tmp))						// ��ǰ�Ӵ���ˮ�ɻ����ַ���
		{
			path.push_back(tmp);
		}
		else {
			continue;	// �����㣬������
		}
		backtrack(str, path, result, i + 1);
		path.pop_back();
	}
}

void sulotion_1()
{
	// ����
	string str;
	getline(cin, str);
	vector<string> path;	// �������������Ӵ�
	vector<vector<string>> result; // �������Ľ��
	backtrack(str, path, result, 0);

	// ������
	if (result.size() == 0)
	{
		cout << 0;
	}
	else if (result.size() == 1)
	{
		cout << result[0].size();
	}
	else if (result.size() == 2)
	{
		cout << -1;
	}
}



// �ڶ��ֽⷨ��ȡ�ɣ���ԭ�����ַ����ָ��ж�ˮ�ɻ���ת��Ϊֱ�Ӽ���ÿλ�ַ��� ASC���롣Ȼ���������зָѰ��ˮ�ɻ�����
bool is_narcissistic_2(vector<int>& vec, int index, int end)
{
	int num = 0; // ��Ҫ�жϵ�ˮ�ɻ���
	for (int i = index; i <= end; i++)
	{
		num += vec[i];
	}
	int sum = 0; // ˮ�ɻ���
	int ori_num = num;
	while (num > 0)
	{
		sum += pow(num % 10, 3);
		num /= 10;
	}
	if (sum == ori_num)
	{
		return true;
	}
	else {
		return false;
	}
}

void backtrack_2(vector<int>& vec, vector<int>& path, vector<vector<int>>& result, int index)	// ÿ�α����̶�index��Ȼ��ͨ��i����ʣ�ಿ�֣�Ѱ��ˮ�ɻ�����
{
	if (index >= vec.size())	// ������
	{
		result.push_back(path);
	}
	for (int i = index; i < vec.size(); i++)
	{
		if (is_narcissistic_2(vec, index, i)) // �����ˮ�ɻ���,��¼��ǰ���������±�
		{
			path.push_back(i);
		}
		else {
			continue;
		}
		// ���� + ����
		backtrack_2(vec, path, result, i + 1);
		path.pop_back(); 
	}

}

void solution_2()
{
	// ����
	string str;
	getline(cin, str);
	// ���ַ�����ÿ���ַ���ת��Ϊ ASCII�룬Ȼ�����������
	vector<int> vec;
	for (auto i : str)
	{
		vec.push_back(i);
	}
	vector<int> path; // ��¼�ָ���Ӵ����±�
	vector<vector<int>> result;
	backtrack_2(vec, path, result, 0); // ��������
	if (result.size() == 0)
	{
		cout << 0;
	}
	else if (result.size() == 1)
	{
		cout << result[0].size();
	}
	else if (result.size() == 2)
	{
		cout << -1;
	}

}

// �ж�ˮ�ɻ�����ͨ��
bool is_narcissistic_common(int num, int wide = 3, int power = 3)	// �жϵ����֣��жϵ�ˮ�ɻ�����λ��(���)���η���
{
	int max = pow(10, wide);		// �������ֵ�����
	int min = pow(10, wide - 1);	// �������ֵ�����
	if (num < min || num > max)
	{
		return false;
	}
	int tnum = num;	// ��Ҫ�ж����Ŀ��������ڲ���
	int sum = 0;	// �ܺ�
	while (tnum > 0)
	{
		sum += pow(tnum % 10, power);
		tnum /= 10;
	}
	if (sum == num)
	{
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	sulotion_1();
	// solution_2();
}