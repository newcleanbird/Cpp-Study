/*
423����Ŀ���� �����������й���������
��Ŀ������
��Ŀ�鹲��N��������Ա����Ŀ����ӵ���M������������ÿ������Ĺ�������ͬ����ÿ������ֻ����һ��������Ա������ɣ����ܶ��˺������ٶ���������ֱ�����κ��Ⱥ�������ϵ��������㷨������Ŀ������й������ţ�ʹ������Ŀ�������ٵ�ʱ�佻����

����������
��һ������ΪM������Ĺ���������λΪ�죬�ö��Ÿ�����
���磺X1 X2 X3 .... Xm
��ʾ����M������ÿ������Ĺ������ֱ�ΪX1�죬X2��......Xm�졣����0<M<30��0<Xm<200
�ڶ�������Ϊ��Ŀ����Ա����N
���磺
5
��ʾ����5��Ա��������0<N<10

���������
���������й���������
���磺
25
��ʾ�����Ҫ25����������й���

ʾ��1
���룺
6 2 7 7 9 3 2 1 3 11 4
2
�����
28
˵����
������λԱ��������һλ�������� 6 2 7 7 3 2 1 ����Ҫ28����ɣ���һλ�������� 9 3 11 4 ����Ҫ27����ɣ���������й���������Ҫ28�졣


˼·��
����˼·
����һ�������൱��ɬ����Ŀ���������ˣ�

�ñȽϼ�����ѧ�������������ǣ�������X1, X2, X3, ... ,Xm��ΪN���֣����������飬��Ҫ������������ÿһ���ֵĺ�Ϊsum1, sum2, ..., sumN��Ҫ���ҵ�һ�ַ��䷽ʽʹ��max(sum1, sum2, ..., sumN)��С��

��һ��򵥵Ļ���˵��������С����������͵����ֵ����������һ��Ҫ�뵽�ö�������ɡ�

������ת��Ϊ��������Ҫ�ҵ�һ����ֵk��һ���˵����������������ԭ����nums���Ա���ΪN���֣������N���ˣ���ʹ����N���ֵĸ�����͵����ֵ�����ᳬ��k��ÿ���˸��ԵĹ��������ᳬ��k����

��Ȼk��ѡ����һ�����������⣺

��k�ǳ���ʱ��ԭ����nums������η��䶼�������Ҫ��
��k�ǳ�Сʱ��ԭ����nums������ô���䶼�޷����Ҫ��
��Ȼ����һ���ٽ�ֵk��ʹ�ô���nums�ķ�����ǡ�����Ҫ��
����ϣ���ҵ������ֵk�������Ҫ��k���ж��ֲ��ң����ֲ��ҵķ�ΧΪ[max(nums), sum(nums)]����

k = max(nums)ʱ���ܹ�����Ϊm = len(nums)���֣���Ҫm������������й�����
k = sum(nums)ʱ���ܹ�����Ϊ1���֣�ֻ��1���˿���������й�����
���������ֹ��̵�̰��������Ϊ��������ѡ������ֵkʱ������nums�ܷ񱻷ָ����N���֣�

�������ͺ͡�̰�ġ�2023B-�������Լ�ı��ݷ���������ȫһ���ˣ������Ϊ
*/

 ����Ϊ m ����Ʒ�ܷ�ŵ� N �������У�ÿ�����ӵ������������Ϊ x
 �����麯�����ж���x�����Ƿ������n���˵�m������

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;

bool subQuestion(int k, vector<int>& nums, int m, int N) {
    int ans = 0;
    vector<int> check(m, 0);

    for (int i = 0; i < m; i++) {
        if (check[i] == 1) continue;
        ans++;
        int curSum = 0;
        int j = i;
        while (j < m) {
            if (check[j] == 1) {
                j++;
                continue;
            }
            if (nums[j] + curSum > k) {
                j++;
            }
            else {
                curSum += nums[j];
                check[j] = 1;
                j++;
            }
        }
    }
    return ans <= N;
}

void solution_1()
{
    vector<int> nums;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }
    int m = nums.size();
    int N;
    cin >> N;

    sort(nums.begin(), nums.end(), greater<int>());
    int left = nums[0], right = accumulate(nums.begin(), nums.end(), 0) + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (subQuestion(mid, nums, m, N)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}

void solution_2()
{
     M������Ĺ�����
    vector<int> w;
    int tmp;
    while (cin >> tmp)
    {
        w.push_back(tmp);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    int n; // ��Ŀ����Ա����N
    cin >> n;
    sort(w.begin(), w.end(), greater<int>());
     ����
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(0);
    }
    for (int i = 0; i < w.size(); i++)
    {
        int min = pq.top(); pq.pop();
        min += w[i];
        pq.push(min);
    }
    int res = 0;
    while (!pq.empty())
    {
        res = max(res, pq.top());
        pq.pop();
    }
    cout << res;
}

int main() {
    solution_2();
}