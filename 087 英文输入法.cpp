/*
087 Ӣ�����뷨
��Ŀ������
������������ʵ��Ӣ�����뷨�������빦�ܡ��������£�
�����û�����ĵ���ǰ׺�����������Ӣ�������������û�������ĵ��ʣ����ֵ���������뵽�ĵ������У�������벻����������û�����ĵ���ǰ׺��

ע�⣺
1.  Ӣ�ĵ�������ʱ�����ִ�Сд
2.  ������ʽ�硱don't�����ж�Ϊ�������ʣ���don���͡�t��
3.  ����ĵ������У��������ظ����ʣ���ֻ����Ӣ�ĵ��ʣ������б�����

����������
����Ϊ���С�
��������һ����Ӣ�ĵ���word�ͱ�������ɵ����str��
������һ��Ϊһ��Ӣ�ĵ���ǰ׺pre��

0 < word.length() <= 20
0 < str.length <= 10000
0 < pre <= 20

���������
�������Ҫ��ĵ������л򵥴�ǰ׺�����ڶ��ʱ������֮���Ե����ո�ָ�

ʾ��1
���룺
I love you
He
�����
He
˵����
���û�������Ӣ����䡱I love you������������I������love������you���������ʣ��������û����롰He��������������Ϣ���޷����뵽�κη���Ҫ��ĵ��ʣ��������û�����ĵ���ǰ׺��

ʾ��2
���룺
The furthest distance in the world, Is not between life and death, But when I stand in front of you, Yet you don't know that I love you.
f
�����
front furthest
˵����
���û�������Ӣ����䡱The furthestdistance in the world, Is not between life and death, But when I stand in frontof you, Yet you dont know that I love you.�����������ĵ��ʣ����ϡ�f����Ϊǰ׺�ģ��С�furthest���͡�front�������ֵ��������ڵ��ʼ���ӿո����������Ϊ��frontfurthest����
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
	// ����
	string str;
	getline(cin, str);
	set<string> mset;
	string t_str; // ��ʱ����
	for (auto i : str)
	{
		if (isalpha(i))
		{
			t_str.append(1, i);
		}
		else {
			if (t_str.size() == 0)
			{
				continue;
			}
			mset.insert(t_str);
			t_str.clear();
		}
	}
	if (!t_str.empty())
	{
		mset.insert(t_str);
	}
	string target;
	cin >> target;

	// ���Ҳ�ƥ��
	vector<string> res;
	for (auto &i : mset)
	{
		if (i.substr(0, target.size()) == target)
		{
			res.push_back(i);
		}
	}
	if (res.size() != 0)
	{
		for (auto& i : res)
		{
			cout << i << " ";
		}
	}
	else {
		cout << target;
	}
}