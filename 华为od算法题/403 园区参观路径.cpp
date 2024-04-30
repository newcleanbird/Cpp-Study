/*
403��԰���ι�·��
��Ŀ������԰��ĳ���žٰ���Family Day������Ա����������μӣ�����˾԰����Ϊһ�����Σ���ʼ԰�����������Ͻǣ��յ�԰�����������½ǣ������ι�԰��ʱ��ֻ�����Һ�����԰��ǰ���������ʼ԰�����յ�԰�����ж�������ͬ�Ĳι�·����

������������һ��Ϊ԰�����Ϳ�����ÿһ�б�ʾ��԰���Ƿ���Բιۣ�0��ʾ���Բιۣ�1��ʾ���ܲι�
������������Ϊ��ͬ��·������
����˵����
    1 <= ԰���� <= 100
    1 <= ԰���� <= 100

ʾ��
ʾ��1
���룺
3 3
0 0 0
0 1 0
0 0 0
�����2
˵����

ʾ����
4 4
0 0 0 1 
0 0 0 0 
1 0 0 0 
0 0 0 0  

˼·��
���䶯̬�滮
*/
#include<iostream>
#include<vector>

using namespace std;

void print_garden(vector<vector<int>>& garden)
{
    for (auto i : garden)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solution()
{
    int row, col;    // ��(��) �� ��(��)
    cin >> col >> row;
    vector<vector<int>> garden(row + 1, vector<int>(col + 1, 0)); // garden[row][col];
    int tmp;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> tmp;
            garden[i][j] = tmp;
        }
    }

    vector<vector<int>> road(row + 1, vector<int>(col + 1, 0));
    // ��ʼ��
    road[1][1] = 1;
    for (int i = 2; i <= row; i++)
    {
        if (garden[i][1] == 1)
        {
            continue;
        }
        else {
            road[i][1] = road[i - 1][1];
        }
    }
    //print_garden(road);
    for (int j = 2; j <= col; j++)
    {
        if (garden[1][j] == 1)
        {
            continue;
        }
        else {
            road[1][j] = road[1][j - 1];
        }
    }
    //print_garden(road);
    for (int i = 2; i <= row; i++)
    {
        for (int j = 2; j <= col; j++)
        {
            if (garden[i][j] == 1)
            {
                road[i][j] = 0;
            }
            else
            {
                road[i][j] = road[i - 1][j] + road[i][j - 1];
            }
            //print_garden(road);
        }
    }
    cout << road[row][col];
}

void solution_1()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (grid[i][0] == 1) break;
        dp[i][0] = 1;
    }

    for (int j = 0; j < m; ++j) {
        if (grid[0][j] == 1) break;
        dp[0][j] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (grid[i][j] == 1) continue;
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[n - 1][m - 1] << endl;
}

int main()
{
    //solution();
    solution_1();
}