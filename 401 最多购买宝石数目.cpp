/*
��Ŀ������
��������һ�ű�ʯ����ͬ�ı�ʯ��Ӧ��ͬ�ļ۸񣬱�ʯ�ļ۸���Ϊgems[i],0<=i<n, n = gems.length��ʯ��ͬʱ����0�����������ͬʱ���۶������Ҫ����۵ı�ʯ�������������ͻ������ʯ����Ϊm������ı�ʯ��ű���Ϊgems[i],gems[i+1]...gems[i+m-1](0<=i<n,m<=n)�����㵱ǰӵ������ֵΪvalue��Ǯ����������ܹ��򵽶��ٸ���ʯ,���޷�����ʯ���򷵻�0.

������������һ������n����������Ϊint��ȡֵ��Χ��[0,10 ]����ʾ�����б�ʯ����������
֮��n�зֱ��ʾ�ӵ�0������n-1����ʯ�ļ۸񣬼�gems[0]��gems[n-1]�ļ۸�����Ϊint��ȡֵ��Χ��(0,1000]��
֮��һ������v������Ϊint��ȡֵ��Χ��[0,10 ]��ʾ��ӵ�е�Ǯ��
������������int���͵ķ���ֵ����ʾ���ɹ���ı�ʯ������

ʾ��
ʾ��1
���룺
7
8
4
6
3
1
6
7
10
�����3
˵����
       gems = [8,4,6,3,1,6,7], value = 10
       ��๺��ı�ʯΪgems[2]��gems[4]����gems[3]��gems[5]

ʾ��2
���룺
0
1
�����0
˵����
gems = [], value = 1
��Ϊû�б�ʯ�����Է���0

ʾ��3
���룺
9
6
1
3
1
8
9
3
2
4
15
�����4
˵����gems = [6, 1, 3, 1, 8, 9, 3, 2, 4], value = 15
��๺��ı�ʯΪgems[0]��gems[3]

ʾ��4
���룺
9
1
1
1
1
1
1
1
1
1
10
�����
9
˵����
gems = [1, 1, 1, 1, 1, 1, 1, 1, 1], value = 10
��๺��ı�ʯΪgems[0]��gems[8]����ȫ������

// Ѱ�������У�����С�������������
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int tmp;
    vector<int> vec;
    while (num--)
    {
        cin >> tmp;
        vec.push_back(tmp);
    }
    int money = 0;
    cin >> money;
    // Ѱ�Һ���С�������������
    int count = 0;
    int sum = 0;
    int max = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        count = 0;
        sum = 0;
        for (int j = i; j < vec.size(); j++)
        {
            if (sum + vec[j] <= money)
            {
                count++;
                sum += vec[j];
            }
            else {
                max = max > count ? max : count;
                break;
            }
        }
        max = max > count ? max : count;
    }
    cout << max;
}

