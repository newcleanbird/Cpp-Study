/*
413 ���������������ĸ߶�
��Ŀ������
���幹�������������������£�
ÿ���ڵ㶼����һ������������һ���µ���ʱ���Ӹ��ڵ�����Ѱ�ң�ֱ���ҵ�һ�����ʵĿսڵ���롣
    ���ҵĹ����ǣ�
        1. �����С�ڽڵ������ȥ500����������ڵ��������
        2. ��������ڽڵ��������500����������ڵ��������
        3. ���򣬽�������ڵ��������
����һϵ�������밴���Ϲ��򣬰�˳�����������У�������һ�����������������������ĸ߶ȡ�

������������һ��Ϊһ����N����ʾ��N������1<=N<=10000
�ڶ���ΪN���ո�ָ���������ÿ�����ķ�ΧΪ[1,10000]

���������������ĸ߶�(���ڵ�ĸ߶�Ϊ1)

����˵����

ʾ��1
���룺
5
5000 2000 5000 8000 1800
�����
3
˵����
���չ�����������£��߶�Ϊ3��

ʾ��2
���룺
3
5000 4000 3000
�����
3
˵����
���չ�����������£��߶�Ϊ3��

ʾ��2
���룺
6
500 1500 2500 3500 4500 5500

*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int val = 0;
    Node* a = nullptr;
    Node* b = nullptr;
    Node* c = nullptr;

public:
    Node(int n)
    {
        val = n;
    }
};

class TernarySearchTree
{
public:
    Node* head = nullptr;
};

TernarySearchTree tree;

int res = 0;

void insertNode(int n)
{
    int height = 1;
    Node* next = tree.head;
    Node* cur;
    if (next == nullptr)
    {
        tree.head = new Node(n);
    }
    else {
        while (1)
        {
            cur = next;
            if (n < cur->val - 500)
            {
                next = next->a;
                height++;
                if (next == nullptr)
                {
                    cur->a = new Node(n);
                    break;
                }
            }
            else if (n > cur->val + 500)
            {
                next = next->c;
                height++;
                if (next == nullptr)
                {
                    cur->c = new Node(n);
                    break;
                }
            }
            else {
                next = next->b;
                height++;
                if (next == nullptr)
                {
                    cur->b = new Node(n);
                    break;
                }
            }
        }
    }
    res = max(res, height);
}

void print()
{
    Node* cur = tree.head;
    queue<Node*> q;
    if (cur != nullptr)
    {
        q.push(cur);
    }
    while (!q.empty())
    {
        cur = q.front(); q.pop();
        cout << cur->val << " ";
        if (cur->a != nullptr)
        {
            q.push(cur->a);
        }
        if (cur->b != nullptr)
        {
            q.push(cur->b);
        }
        if (cur->c != nullptr)
        {
            q.push(cur->c);
        }
    }
}

int main()
{
    int num;
    cin >> num;
    vector<int> nums(num);
    for (int i = 0; i < num; i++)
    {
        cin >> nums[i];
    }
    // ����
    for (auto i : nums)
    {
        insertNode(i);
        print();
        cout << endl;
    }
    cout << res;
}