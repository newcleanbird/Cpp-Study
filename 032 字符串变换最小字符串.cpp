/*
32���ַ����任��С�ַ���

��Ŀ������

����һ���ַ���s�����ֻ�ܽ���һ�α任�����ر任���ܵõ�����С�ַ����������ֵ�����бȽϣ����任���򣺽����ַ���������������ͬλ�õ��ַ���

����������һ��Сд��ĸ��ɵ��ַ���s

�������������Ҫ����б任�õ�����С�ַ���

����˵����s�Ƕ���Сд�ַ����
                  1<=s.length<=1000

ʾ��

ʾ��1

���룺abcdef

�����abcdef

˵����abcdef�Ѿ�����С�ַ���������Ҫ����

ʾ��2

���룺bcdefa

�����acdefb

˵����a��b����λ�ý��������Եȵ���С�ַ���

ʾ��3��
cdefgba
adefgbc

˼·��
// ����ʲô����µ��ַ�����С�أ�
�����ֵ�����λ��Ϊ�ڱ�����������鿴��û�к��Լ������С�ģ�������򽻻�֮��Ϊ��С�ַ�����
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    // ����
    string str;
    getline(cin, str);

    // �ж�
    char min_tmp = 'z'+1;
    int seq = 0;
    bool is_find = false;
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i+1; j < str.size(); j++)
        {
            if (str[j] < str[i])
            {
                is_find = true;
                if (str[j] < min_tmp)
                {
                    seq = j;
                    min_tmp = str[j];
                }
            }
        }
        if (is_find)
        {
            swap(str[seq], str[i]);
            break;
        }
    }
    cout << str;
}