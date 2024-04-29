/*
475�������ļ���
��Ŀ������
��֪������ʹ�õ������Ϊ#��$����������˵ĵȼ۹�ʽ���£�
x#y = 4*x+3*y+2
x$y = 2*x+y+3
1������x��y���޷�������
2�������˹�ʽ��C���Թ������
3�������˹�ʽ�У�#�����ȼ�����$����ͬ����������������ҵ�˳�����
����һ�λ����˵��ַ������ģ����������벢��������

����������
�������ַ������ʽ����β�����س����У�
������ַ���˵����  �ַ���Ϊ�����޷��������Ͳ�������#��$����ɵļ�����ʽ�����磺123#4$5#67$78��
1��������֤�ַ����У��������������֮��û���κηָ�����
2��������֤������ȡֵ��ΧΪ32λ�޷���������
3����֤�����Լ�����������������������
4����֤������ַ���Ϊ�Ϸ�����ֵ���ģ����磺123#4$5#67$78
5����֤������ַǷ�����ֵ���ģ��������������ַ�����
#4$5 //ȱ�ٲ�����
4$5# //ȱ�ٲ�����
4#$5 //ȱ�ٲ�����
4 $5 //�пո�
3+4-5*6/7 //������������
12345678987654321$54321 //32λ�����������

���������
��������Ļ������ַ����������������β�����س����У�

ʾ��1
���룺
7#6$5#12
�����
157
˵����
ʾ����
7#6$5#12
=(4*7+3*6+2)$5#12
=48$5#12
=48$(4*5+3*12+2)
=48$58
=2*48+58+3
=157
*/

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<map>

using namespace std;

map<char, int> op_prior = { {'#', 2}, {'$', 1} };

int mars_operator(int x, int y, char op)
{
	if (op == '#')
	{
		return 4 * x + 3 * y + 2;
	}
	else {
		return 2 * x + y + 3;
	}
}

int main()
{
	string expression;	// Ԥ��ʽ		// 7#6$5#12
	getline(cin, expression);
	stack<int> nums; // ջ���洢������	
	stack<char> ops; // ջ���洢�����	#�����ȼ�����$
	// ����
	string t;
	for (int i = 0; i < expression.size(); i++)
	{
		if (isdigit(expression[i]))
		{
			t += expression[i];
			if (i == expression.size() - 1)
			{
				nums.push(stoi(t));// ��������ѹ��ջ
				t.clear();// ����str
			}
			else if(!isdigit(expression[i+1])){
				nums.push(stoi(t));// ��������ѹ��ջ
				t.clear();// ����str
			}
		}
		else {	// ��ǰ���������
			// ��������
			if (ops.empty())
			{
				ops.push(expression[i]);
			}
			else {
				if (op_prior[expression[i]] > op_prior[ops.top()])
				{
					ops.push(expression[i]);
				}
				else {
					while (!ops.empty() && op_prior[expression[i]] <= op_prior[ops.top()])
					{
						int b = nums.top(); nums.pop();
						int a = nums.top(); nums.pop();
						char op = ops.top(); ops.pop();
						nums.push(mars_operator(a, b, op));
					}
					ops.push(expression[i]);
				}
			}
		}
	}
	while (!ops.empty())
	{
		int b = nums.top(); nums.pop();
		int a = nums.top(); nums.pop();
		char op = ops.top(); ops.pop();
		nums.push(mars_operator(a, b, op));
	}
	cout << nums.top();
	
}