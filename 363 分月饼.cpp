/*
363�����±�
��Ŀ������
����ڣ���˾���±���m��Ա��������n���±���m<=n��ÿ��Ա�����ٷ�1���±��������Էֶ�������˷ֵ�����±��ĸ�����Max1�����˷ֵ��ڶ����±�������Max2��Max1-Max2 <= 3�����˷ֵ���n-1���±�������Max(n-1)�����˷ֵ���n���±�������Max(n)��Max(n-1) �C Max(n) <= 3, ���ж����ַ��±��ķ�����
����������
ÿһ������m n����ʾm��Ա����n���±���m<=n
���������
����ж������±��ַ�
����˵����
����

ʾ��1
���룺
2 4
�����
2
˵����
�ַ���2�֣�
4=1+3
4=2+2
ע�⣺1+3��3+1��һ�ַַ�

ʾ��2
���룺
3 5
�����
2
˵����
5=1+1+3
5=1+2+2

ʾ��3
���룺
3 12
�����
6
˵����
����Ҫ�����6�ַַ���
12=1+1+10��Max1=10��Max2=1��������Ҫ��
12=1+2+9��Max1=9, Max2=2, ������Ҫ��
12=1+3+8��Max1=8, Max2=3, ������Ҫ��
12=1+4+7��Max1=7, Max2=4, Max3=1������Ҫ��
12=1+5+6��Max1=6, Max2=5, Max3=1��������Ҫ��
12=2+2+8��Max1=8, Max2=2, ������Ҫ��
12=2+3+7��Max1=7, Max2=3, ������Ҫ��
12=2+4+6��Max1=6, Max2=4, Max3=2�� ����Ҫ��
12=2+5+5��Max1=5, Max2=2������Ҫ��
12=3+3+6��Max1=6, Max2=3, ����Ҫ��
12=3+4+5��Max1=5, Max2=4, Max3=3������Ҫ��
12=4+4+4��Max1=4, ����Ҫ��

����˼·    ��̬�滮
�ñȽ��Ͻ�����ѧ���Ա����������Ϊ����ѡ��m�ǵݼ�������Ҫ�������������Ĳ�ֵ������3����m�����ĺ�Ϊn����һ���ж�������ѡ��ʽ��
��������ѡ���i����֮�󣬵�i+1������ȡֵ�͵�i������ȡֵ��أ��������뵽�ö�̬�滮������������⡣˼����̬�滮��������

1.dp����ĺ�����ʲô��
������Ҫ�����������أ�ѡ���˵ڼ������������ȡ��ʲô��ֵ����ǰ�ܺ�Ϊ���١������Ҫ����һ����ά��dp���顣
���� dp[i][j][k] ��ʾ����i����ȡֵΪjʱ��ǰi�������ܺ�Ϊk�ķ�������
�ֱ���i��j��k��������ȡֵ��Χ��ȷ��dp����Ĵ�С��
i��k�Ķ���Ƚ���ȷ����Χ�ֱ��� [1, m]��[1, n]��
ÿ�����ֵ�ȡֵj����СΪ1���������Ϊm-1�����ֶ�ѡ����С��1��ʣ��һ�������ѡ��n-(m-1) = n-m+1����j��ȡֵ��Χ��[1, n+m+1]
�ʹ���dp������һ����СΪ (m+1)*(n-m+2)*(n+1) ����ά���顣

2.��̬ת�Ʒ�����ʲô��
�����i������ȡֵΪj����ô��i+1����ֻ����j��j+1��j+2��j+3�н�����ѡ��
����ʱǰi�������ܺ�Ϊk����ô����i+1����
    ȡ��jʱ��ǰi+1�������ܺ�Ϊk+j������ dp[i+1][j][k+j] += dp[i][j][k]
    ȡ��j+1ʱ��ǰi+1�������ܺ�Ϊk+j+1������ dp[i+1][j+1][k+j+1] += dp[i][j][k]
    ȡ��j+2ʱ��ǰi+1�������ܺ�Ϊk+j+2������ dp[i+1][j+2][k+j+2] += dp[i][j][k]
    ȡ��j+3ʱ��ǰi+1�������ܺ�Ϊk+j+3������ dp[i+1][j+3][k+j+3] += dp[i][j][k]
�����ĸ�ʽ�ӿ��Ժϲ�Ϊһ��ʽ�ӣ��� dp[i+1][j+d][k+j+d] += dp[i][j][k]������d��ȡֵΪ[0,3]
�ȴ�С�������i���ٴ�С�������j���ٴ�С�������k�����������
for i in range(1, m):
    for j in range(1, n-m+2):
        for k in range(i, n+1):
            for d in range(4):
                if j+d < n-m+2 and k+j+d < n+1:
                    dp[i+1][j+d][k+j+d] += dp[i][j][k]

3.dp������γ�ʼ����
i = 0û��ʵ�����壬�����ǡ�
����i = 1���������1�����ֵ�ȡֵj��СΪ1�����Ϊn // m�����������־����ܽӽ��������������ʱj��ȡֵΪ[1, n // m]��
ͬʱ������ֻѡ����һ�����֣���˴�ʱǰi�����ֵ��ܺ�k = j
�ʶ���i = 1�������³�ʼ��

dp = [[[0] * (n+1) for j in range(n-m+2)] for i in range(m+1)]
for j in range(1, n//m+1):
    dp[1][j][j] = 1

4.ʱ�临�Ӷ�
ʱ�ո��Ӷ�
ʱ�临�Ӷȣ�O(NM(N-M))������ѭ������ʱ�临�Ӷȡ�

�ռ临�Ӷȣ�O(NM(N-M))����άdp��������ռ䡣
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;


#include <iostream>
using namespace std;

 ˼·1����̬�滮
int solution(int m, int n)
{
     dp array initialization
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n - m + 2, vector<int>(n + 1, 0)));   // dp[i][j][k] ��i��Ա�����j���±���ǰһ��������k���±�
     int dp[m + 1][n - m + 2][n + 1] = { 0 };

     dp��ʼ������һ��Ա�����ٷ���1���±�
    for (int j = 1; j <= n / m; j++) {
        dp[1][j][j] = 1;
    }

    for (int i = 1; i < m; i++) {   // Ա��:[i, m]
        for (int j = 1; j <= n - m + 1; j++) {  // ��i��Ա���ɷ�����±�����[1, n-m+1]
            for (int k = i; k <= n; k++) {      // �ܷ�����[i, n]
                for (int d = 0; d < 4; d++) {   // ÿ���±��ĵ�������[0, 3]
                    if (j + d < n - m + 2 && k + j + d <= n) {  // 
                        dp[i + 1][j + d][k + j + d] += dp[i][j][k];
                    }
                }
            }
        }
    }

    int ans = 0;    // �ռ����������m��Ա���ܹ�����n���±������е�m��Ա���õ�������δ�1��n-m+1��
    for (int j = 1; j <= n - m + 1; j++) {
        ans += dp[m][j][n];
    }
    return ans;
}


int main() {
    int m, n;       // m��Ա�� n���±�
    cin >> m >> n;
    int ans = solution(m, n);
    
    cout << ans << endl;

    return 0;
}






int res = 0;
vector<int> cakeMap;
int base = 1;
 
void moonCake(int idx, int m, int n);
 
int main() {
    string input;
    getline(cin, input);
    int pos = input.find(" ");
    int m = stoi(input.substr(0, pos));
    int n = stoi(input.substr(pos + 1));
    
    if (m == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    cakeMap.resize(m);
    int space = 3 * m * (m - 1) / 2;
    
    while (base * m + space < n) {
        base++;
    }
    
    for (int first = base; first <= n / m; first++) {
        cakeMap[0] = first;
        moonCake(1, m, n - first);
        cakeMap[0] = 0;
    }
    
    cout << res << endl;
    
    return 0;
}
 
void moonCake(int idx, int m, int n) {
    if (idx == m - 1) {
        if (n - cakeMap[idx - 1] >= 0 && n - cakeMap[idx - 1] <= 3) {
            res++;
        }
        return;
    }

    int lastCakes = cakeMap[idx - 1];
    int restM = m - idx;

    for (int i = lastCakes; i <= min(lastCakes + 3, n / restM); i++) {
        cakeMap[idx] = i;
        moonCake(idx + 1, m, n - i);
        cakeMap[idx] = 0;
    }
}
