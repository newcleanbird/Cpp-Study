/*
424��������Ϸ��� / ����Ͷ�ʷ�ʽ
��Ŀ������
��һ��������Ϸ�������������Ͷ������ǿ��������Ϸ�е��ʲ����ⱻ��̭���֡�����һ��Bank�����ṩ��������Ʋ�Ʒm�����ռ�Ͷ�ʻر���ͬ������N��Ԫ������Ͷ�ʣ��ܽ��ܵ��ܷ���ֵΪX��
��Ҫ�ڿɽ��ܷ�Χ��ѡ�����ŵ�Ͷ�ʷ�ʽ������ر���
˵����
��������Ϸ�У�ÿ��Ͷ�ʷ���ֵ���Ϊ�ܷ���ֵ��
��������Ϸ�У����ֻ��Ͷ��2����Ʋ�Ʒ��
��������Ϸ�У���С��λΪ���������ܲ��ΪС����
Ͷ�ʶ�*�ر���=Ͷ�ʻر�

����������
��һ�У���Ʒ��(ȡֵ��Χ[1, 20])����Ͷ�ʶ�(������ȡֵ��Χ[1, 10000])���ɽ��ܵ��ܷ���(������ȡֵ��Χ[1, 200])
�ڶ��У���ƷͶ�ʻر������У�����Ϊ������ȡֵ��Χ[1,60]
�����У���Ʒ����ֵ���У�����Ϊ������ȡֵ��Χ[1,100]
�����У����Ͷ�ʶ�����У�����Ϊ������ȡֵ��Χ[1,10000]

���������
ÿ����Ʒ��Ͷ�ʶ�����
����˵����
��������Ϸ�У�ÿ��Ͷ�ʷ���ֵ���Ϊ�ܷ���ֵ��
��������Ϸ�У����ֻ��Ͷ��2����Ʋ�Ʒ��
��������Ϸ�У���С��λΪ���������ܲ��ΪС����
Ͷ�ʶ�*�ر���=Ͷ�ʻر�

����
ʾ��1
���룺
5 100 10
10 20 30 40 50
3 4 5 6 10
20 30 20 40 30
�����
0 30 0 40 0
˵����
Ͷ�ʵڶ���30����λ��������40����λ���ܵ�Ͷ�ʷ���Ϊ�������Ϊ4+6=10

Լ����
1. �����ܺͲ���������
2. ������Ͷ�ʻر�
3. �������

˼·������ö��
һ��ʼ����Ŀ����Ϊ��һ����ά����DP��������Ŀ����һ���������������ֻ��Ͷ��������Ʋ�Ʒ����ôҪô����Ͷ��һ����Ҫô����Ͷ���������ͷֱ�ö��������������������ر����ɡ�
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	// ��������
	int m, n, x; // ��Ʒ�� Ͷ�ʶ� �ܷ���
	cin >> m >> n >> x;
	vector<int> return_invest(m);	// ��ƷͶ�ʻر���
	vector<int> risk(m);			// ��Ʒ����ֵ
	vector<int> limit_invest(m);	// ���Ͷ�ʶ��
	for (int i = 0; i < m; i++)
	{
		cin >> return_invest[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> risk[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> limit_invest[i];
	}
	map<int, int> choose; // ����Ͷ�����кͶ��
	int max_return = 0; // ���Ͷ�ʶ�
	// ����
	// Ͷ�ʵ�����Ŀ
	for (int i = 0; i < m; i++)
	{
		if (risk[i] <= x)
		{
			int investI = min(limit_invest[i], n);	// Ͷ�ʵĶ�Ȳ����� Ͷ�ʶ� �� ���Ͷ�ʶ��
			if (investI * return_invest[i] > max_return)
			{
				max_return = investI * return_invest[i];
				choose = {pair<int, int>(i, investI)};
			}
		}
	}
	// Ͷ��������Ŀ
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (risk[i] + risk[j] <= x) // �������
			{
				int investI, investII;	// i �� j ��Ͷ�ʶ�
				if (return_invest[i] > return_invest[j])
				{
					investI = min(limit_invest[i], n);
					investII = min(limit_invest[j], n - investI);
				}
				else {
					investII = min(limit_invest[j], n);
					investI = min(limit_invest[i], n - investII);
				}
				if (investI * return_invest[i] + investII * return_invest[j] > max_return)
				{
					max_return = investI * return_invest[i] + investII * return_invest[j];
					choose = { pair<int, int>(i, investI), pair<int, int>(j, investII) };
				}
			}
		}
	}
	// ������
	for (int i = 0; i < m; i++)
	{
		cout << choose[i] << " ";
	}
}