///*
//441����������
//��Ŀ������
//����һ�����ʽ���������������
//���ʽ���������£�
//1. ���е��������ֽ�Ϊ������(����0)
//2. ��֧����������(+-* /)������
//3. ���Ϊ���������, �������뻯Ϊ����ʽ(����6, 3 / 4, 7 / 8, 90 / 7)
//4. ��������Ϊ0������������������ֱ�����"ERROR"
//5. ��������ռ������е����ֶ����ᳬ�����ͷ�Χ
//
//����������һ���Ϸ�, ����������Ų�ƥ������
//����������
//�ַ�����ʽ�ı��ʽ����֧�� + - * / �����ֿ��ܳ�����λ�����ܴ��пո�û�и���
//����С��200���ַ�
//
//���������
//���ʽ�����������ʽ���
//������Ϊ��������ôֱ���������
//������Ϊ��������ô���ӷ�ĸ������Լ�֣�����Ϊ�ٷ��������ɱ��Ϊ������
//��������Ǹ���, ���ŷ�����ǰ��
//
//ʾ��1
//���룺
//1 + 5 * 7 / 8
//�����
//43 / 8
//˵����
//
//ʾ��2
//���룺
//1 / (0 - 5)
//�����
//- 1 / 5
//˵����
//������Ҫ�ᵽ��ǰ��
//
//ʾ��3
//���룺
//1 * (3 * 4 / (8 - (7 + 0)))
//�����
//12
//˵����
//ע�����ſ��Զ���Ƕ��
//
//˼·��������׺���ʽ
//1. ����ջ��ʵ��ת��
//ת��������Ҫ�õ�ջ������ʹ������ջ��stack ջ��������������post ջ����������ĺ�׺���ʽ������������£�
//������ɨ����׺���ʽ��
//���ǲ�������ֱ�Ӵ��� post ջ��
//�����������
//��1����������������� ( , ��ֱ�Ӵ��� stack ջ��
//��2����������������� )���� stack ջ�� ( ǰ�������������ջ������ post ջ��
//��3�����������Ϊ�����ţ��򽫸�������� stack ջ����������Ƚϣ�������ջ�����������ֱ�Ӵ��� stack ջ������ջ���������ջ����ջ�е���Ԫ��ֱ���������ָ������ȼ���Ԫ��(����ջΪ��)Ϊֹ�������� post ջ��
//��4����ɨ�����stack ջ�л��������ʱ���������������ջ������ post ջ��
//
//*/
//
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;


int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    /*else if (op == '^')
        return 3;*/
    else
        return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;
    for (size_t i = 0; i < infix.length(); ++i) {
        if (isdigit(infix[i])) {
            // �����λ�������
            while (i + 1 < infix.length() && isdigit(infix[i + 1])) {
                postfix += infix[i];
                ++i;
            }
            postfix += infix[i]; // ������һ������
            postfix += ' '; // ��ӿո�ָ���
        }
        else if (infix[i] == '(') {
            operators.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' '; // ��ӿո�ָ���
                operators.pop();
            }
            operators.pop(); // ����������
        }
        else {
            while (!operators.empty() && getPrecedence(infix[i]) <= getPrecedence(operators.top())) {
                postfix += operators.top();
                postfix += ' '; // ��ӿո�ָ���
                operators.pop();
            }
            operators.push(infix[i]);
        }
    }
    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' '; // ��ӿո�ָ���
        operators.pop();
    }
    return postfix;
}

/*�����׺���ʽ�����к�׺���ʽ�����ֿ����ж�λ�����ֺͷ���֮���ÿո���*/
int calculatePostfixExpression(const std::string& expression) {
    std::stack<int> numStack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int num2 = numStack.top();
            numStack.pop();
            int num1 = numStack.top();
            numStack.pop();

            if (token == "+") {
                numStack.push(num1 + num2);
            }
            else if (token == "-") {
                numStack.push(num1 - num2);
            }
            else if (token == "*") {
                numStack.push(num1 * num2);
            }
            else if (token == "/") {
                numStack.push(num1 / num2);
            }
        }
        else {
            numStack.push(std::stoi(token));
        }
    }

    return numStack.top();
}

/*�����׺���ʽ�����к�׺���ʽ�����ֿ����ж�λ�����ֺͷ���֮���ÿո������������������������ʽ��ʾ*/
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

std::pair<int, int> simplifyFraction(int numerator, int denominator) {
    int g = gcd(numerator, denominator);
    return std::make_pair(numerator / g, denominator / g);
}

int calculatePostfixExpression_1(const std::string& expression) {
    std::stack<std::pair<int, int>> numStack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int num2 = numStack.top().first;
            int den2 = numStack.top().second;
            numStack.pop();
            int num1 = numStack.top().first;
            int den1 = numStack.top().second;
            numStack.pop();

            if (token == "+") {
                numStack.push(simplifyFraction(num1 * den2 + num2 * den1, den1 * den2));
            }
            else if (token == "-") {
                numStack.push(simplifyFraction(num1 * den2 - num2 * den1, den1 * den2));
            }
            else if (token == "*") {
                numStack.push(simplifyFraction(num1 * num2, den1 * den2));
            }
            else if (token == "/") {
                numStack.push(simplifyFraction(num1 * den2, den1 * num2));
            }
        }
        else {
            std::istringstream issNum(token);
            int numerator, denominator;
            issNum >> numerator;
            issNum.ignore();
            issNum >> denominator;
            numStack.push(std::make_pair(numerator, denominator));
        }
    }

    return numStack.top().first;
}

int main() {
    //string infixExpression = "3+45*67";
    string infixExpression = "1+5*7/8";
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Infix expression: " << infixExpression << endl;
    cout << "Postfix expression: " << postfixExpression << endl;
    //cout << "���ʽ��ֵ��" << calculatePostfixExpression(postfixExpression) << endl;
    cout << "���ʽ��ֵ��" << calculatePostfixExpression_1(postfixExpression) << endl;
    return 0;
}

