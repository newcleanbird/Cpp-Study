/*
418�����յĵ��ʸ����������ַ�����ƴд
��Ŀ������
��һ���ַ�������words��һ���ַ���chars��
���������chars�е���ĸƴд��words�е�ĳ�������ʡ����ַ���������ô���Ǿ���Ϊ��������������ʡ�
words���ַ����� a-z Ӣ��Сд��ĸ��ɡ� ����: abc
chars �� a-z Ӣ��Сд��ĸ�� ��?����ɡ�����Ӣ���ʺš�?����ʾ�����ַ����ܹ���ƴдʱ��������һ��Ӣ����ĸ�� ���磺 "?" ���Ե��� "a"����ĸ��
ע�⣺ÿ��ƴдʱ��chars�е�ÿ����ĸ�������ַ���ֻ��ʹ��һ�Ρ�
����ʻ��words�������յ����е��ʵĸ����� û�������κε��ʣ������0��
����������
��1����������words�ĸ�������ΪN��
�ӵ�2�п�ʼ����N+1��������������words��ÿ���ַ���Ԫ�ء�
��N+2�������ַ���chars��
���������
���һ����������ʾ�ʻ��words�������յĵ��ʸ�����
ע�⣺
1 <= words.length <= 100
1 <= words[i].length, chars.length <= 100
�����ַ����ж�������СдӢ����ĸ��Ӣ���ʺ�


ʾ��1
���룺
4
cat
bt
hat
tree
atach??
�����
3
˵����
����ƴд�ַ���"cat"��"bt"��"hat"

ʾ��2
���룺
3
hello
world
cloud
welldonehoneyr
�����
2
˵����
����ƴд�ַ���"hello"��"world"

ʾ��3
���룺
3
apple
car
window
welldoneapplec?
�����
2
˵����
����ƴд�ַ���"apple"��"car"
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool fit_word(string str, map<char, int> mchars, int god_char)
{
	for (auto i : str)
	{
		mchars[i]--;
	}
	int unfit_count = 0;
	for (auto i : mchars)
	{
		if (i.second < 0)
		{
			unfit_count += abs(i.second);
		}
	}
	if (god_char >= unfit_count)
	{
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; i++)
	{
		cin >> words[i];
	}
	string chars;
	cin >> chars;
	int god_char = 0;
	// ͳ��chars������
	map<char, int> mchars;
	for (auto i : chars)
	{
		if (i == '?')
		{
			god_char++;
			continue;
		}
		mchars[i]++;
	}
	// ƥ��
	int count = 0;
	for (auto i : words)
	{
		if (fit_word(i, mchars, god_char))
		{
			count++;
		}
	}
	cout << count;
}