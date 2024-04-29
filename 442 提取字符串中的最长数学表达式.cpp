/*
��Ŀ������
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

���룺
1-2abcd

�����
-1

-1+2-3+4ab-1+1+1+1+1

˼·��
������ʽ
*/

#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<stack>


using namespace std;

string findexpression(string& s)
{
//	regex expRagex(R"(^[+-]?(\d[+-*])+\d$)");	// ������ʽ�Ĺ���
	regex expRagex(R"([+\-]?(\d+[+\-*])+\d+)");
	sregex_iterator beg(s.begin(), s.end(), expRagex);
	sregex_iterator end = sregex_iterator();

	int max_length = 0;
	string longestexpression;
	for (sregex_iterator i = beg; i != end; i++)
	{
		string matchstr = i->str();		// ƥ�䵽���ַ���
		if (matchstr.size() > max_length)
		{
			max_length = matchstr.size();
			longestexpression = matchstr;
		} 
	}
	return longestexpression;
}


// ���ܣ��������ѧ���ʽ��ֵ
long evaluateExpression(const string& expression) {
    if (expression.empty()) return 0; // ������ʽΪ�գ�ֱ�ӷ���0

    stack<long> values;     // ʹ��ջ���洢�м���
    long currentNumber = 0; // ��ǰ����������
    char sign = '+';        // ��ǰ����ǰ�Ĳ�������Ĭ��Ϊ'+'
    for (int i = 0; i <= expression.size(); ++i) {
        char c = i < expression.size() ? expression[i] : '+'; // ��ȡ�ַ����ڱ��ʽĩβ׷��'+'
        if (isdigit(c)) { // ����ַ�������
            currentNumber = currentNumber * 10 + (c - '0'); // �ۼ��γ�����
        }
        else if (c == '+' || c == '-' || c == '*' || i == expression.size()) { // ����ַ��ǲ��������Ѵ��ַ���ĩβ
            if (c != '*' && !values.empty() && values.top() == -1) {
                values.pop(); // ���ջ��Ϊ-1��֮ǰ�ķ���Ϊ���ţ����򵯳�
                sign = '-';  // �����Ÿ�Ϊ����
            }
            switch (sign) {
            case '+': values.push(currentNumber); break; // �ӷ�������ǰ����ѹ��ջ
            case '-': values.push(-currentNumber); break; // ����������ǰ���ֵĸ�ֵѹ��ջ
            case '*':
                long top = values.top(); // ȡ��ջ��Ԫ��
                values.pop(); // ����ջ��Ԫ��
                values.push(top * currentNumber); // ִ�г˷��������ѹ��ջ
                break;
            }
            currentNumber = 0; // ���õ�ǰ����
            sign = c; // ���²�����
        }
    }

    long result = 0; // ��ʼ�����
    while (!values.empty()) {
        result += values.top(); // ��ջ�����������ۼ�
        values.pop(); // ����ջ��Ԫ��
    }
    return result; // ���ؼ�����
}

int main()
{
	string str;
	getline(cin, str);
	string longestexpression = findexpression(str);
	int res = evaluateExpression(str);
	cout << res;
}