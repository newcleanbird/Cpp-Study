/*
023 ����ߺ������Ŷ�
��Ŀ������

ĳѧУ�����˶��ᣬѧ���ǰ����(1��2��3��n)���б�ʶ������Ҫ��������ɵ͵������У��������ͬ���ˣ����������ᵽ�����У�����������ض���ͬ���ˣ�ά��ԭ�еı��˳���ϵ����������к��ѧ����š�

�����������������У�ÿ��������n����������ɣ�0 < n <= 100������һ�������е���ֵ������ߣ��ڶ��������е���ֵ�������ء�

������������н����ÿ����ֵ����ԭʼ�����е�ѧ����ţ���Ŵ�1��ʼ

����˵����

ʾ��1

���룺
4
100 100 120 130
40 30 60 50

�����2 1 3 4

˵��������ĵ�һ������2��ʾ����ԭʼ���Ϊ2�������Ϊ100������Ϊ30������ˡ��������ͱ��Ϊ1�������һ���������ظ��ᣬ���Ҫ����1ǰ�档

ʾ��2

���룺
3
90 110 90
45 60 45

�����1 3 2

˵����1��3��������ض���ͬ����Ҫ����ԭ��λ�ù�ϵ��1����3ǰ�棬������3 1 2
*/

#include<bits/stdc++.h>

using namespace std;

struct stu
{
    int num;
    int height;
    int weight;
};

bool compare(stu stu1, stu stu2)
{
    if (stu1.height == stu2.height)
    {
        return stu1.weight < stu2.weight;
    }
    else return stu1.height < stu2.height;
}

int main()
{
    int count = 0;
    cin >> count;
    vector<stu> stus(count);
    
    // ����
    int tmp;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        stus[i].num = i+1;
        stus[i].height = tmp;
    }
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        stus[i].weight = tmp;
    }

    // ����
    sort(stus.begin(), stus.end(), compare);

    for (auto &i : stus)
    {
        cout << i.num << " ";
    }

}
