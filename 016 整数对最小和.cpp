/*
16 ��������С��
��Ŀ������

����������������array1��array2������Ԫ�ذ��������С������array1��array2�зֱ�ȡ��һ��Ԫ�ؿɹ���һ��Ԫ�أ�������Ҫȡ��k��Ԫ�أ�����ȡ��������Ԫ����ͣ�����͵���Сֵ
ע�⣺����Ԫ�������Ӧ��array1��array2�е������±����ͬ������Ϊͬһ��Ԫ�ء�

����������

������������array1��array2��ÿ���׸�����Ϊ�����Сsize(0 < size <= 100);
0 < array1[i] <= 1000
0 < array2[i] <= 1000
������һ��Ϊ������k
0 < k <= array1.size() * array2.size()

���������

����Ҫ�����С��

����˵����

 ����

ʾ��1

���룺

3 1 1 2
3 1 2 3
2
�����

4
˵����

�����У���Ҫȡ2��Ԫ��
ȡ��һ�������0��Ԫ����ڶ��������0��Ԫ�����1��Ԫ��[1,1];
ȡ��һ�������1��Ԫ����ڶ��������0��Ԫ�����1��Ԫ��[1,1];
���Ϊ1+1+1+1=4��Ϊ����Ҫ�����С��

˼·��ֱ�ӱ������
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n1, n2, k;
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) cin >> arr1[i];

    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) cin >> arr2[i];

    cin >> k;

    vector<int> pair;
    for (auto i : arr1)
    {
        for (auto j : arr2)
        {
            pair.push_back(i + j);
        }
    }
    sort(pair.begin(), pair.end());

    int res = 0;
    for(int i = 0; i < k; i++)
    {
        res += pair[i];
    }
    cout << res;

}





