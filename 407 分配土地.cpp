/*
407����������
��Ŀ������
��ǰ�и���ׯ��������ϲ���ڸ�������ϲ���С���ӣ������ϱ�ʶ�˸��ֲ�ͬ�����֡�ĳ�켯����������������ͬ���ֵ���С�����ε����صķ����Ϊ���������޴��׵Ĵ������ʣ��˴η������أ��������׵Ĵ�������������������

����������
��һ������m��n��m������ӵ����صĳ���n�������صĿ�
�ڶ��п�ʼ�����ͼ�ϵľ����ʶ

���������
�����Ҫ����������������������ͬ�������ӵ���С�����е���������

����˵����
�����ϵ�����Ϊ1-500�����ر߳�������500
δ�����ӵ�������0��ʶ

ʾ��1
���룺
3 3
1 0 1
0 0 0
0 1 0
�����
9
˵����
�����ϵ�����Ϊ1��������ֱ�Ϊ(0,0)��(2,1)�Լ�(0,2)��Ϊ�˸����������ӣ�������Ҫ���ǵĺ�����Ϊ0��2��������Ϊ0��2���������Ϊ9����(2-0+1)*(2-0+1)=9��

ʾ��2
���룺
3 3
1 0 2
0 0 0
0 3 4
�����
1
˵����
���ڲ����ڳɶԵ�С���ӣ��ʶ�����1����һ�����ص������


*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

void allocate_land() {
    int a, b;
    cin >> a >> b;
    vector<int> nums(501, 0);
    vector<int> max_row(501, 0);
    vector<int> max_col(501, 0);
    vector<int> min_row(501, 502);
    vector<int> min_col(501, 502);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            int c;
            cin >> c;
            nums[c] = 1;
            max_row[c] = max(max_row[c], i);
            max_col[c] = max(max_col[c], j);
            min_row[c] = min(min_row[c], i);
            min_col[c] = min(min_col[c], j);
        }
    }

    int max_area = 0;
    for (int i = 1; i <= 500; i++) {
        if (nums[i] == 1) {
            max_area = max(max_area, (max_row[i] - min_row[i] + 1) * (max_col[i] - min_col[i] + 1));
        }
    }

    cout << max_area << endl;
}

int main() {
    allocate_land();
    return 0;
}