/*
226������ѧ�ҿ�������

��Ŀ������
��һ������ѧ�ҷ���һ��ʯ�������Ǻܿ�ϧ������ʱ���Ѿ��ϳɶ�Σ�ԭ�ط���n���Ͽ������ʯ����Ƭ��Ϊ���ƽ�ʯ�����ݣ�����ѧ��ϣ���г����ܰ�æ���㸴ԭ���ʯ����������������ܰ�æ��

����������
��һ������n��n��ʾʯ����Ƭ�ĸ�����
�ڶ�����������ʯ����Ƭ�ϵ���������s������n�顣

���������
���ʯ�����ֵ���ϣ������������У�����ĩ�޶���ո�

����˵����
�������ʯ����Ƭ������ȫ��ͬ����������Ƭ���˳��任��Ӱ�츴ԭ��ı������ݣ�����ͬ��Ƭ���λ�ñ任��Ӱ����ϡ�

ʾ��1
���룺
3
a b c
�����
abc
acb
bac
bca
cab
cba
˵����
��ʯ����Ƭ�ϵ�����Ϊ��a������b������c��ʱ��������С�abc������acb������bac������bca������cab������cba��

ʾ��2
���룺
3
a b a
�����
aab
aba
baa
˵����
��ʯ����Ƭ�ϵ�����Ϊ��a������b������a��ʱ������ܵ�����С�aab������aba������baa��

ʾ��3
���룺
3
a b ab
�����
aabb
abab
abba
baab
baba
˵����
��ʯ����Ƭ�ϵ�����Ϊ��a������b������ab��ʱ������ܵ�����С�aabb������abab������abba������baab������baba��


// ��������
���û��ݷ�(dfs)����������ÿ���������������ռ���ʼ������������·����������Ҫ��ʱֹͣ��
*/

#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

int length_data;
vector<string> vec;

void backtrack(vector<bool>& used, set<string>& s_res, vector<string>& path) {
	if (path.size() == length_data)
	{
		string result;
		for (auto i : path)
		{
			result += i;
		}
		s_res.insert(result);
		return;
	}
	for (int i = 0; i < vec.size(); i++)
	{
		if (used[i]) continue;
		path.push_back(vec[i]);
		used[i] = true;
		backtrack(used, s_res, path);
		path.pop_back();
		used[i] = false;
	}
}

int main()
{
	// ��������
	cin >> length_data;
	cin.get();
	string str;
	getline(cin, str);
	istringstream ss(str);
	string temp;
	while (ss >> temp)
	{
		vec.push_back(temp);
	}
	// dfs
	vector<bool> used(vec.size(), false);
	set<string> s_res;
	vector<string> path;
	backtrack(used, s_res, path);
	for (auto i : s_res)
	{
		cout << i << endl;
	}
}