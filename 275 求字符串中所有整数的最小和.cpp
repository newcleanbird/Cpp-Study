/*
275�����ַ�����������������С��

��Ŀ������
�����ַ���s�����s�а���������������С��
˵��
1. �ַ���s��ֻ���� a-z A-Z +- ���֣�
2. �Ϸ�����������
    1�� ������ һ�����߶��0-9��ɣ��� 0 2 3 002 102
    2�������� ���� - ��ͷ�����ֲ�����һ�����߶��0-9��ɣ��� -0 -012 -23 -00023
����������
�������ֵ��ַ���
���������
������������С��
ʾ��1
���룺
bb1234aa
�����
10
˵����
ʾ��2
���룺
bb12-34aa
�����
-31
˵����
1+2+��-34�� = -31

����3��
a-1c2+1-+1+-2s-c3-2+2

�߼���������ĸ�������������֣���ǰ�治�Ƿ��ţ���ֱ����ӣ����и��ţ���������������С�ĸ����Ӻ͡�
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int sum = 0;
    string temp;
    bool minue= false;
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))    // ��������
        {
            if (minue)          // ǰ�и���
            {
                temp += str[i];
            }
            else {  // û�и��ţ�ֱ�����
                sum += str[i] - '0';
            }
        }
        else if (str[i] == '-') // ����
        {
            minue = true;
            temp.clear();
        }
        else  // ��ĸ�������ַ�
        {
            if (minue == true)   // ǰ�и��ŵ��ַ�������ת���ַ������������
            {
                minue = false;
                if (!temp.empty())
                {
                    sum -= stoi(temp);
                }
                
            }
        }
    }
    if (minue == true)
    {
        minue = false;
        if (!temp.empty())
        {
            sum += stoi(temp);
        }
        
    }
    cout << sum;
}
