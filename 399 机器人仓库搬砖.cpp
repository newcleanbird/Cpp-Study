/*
399�������˲ֿ��ש
��Ŀ������
�����˰�ש��һ����N��ש�����N����ͬ�Ĳֿ��У���i��ש����bricks[i]��שͷ��Ҫ����8Сʱ�ڰ��ꡣ������ÿСʱ�ܰ�ש������ȡ�����ж��������񣬻�����һ��Сʱ��ֻ����һ���ֿ��а�ש�������˵�������ÿСʱ����һ����������ֻ����һ��Сʱ��Ч��Ϊʹ�û����������С��������Сÿ�β��������������
Ϊ�˱�����8Сʱ������ɰ�ש���������ÿСʱ�������˳��ܵ���С����������
��ע��
1�����迼�ǻ����˲���������ĺ�ʱ��
2�����迼�ǻ����˰�ש�ĺ�ʱ��
3��������ÿСʱ����������ֻ����һ��Сʱ����Ч��
����������
��������Ϊ��30 12 25 8 19��һ���������飬�����е�ÿ�����ִ����i��ש�ĸ�����ÿ��ש�ĸ���������100��
���������
�����8Сʱ����ɰ�ש���񣬻�����ÿСʱ������Ҫ����ٸ�������
���8��Сʱ��������ζ���ɲ��������������-1����
����˵����
ʾ��1
���룺
30 12 25 8 19
�����
15
˵����
ʾ��2
���룺
10 12 25 8 19 8 6 4 17 19 20 30
�����
-1
˵����
ש�Ķ���Ϊ12�Ѵ����12���ֿ��У�������һ��Сʱ��ֻ����һ���ֿ��ש���������������

����˼·��
1. ���ַ������ٶ�
�ٶȵ�������[1, max],ʹ�ö��������ٶ�
	����ٶȿ��������꣬˵���ٶȴ��ˣ���Ҫ�����ٶȣ���С����ٶ�������һ�룬������ܣ����������ٶ�������һ��


*/
#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

bool can_fin(vector<int>& work, int count, int power)
{
	int hour = 0;
	for (auto i : work)
	{
		hour += (int)ceil((double)i / power);
	}
	return hour <= count;
}

// ʹ�ö�������
int calculate(vector<int>& work, int count)
{
	if (work.size() > count) return -1;
	int left = 0;
	int right = *max_element(work.begin(), work.end());
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (can_fin(work, count, mid))	// �����
		{
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

// ʹ�����ȶ��ж�������
int calculate_1(vector<int>& work, int count)
{
	priority_queue<double> mque(work.begin(), work.end());
	int max;
	while (mque.size() <= 8)
	{
		max = mque.top();
		mque.pop();
		mque.push(max/2);
		mque.push(max/2);
	}
	return ceil(mque.top());
}

int main()
{
	// ����
	vector<int> work;
	int tmp;
	while (cin >> tmp)
	{
		work.push_back(tmp);
		if (cin.peek() == '\n')
			break;
	}
	int count = 8; // ��Ҫ8Сʱ
	cout << calculate_1(work, count);
}