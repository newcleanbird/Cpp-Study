/*
400 С����λ��
��Ŀ������

С���ѳ��٣���ѧ�Ŵ�С�����ų�һ�У�С�������ˣ������С���������⣬���������ҵ���Ӧ���ŵ�λ�á�

�㷨���Ӷ�Ҫ�󲻸���nLog(n)��ѧ��Ϊ�������ͣ����й�ģ<=10000��

����������

1����һ�У��������ųɶ��е�С���ѵ�ѧ�ţ������������ԡ�,��������
       ���磺93 95 97 100 102 123 155
2���ڶ��У�С��ѧ�ţ���110��

���������

���һ�����֣��������λ�ã���1��ʼ����

���磺

6

����˵����

ʾ��1

���룺
93 95 97 100 102 123 155
110
�����
6

˼����
���ֲ��ң��Ҳ�������������Ҵ���Ŀ��ֵ��λ�á�
0 1 2 3   4    5
1 2 3 111 112 113
110
˵����
*/

// ���ֲ���

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec;
    int tmp;
    while (cin >> tmp)
    {
        vec.push_back(tmp);
        if (cin.peek() == '\n') break;
    }
    cin.get();
    int target = 0;
    cin >> target;
    // ���ֲ���
    int mid;
    int left = -1;
    int right = vec.size();
    while (left +1 != right)
    {
        mid = (left + right) / 2;
        if (vec[mid] < target)
        {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    cout << right + 1;
}