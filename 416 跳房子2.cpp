/*
416��������2
��Ŀ����
�����ӣ�Ҳ�����ɻ�����һ�������ԵĶ�ͯ��Ϸ��Ϸ��������Ҫ�ֶ���غϰ�˳��������1��ֱ�����ӵ����һ��
Ȼ����һ��ѡ���ӵĻ��ᣬֱ�����з��ӱ�ѡ�꣬���������˻�ʤ��
�����ӵĹ����У�����в��ߵ�Υ����Ϊ�������ǰ�غϣ��������ܵ��˼���.���跿�ӵ��ܸ�����count��
С��ÿ�غϿ����������Ĳ�������������steps�У������������Ƿ���һ�ֲ�������ϣ�������С�������غ��������һ��?
����У��������������С�Ĳ������(���ݱ�֤��������С�Ĳ��������Ψһ��)��
ע��:�����еĲ��������ظ����������е�Ԫ�ز����ظ�ʹ��

��������:
��һ������Ϊ�����ܸ���count������int��������
�ڶ�������Ϊÿ�غϿ����������Ĳ���������int������������

�������
������������С������Ҫ��Ĳ������ (˳�򱣳�steps��ԭ��˳��)
����˵��:
count<=10000��
3<=steps.length<=10000��
-100000<=steps[i]<=100000

ʾ��1
����:
9
1,4,5,2,0,2
���:
4,5,0

ʾ��2
����:
9
1,5,2,0,2,4
���:
5,2,2

ʾ��3
����:
12
-1,2,4,9
���:
-1,4,9

ʾ��4��
����
15
1,9,4,25,10,8,7,5
���
1, 4, 10
˵��
���������Ĳ���������
1, 9, 5
�����½Ǳ�֮��Ϊ��0 + 1 + 7 = 8
1, 4, 10
�����½Ǳ�֮��Ϊ��0 + 2 + 4 = 6
��Ϊ 6<8�������[1, 4, 10]��
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int count;
	cin >> count;
	cin.get();
	vector<pair<int, int>> steps;
	vector<int> arr;
	string str;
	getline(cin, str);
	string tmp;
	int idx = 0;
	for (auto i : str)
	{
		if (i != ',')
		{
			tmp += i;
		}
		else {
			steps.push_back({ stoi(tmp),  idx++});
			arr.push_back(stoi(tmp));
			tmp.clear();
		}
	}
	steps.push_back({ stoi(tmp), idx++ });
	arr.push_back(stoi(tmp));
	sort(steps.begin(), steps.end());
	// ����
	vector<int> vi;
	int m_min = 3 * steps.size();
	for (int cur = 0; cur < steps.size(); cur++)
	{
		int l = cur + 1, r = steps.size() - 1;
		while (l < r)
		{
			int tol = steps[cur].first + steps[l].first + steps[r].first;
			int sum_id = steps[cur].second + steps[l].second + steps[r].second;
			if (tol == count)	// �ҵ�һ�����������
			{
				if (sum_id < m_min)
				{
					m_min = sum_id;
					vi = { steps[cur].second , steps[l].second , steps[r].second };
				}
				r--;
			}
			else if (tol > count)
			{
				r--;
			}
			else {
				l++;
			}
		}
	}
	sort(vi.begin(), vi.end());
	cout << arr[vi[0]] << " " << arr[vi[1]] << " " << arr[vi[2]] << endl;
}