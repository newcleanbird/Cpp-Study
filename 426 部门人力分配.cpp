/*
426 ������������
��Ŀ������
�����ڽ������󿪷�ʱ��Ҫ�����������š���ǰ������Ҫ���N������������requirements[]��ʾ��requirements[i]��ʾ��i������Ĺ�������С����λ�����¡�
�ⲿ��������Ҫ��M��������ɿ����������������ź�ÿ���µ������ǹ̶��ġ�
ĿǰҪ��ÿ���������2�����󿪷�������ÿ������Ҫ��ɵ������ܳ���������������ﲿ���������������󿪷����ȵ�����£�ÿ������Ҫ����С�����Ƕ��٣�
���������������һ��ΪM��requirements��M��ʾ��Ҫ����ʱ��Ҫ��requirements��ʾÿ������������С��NΪrequirements����
1 <= N/2 <= M <= N <= 10^4
1 <= requirements[i] <= 10^9
�������������ÿ��������ݣ����������Ҫ����������ĩ�޶���ո�

ʾ��1
���룺
3
3 5 3 4
�����6
˵���������������У���һ����������3��ʾ����ʱ��Ҫ�󣬵ڶ����������ݱ�ʾ����������С���������һ�У���ʾ������������

3
1 2 3 4

// ˼·��������+˫ָ��
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void solution()
{
	int m;	// ʱ��
	cin >> m;
	int tmp;
	priority_queue<int, vector<int>, greater<int>> que;
	while (cin >> tmp)
	{
		que.push(tmp);
		if (cin.peek() == '\n') break;
	}

	// ����
	int count; // ��Ҫ������
	int tmp1, tmp2;
	while (que.size() > m)
	{
		tmp1 = que.top();
		que.pop();
		tmp2 = que.top();
		que.pop();
		que.push(tmp1 + tmp2);
	}
	while (!que.empty())
	{
		count = max(count, que.top());
		que.pop();
	}
	cout << count;
}

void solution_1()
{
    int m;
    std::cin >> m;
    std::vector<int> w;
    int x;
    while (std::cin >> x) {
        w.push_back(x);
    }

    std::sort(w.begin(), w.end());
    int n = w.size();
    int l = w[n - 1];
    int r = 1e9;

    while (l < r) {
        int mid = (l + r) / 2;
        if (check(w, m, mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    std::cout << l << std::endl;
}

int check(const std::vector<int>& w, int m, int x) {
    int cnt = 0;
    int l = 0;
    int r = w.size() - 1;

    while (l <= r) {
        if (w[l] + w[r] <= x) {
            l++;
            r--;
        } else {
            r--;
        }
        cnt++;
    }

    return cnt <= m;
}

int main()
{
	// solution();
    solution_1();

}