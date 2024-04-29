/*
261 ���������ɳ������Ŷ�
��Ŀ������
���������ÿ���˵�������һ�������Ҫ������Ŷӵ��������ֵΪN��ÿ���Ŷӿ�����1�˻�2����ɣ���1����ֻ�ܲμ�1���Ŷӣ��������������ɳ�����֧����Ҫ����Ŷӣ�

����������
5
3 1 5 7 9
8
��һ�������������������Χ[1,500000]
�ڶ����������ÿ���˵�������ÿ��Ԫ�ص�ȡֵ��Χ[1, 500000]������Ĵ�С��Χ[1,500000]
��������ֵΪ�Ŷ�Ҫ����������ֵ����Χ[1, 500000]

���������
3
�������ɳ����Ŷ�����

ʾ��1
���룺
5
3 1 5 7 9
8
�����
3
˵����
3,5���һ�ӣ�1,7���һ�ӣ�9�Լ�һ���ӣ������3
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;	// ������
	cin >> n;
	vector<int> powers(n); // ����ÿ���˵�����
	for (int i = 0; i < n; i++)
	{
		cin >> powers[i];
	}
	int target;	// �Ŷ�Ҫ����������ֵ
	cin >> target;

	// ���
	int res = 0; // �������ɳ����Ŷ�
	sort(powers.begin(), powers.end(), less<int>());
	int l = 0, r = powers.size() - 1;
	while (l < r)
	{
		if (powers[0] >= target)
		{
			res = powers.size();
			break;
		}
		if (powers[r] >= target)
		{
			res++;
			r--;
		}
		else {
			if (powers[l] + powers[r] >= target)
			{
				res++;
				l++;
				r--;
			}
			else {
				l++;
			}
		}
	}
	cout << res;
}
