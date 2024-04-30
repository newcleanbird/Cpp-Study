/*
425 ʯͷ��������Ϸ
��Ŀ������
ʯͷ��������Ϸ��3�ֳ�ȭ��״��ʯͷ������������ �ֱ�����ĸ A,B,C��ʾ��

��Ϸ����
1����ȭ��״֮���ʤ���������£�A> B��B> C��C> A
��>�� ���һ����ĸ����ʾ���������״�� �ұ�һ����ĸ����ʾ���������״��
2) �������������ҽ���һ�ֳ�ȭ��״����������ȭ��״�������״�������ʤ���ߡ� ������Ϊ��ƽ�֡�
����1 ������ҳ�ȭ�ֱ��� A,B,C�����ڳ�����������ѭ������û���κ�һ������������ȭ�ߣ����ж�Ϊƽ�֡�
����2 ������ң���ȭ�ֱ��� A,B����ȭA�Ļ�ʤ��
����3   ������ң���ȭȫ���� A�� ��Ϊƽ��
3��������ƽ�֣�û��Ӯ�ҡ��ж��ʤ����ʱ��ͬΪӮ�ҡ�
����������
��һ����Ϸ�У�ÿ����ҵ���ϢΪһ�С��������������1000�������Ϣ2���ֶΣ��ÿո������
1�����ID��һ������Ӣ����ĸ��������ɵ��ַ�����
2����ȭ��״����Ӣ�Ĵ�д��ĸ��ʾ��A��B��C��״��
3����ȭʱ�䣺��������ԽС��ʾʱ��Խ��

���磺
abc1 A
xyz B
���ͣ����abc1 ��ȭΪʯͷ��A������� xyz ��ȭΪ������B��
���������
���ΪӮ�ҵ����ID�б�һ����������ÿ��IDһ�У����ַ����������С� ���û��Ӯ�ң����Ϊ��NULL���ַ�����
���磺
abc1
ʾ��1
���룺
s
s
�����
abc1
˵����
A��B�����ƣ�abc1 ʤ��

ʾ��2
���룺
abc1 A
xyz A
�����
NULL
˵����
û����ʤ�ĳ�ȭ��״��ƽ��

ʾ��3
���룺
abc1 A
def A
alic A
xyz B
�����
abc1
alic
def
˵����
AΪ��ʤ����������Ӯ��
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main()
{
	// ����	
	unordered_map<char, vector<string>> player;
	string name;
	char shape;
	while (cin >> name >> shape)
	{
		if (shape < 'A' || shape > 'C') {
			std::cout << "NULL" << std::endl;
			return 0;
		}
		player[shape].push_back(name);
		cin.get();
	}
	// ����
	vector<string> res;
	if (player.size() == 1 || player.size() == 3)
	{
		std::cout << "NULL" << std::endl;
	}
	else {
		if (player.find('A') == player.end()) // �Ҳ���A����ֻ��B �� C����ʤ��ΪB
		{
			res = player['B'];
		}
		else if (player.find('B') == player.end())
		{
			res = player['C'];
		}
		else if (player.find('C') == player.end())
		{
			res = player['A'];
		}
	}
	sort(res.begin(), res.end());
	for (auto i : res)
	{
		cout << i << endl;
	}


}