﻿/*
430 数的分解（C卷新题）
题目描述
给定一个正整数 n，如果能够分解为 m (m > 1)个连续正整数之和，请输出所有分解中，m最小的分解。
如果给定整数无法分解为连续正整数，则输出字符串 "N”。

输入描述
输入一个整数n (1 ≤ n ≤ 2^30)

输出描述
如果可以分解为若干个连续正整数之和，则输出形如：n = x1 + x2 + ... + xk
例如21=10+11
如果不可以分解，则输出“N"

样例
输入
21
输出
21=10+11
说明
21可以分解为以下几种形式
21=10+11
21=1+2+3+4+5+6
21=6+7+8
其中，21=10+11，是最短的分解序列

思路：数论
首项 a, 项数k 和为 (2a+k-1)k / 2 ，即找到一组a和k使得 (2a+k-1)k = 2N
枚举k，范围为(1, log(2n, 2)) 然后验证a是否满足 (2a+k-1)k = 2N

由关系式可得，k一定是2n的因子
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	n *= 2; // 2n方便计算
	bool has_res = 0;
	for (int k = 2; k * k < n; k++)
	{
		if (n % k != 0)
		{
			continue;
		}
		int a = ((n / k) - k + 1) / 2;
		if ((2 * a + k - 1) * k == n)
		{
			cout << n/2 << "=";
			for (int i = a; i < a+k; i++)
			{
				cout << i;
				if (i != a + k - 1)
				{
					cout << '+';
				}
			}
			has_res = 1;
			break;
		}
	}
	if (has_res == 0)
	{
		cout << "N";
	}
}