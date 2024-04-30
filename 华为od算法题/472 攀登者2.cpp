/*
* 472 �ʵ���2
�ʵ���ϲ��Ѱ�Ҹ��ֵ�ͼ�����ҳ����ʵǵ���ߵ�ɽ�塣
��ͼ��ʾΪһά���飬�������������ˮƽλ�ã������Ԫ�ش�����Ժ��θ߶ȡ���������Ԫ��0������档
���磺[0,1,2,4,3,1,0,0,1,2,3,1,2,1,0]����������ͼ��ʾ�ĵ�ͼ����ͼ��������ɽ��λ�÷ֱ�Ϊ 1,2,3,4,5 �� 8,9,10,11,12,13����߷�߶ȷֱ�Ϊ 4,3����߷�λ�÷ֱ�Ϊ3,10��
һ��ɽ�������ж���ɽ��(�߶ȴ�������λ�õĸ߶ȣ����ڵ�ͼ�߽��Ҹ߶ȴ������ڵĸ߶�)��

			  4
			+---+
			|	|
			|	|
			|	| 3						  3
			|	+---+					+---+
			|		|					|	|
			|		|					|	|
		  2	|		|				  2 |	|	  2
		+---+		|				+---+	|	+---+
		|			|				|		|	|	|
		|			|				|		|	|	|
	  1	|			| 1			  1 |		| 1	|	| 1
	+---+			+---+		+---+		+---+	+---+
	|					|		|						|
	|					|		|						|
  0	|					| 0   0 |						| 0
+---+					+---+---+						+---+
  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14

1.��ɽʱ�����ĵ�ɽ�ߵ�����(����)����ɽʱ���������ڸ߶Ȳ�����������������ʱ�������ڸ߶Ȳ�һ����������ƽ�ز�������������ɽ���������ĵ���ʱ��������Σ��.
������ͼ��ʾ��ɽ�壬 ������0���ߵ�����1���߶Ȳ�Ϊ1����Ҫ����2X1=2��������������2�߶�2�ߵ��߶�4����3��Ҫ����2X2=4������������Ǵ�����3�ߵ�����4������1X1=1��������
2.��ɽ����������Ϊ999��
3.��ɽʱ�������յ�����ǵ�ͼ���κθ߶�Ϊ0�ĵ���������ͼ�е�0,6,7,14����������Ϊ��ɽ�������յ�

�ʵ�����Ҫ����һ�ŵ�ͼ���ж�����ɽ����Խ����ʵǣ��ҿ��԰�ȫ���ص����棬��������Σ��
������ͼ�е����飬��3����ͬ��ɽ�壬����λ����3��ɽ���Դ�λ��0����λ��6��ʼ����λ��0�ǵ�ɽ����Ҫ��������1X2+1X2+2X2 = 8����ɽ�����ص�����0��Ҫ���� 2X1+1X1 + 1X1 = 4 �����������յ�ɽ·��0->3->0��Ҫ��������12���ʵ���������Ҫ12���ϵ�����(����12)���ܰ�ȫ���ء�


ʾ��1
����
0,1,4,3,1,0,0,1,2,3,1,2,1,0
13
���
3
˵��
��ɽ��ֻ�ܹ�����λ��10��12��ɽ�壬7->10->7��14->12->14

ʾ��2
����
1,4,3
999
���
0
˵��
ԭ������������������⣬������
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> mountain;
vector<int> cost_m;

void find_mountain(vector<int>& m)
{
	// int l = -1, r = m.size(), top;
	for (int i = 0; i < m.size(); i++)
	{
		if (m.size() == 1)	// ֻ��Ψһ��ֵ��Ӧ�ò������������.ֻ��Ϊ�˱�֤ m����1
		{
			mountain.push_back(i);
		}
		else if (i == 0)
		{
			if (m[i] > m[i + 1])
			{
				mountain.push_back(i);
			}
			
		}
		else if(i == m.size() - 1)
		{
			if (m[i] > m[i - 1])
			{
				mountain.push_back(i);
			}
		}
		else {
			if (m[i] > m[i + 1] && m[i] > m[i - 1])
			{
				mountain.push_back(i);
			}
		}
	}
}

int find_left_zero(vector<int>& m, int index)
{
	for (int i = index; i >= 0; i--)
	{
		if (m[i] == 0)
		{
			return i;
		}
	}
	return -1;
}

int find_right_zero(vector<int>& m, int index)
{
	for (int i = index; i < m.size(); i++)
	{
		if (m[i] == 0)
		{
			return i;
		}
	}
	return -1;
}

int left_to_right(vector<int>& m, int l, int top)	// �������ҳ���
{
	int cost = 0;
	for (int i = l+1; i <= top; i++)	// ��i - > top
	{
		if (m[i] > m[i - 1])	// ������
		{
			cost += (m[i] - m[i - 1]) * 2;
		}
		else {
			cost += m[i-1] - m[i]; // ������
		}
	}
	if (cost == 0)
	{
		return 1000;
	}
	else {
		return cost;
	}
	
}

int right_to_left(vector<int>& m, int r, int top) // �����������
{
	int cost = 0;
	for (int i = r - 1; i >= top; i--)
	{
		if (m[i] > m[i + 1])	// ������
		{
			cost += (m[i] - m[i + 1]) * 2;
		}
		else {
			cost += m[i + 1] - m[i]; // ������
		}
	}
	if (cost == 0)
	{
		return 1000;
	}
	else {
		return cost;
	}
}

void find_min(vector<int>& m)
{
	for (auto i : mountain)
	{
		int min_up_cost = 1000;
		int min_down_cost = 1000;
		int left_zero = find_left_zero(m, i);
		int right_zero = find_right_zero(m, i);
		// ��ɽ
		if (left_zero != -1)
		{
			min_up_cost = min(min_up_cost, left_to_right(m, left_zero, i));
		}
		if (right_zero != -1)
		{
			min_up_cost = min(min_up_cost, right_to_left(m, right_zero, i));
		}
		// ��ɽ
		if (right_zero != -1)
		{
			min_down_cost = min(min_down_cost, left_to_right(m, i, right_zero));
		}
		if (left_zero != -1)
		{
			min_down_cost = min(min_down_cost, right_to_left(m, i, left_zero));
		}
		cost_m.push_back(min_up_cost + min_down_cost);
	}
}

int main()
{
	// ����
	vector<int> m;
	string str;
	getline(cin, str);
	string s;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ',')
		{
			s += str[i];
		}
		else {
			m.push_back(stoi(s));
			s.clear();
		}
	}
	if (!s.empty())
	{
		m.push_back(stoi(s));
	}
	int power;
	cin >> power;

	// ���ҵ�����ɽ���ɽ����ɽ��
	find_mountain(m);

	// ��ѯÿ��ɽ����С�����ķ�
	find_min(m);

	int count = 0;
	// ������������
	for (auto i : cost_m)
	{
		if (i <= power)
		{
			count++;
		}
	}
	cout << count;
}

