/*
440��������Ϸ
��Ŀ������
a��b����������7��Ϸ����Ϸ����Ϊa�ȱ�һ����ʼ����x(10<��ʼ����<10000)��b����һ������y(x-y<3),a�ٱ�һ������z(y-z<3)���Դ����ƣ�ֱ������һ������7������7��Ϊʤ�ߣ���bӮ�ñ���������£�һ���ж�������ϣ�

����������
��ʼ����m����100��10<=m<=10000

���������
b��Ӯ�ñ�������ϴ���

����˵����
ʾ��1
���룺
10
�����
1

˼·��
ÿ�ε���Ϊ0~2
*/
#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<pair<int, bool>, int> memo; // map�洢��ʼλ�ú�˭���ִ� �Լ���Ӧ�����������Ϣ

int countwaystowin(int start, bool isaturn) {
    if (start == 7 && !isaturn) return 1;   // ��7��ʼ��b���ִΣ���ʱb��һ��Ӯ����ϡ�
    if (start == 7 && isaturn) return 0;    // ��7��ʼ��a���ִΣ���ʱb������Ӯ��
    if (start < 7) return 0;

    auto key = make_pair(start, isaturn);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int waystowin = 0;
    for (int nextmove = 1; nextmove <= 2; nextmove++) {
        if (isaturn) {
            waystowin += countwaystowin(start - nextmove, false);
        }
        else {
            waystowin += countwaystowin(start - nextmove, true);
        }
    }

    memo[key] = waystowin;
    return waystowin;
}

int main()
{
	int m;  // ��ʼ����
	cin >> m;
    int res = countwaystowin(m, true);
    cout << res;
}


