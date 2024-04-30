/*
468�����Դ���������������������
��Ŀ������
��ĳ����Ŀ���ж�������� tasks �����ʾ����Ҫ�����д������� tasks[i] = [si, ei]��������� si <= day <= ei �е�����һ�촦��������뷵������Դ���������������
ע��һ��������һ������Ĵ���

����������
��һ��Ϊ�������� n��1 <= n <= 100000������ n �б�ʾ��������Ŀ�ʼʱ�����ֹʱ�䣬�� si �� ei ��ʾ��1 <= si <= ei <= 100000��

���������
���Ϊһ����������ʾ���Դ���������������


ʾ��1
���룺
3
1 1
1 2
1 3
�����
3
˵����
��һ�촦������ 1���ڶ��촦������ 2�������촦������ 3��
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task
{
    int start;
    int end;
};

bool cmp(Task& a, Task& b)
{
    if (a.end != b.end)
    {
        return a.end < b.end;
    }
    else
    {
        return a.start < b.start;
    }
    
}

int main() {
    // ��������
    int n;
    cin >> n; // ������������
    vector<Task> tasks;
    int max_time = 0;   // ���Ļ����ʱ��
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tasks.push_back({ x, y });
        max_time = max(max_time, y);
    }
    sort(tasks.begin(), tasks.end(), cmp);

    // ִ��
    priority_queue<int, vector<int>, greater<int>> pq;
    int task_loc = 0;
    int res = 0;
    for (int i = 0; i <= max_time; i++)
    {
        // ������ʱ��Ļ�������
        while (task_loc < n && tasks[task_loc].start <= i)
        {
            pq.push(tasks[task_loc].end);
            task_loc++;
        }
        // ȥ�������ϵĻ�Ƴ�����
        while (!pq.empty() && pq.top() < i)
        {
            pq.pop();
        }
        // ִ������
        if (!pq.empty())
        {
            pq.pop();
            res++;
        }
    }
    cout << res;
    return 0;
}