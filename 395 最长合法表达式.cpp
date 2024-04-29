/*
395����Ϸ����ʽ / ��ȡ�ַ����е����ѧ���ʽ������
��ȡ�ַ����е���Ϸ�����ѧ���ʽ���ַ���������ģ���������ʽ��ֵ�����û�У��򷵻�0
����ѧ���ʽֻ�ܰ�����������
0-9���֣����� +-*
˵����
1. �������֣���������������long
2. ����ж������һ���ģ��뷵�ص�һ�����ʽ�Ľ��
3. ��ѧ���ʽ����������ģ��Ϸ���
4. �����������������֣��� +--+1 �ǲ��Ϸ���

����������
�ַ���

���������
���ʽֵ

����˵����

ʾ��1
���룺
1-2abcd
�����
-1
˵����

ab1-2+3-4+ba-1-2-3-4+5*5+99

˼·��
ʹ��������ʽ����ƥ��

�ѵ㣺�����ַ������ʽ��ֵ
1. ʹ��ջ(��Ϊ����û�����ţ���˿���ֱ�ӽ�)
2. ��׺ת��׺����׺��ֵ��(����˼·)


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>
#include <stack>

using namespace std;

//vector<char> chars{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*' };
//
//bool is_exp(string& str, int start, int end)
//{
//	bool is_sign = false;
//	for (int i = start; i <= end; i++)
//	{
//		if (find(chars.begin(), chars.end(), str[i]) != chars.end())	// ���Ų����ڣ����ǺϷ����ʽ
//		{
//			return false;
//		}
//		else if (isdigit(str[i]) && is_sign)		// ��ǰ�ַ������֣���һ���Ƿ���
//		{
//			is_sign = false;
//		}
//		else if (!isdigit(str[i]) && is_sign)		// ��ǰ�Ƿ��ţ���һ��������
//		{
//			is_sign = true;
//		}
//		else if (isdigit(str[i]) && is_sign)
//		{
//			return false;
//		}
//		else if (!isdigit(str[i]) && !is_sign)
//		{
//			return false;
//		}
//	}
//}
// �޽��ַ������Ƴ��ո�
void trim(string& s)
{
    int index = 0;
    if (!s.empty())
    {
        while ((index = s.find(' ', index)) != string::npos)
        {
            s.erase(index, 1);
        }
    }
}

// �����ַ������ʽ��ֵ
int calculate(const std::string& expression) {
    std::stack<int> nums;
    std::stack<char> ops;
    int num = 0;
    char op = '+';

    for (int i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        if ((!isdigit(c) && c != ' ') || i == expression.size() - 1) {
            switch (op) {
            case '+':
                nums.push(num);
                break;
            case '-':
                nums.push(-num);
                break;
            case '*':
                nums.top() *= num;
                break;
            case '/':
                nums.top() /= num;
                break;
            }
            op = c;
            num = 0;
        }
    }

    int result = 0;
    while (!nums.empty()) {
        result += nums.top();
        nums.pop();
    }
    return result;
}

int main()
{
    //����
	string s;    // �洢������ַ���
	getline(cin, s);
    
    // ����
    int maxExpLen = 0;
    long ans = 0;
    string maxstr;
    for (int i = 0; i < s.length(); i++) 
    {
        for (int j = i; j < s.length(); j++) 
        {
            string sub = s.substr(i, j - i + 1);
            regex reg(R"(^[+-]?(\d+[+\-*])+\d+$)");    // +- ���� +-* ����
            if (regex_match(sub, reg) && sub.length() > maxExpLen) {
                maxExpLen = j - i + 1;
                //ans = calculate(sub);
                maxstr = sub;
            }
        }
    }
    ans = calculate(maxstr);
    cout << "manstr:" << maxstr << " =" << ans << endl;
    cout << "maxExpLen:" << maxExpLen<< endl;

    return 0;



}
