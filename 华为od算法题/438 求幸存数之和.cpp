/*
438 ���Ҵ���֮��
��Ŀ������
��һ���������� nums��һ������ jump�����Ҵ����� left���������Ϊ��������Ϊ0��λ�ÿ�ʼ��������м����� j �����֣���������Ϊj+1�����֣��������ó������Ӹõ��������Դ����ƣ�ֱ���Ҵ�left����Ϊֹ��Ȼ�󷵻��Ҵ���֮�͡�

Լ����
1��0�ǵ�һ�������㡣
2������������е�֮���� jump �����֣��ѱ��ó������ֲ��������ڡ�
3������ĩβʱ�޷��ͷ��ʼ��ѭ�����ң��������Զ��ѭ����
4������ʼʱ left>len(nums) ����������������̡�

* nums: ���������У����ȷ�Χ [1,10000]
* jump: ��������Χ [1,10000]
* left: �Ҵ���������Χ [0,10000]
* return: �Ҵ���֮��

int sumofleft(int[] nums, int jump, int left)

ʾ��1
���룺
1,2,3,4,5,6,7,8,9
4
3
�����
13
˵������1������Ϊ0����ʼ����, �м����� 4 ������, �������ɾ�� 6, 2, 8, 5, 4, 7 �� ʣ�� 1, 3, 9, ���غ�Ϊ13

���̣�
0,1,2,3,4,5,6,7,8
1,2,3,4,5,6,7,8,9
1,2,3,4,5,7,8,9
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	// ����
	string str;
	getline(cin, str);
	vector<int> nums;
	string tmp;
	for (auto i : str)
	{
		if (i == ',')
		{
			nums.push_back(stoi(tmp));
			tmp.clear();
		}
		else {
			tmp += i;
		}
	}
	nums.push_back(stoi(tmp));
	int jump, left; // ���� jump�����Ҵ����� left
	cin >> jump >> left;
	// ����
	int cur = jump + 1;
	for (int i = nums.size(); i > left; i--)
	{
		nums.erase(nums.begin() + cur);
		cur = (cur + jump) % (nums.size());
	}
	int count = 0;
	for (auto i : nums)
	{
		count += i;
	}
	cout << count;
}