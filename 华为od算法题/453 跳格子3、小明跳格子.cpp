/*
453 ������3��С��������
��Ŀ������
С����������һ������������Ϸ��ÿ�����������ض��ķ�����score[] = [1 -1 -6 7 -17 7]�������score[0]��ʼ��ÿ��������Ĳ���Ϊk�����㷵��С�������յ�score[n-1]ʱ���ܵõ������÷֡�
ע��
���ӵ��ܳ��ȺͲ����������� [1,  100000]��
ÿ�����ӵķ�����[-10000, 10000]�����У�

����������
6					// ��һ�������ܵĸ�������
1 -1 -6 7 -17 7		// �ڶ�������ÿ�����ӵķ���score[]
2					// ����������������Ĳ���k
���������
14					// ������÷�����С�������score[0]��ʼ������һ����score[1], �ڶ�������score[3],����������score[5]����˵õ������ĵ÷���score[0] + score[1] + score[3] + score[5] = 14

ʾ��1
���룺
6
1 -1 -6 7 -17 7
2
�����
14
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;	// �ܵĸ�������
	cin >> n;
	vector<int> scores(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> scores[i];
	}
	int k;	// ������Ĳ���
	cin >> k;

	// ����
	vector<int> dp(n+1);
	//for (int i = 1; i < k; i++)	// ��ʼ��
	//{
	//	dp[i] = scores[i];
	//}
	for (int i = 1; i <= n; i++)
	{
		int max_dp = -10000;
		for (int j = i-1; j >= i - k && j>=0; j--)
		{
			max_dp = max(max_dp, dp[j]);
		}
		dp[i] = max_dp + scores[i];
	}
	/*for (auto i : dp)
	{
		cout << i << " ";
	}*/
	cout << dp[n];

}