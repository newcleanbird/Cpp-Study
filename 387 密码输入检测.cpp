/*
387������������
��Ŀ������
�����û�����������input�����������ַ�'<'��ʾ�˸񣬿������ǰһ��������ַ��������д����������յõ��������ַ������ж������Ƿ��������µ����밲ȫҪ��
���밲ȫҪ�����£�
1.���볤��>=8;
2.����������Ҫ����1����д��ĸ;
3.����������Ҫ����1��Сд��ĸ;
4.����������Ҫ����1������;
5.����������Ҫ����1����ĸ����������ķǿհ������ַ�
ע��մ��˸����ȻΪ�մ������û�������ַ�����������<���ַ��Ϳհ��ַ���
������������һ���ַ�����ʾ������û����ݣ�������ַ����С�<���ַ���ʶ�˸��û�������ַ����������հ��ַ������磺ABC<c89%000<
����������������������������ʵ�������ַ�����������������ַ����Ƿ��������밲ȫҪ�����߼��ɡ�,���ָ��� ���磺ABc89%00,true

ʾ��
ʾ��1
���룺ABC<c89%000<
�����ABc89%00,true
˵�������ͣ������C��0�����˸�ȥ��,�����û����������ΪABc89%00�����������밲ȫҪ�����true

ʾ��2
���룺ABC
�����ABC,false
˵�������������밲ȫҪ��

ʾ��3
���룺AB<<
�����,false
˵��������ַ���Ϊ�գ����������밲ȫҪ��

<<
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	// ��������
	string str;
	getline(cin, str);
	// ���봦��
	string key;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '<')
		{
			if (key.size() != 0)
			{
				key.pop_back();
			}			
		}
		else {
			key += str[i];
		}
	}
	// �ж��Ƿ����Ҫ��
	bool upper = false;
	bool lower = false;
	bool digit = false;
	bool special = false;
	for (auto i : key)
	{
		if (isupper(i)) upper = true;
		else if (islower(i)) lower = true;
		else if (isdigit(i)) digit = true;
		else if (!isalnum(i)) special = true;
	}
	bool is_key;
	if (upper && lower && digit && special) {
		is_key = true;
		cout  << key << "," << "true";
	}
	else {
		is_key = false;
		cout << key << "," << "false";
	}
	

}
