/*
427�������������
��Ŀ������
XX�л���ͣ���˶�ܷɻ���ÿ�ܷɻ������Լ��ĺ����CA3385��CZ6678��SC6508�ȣ�����ŵ�ǰ2����д��ĸ(�����֣������չ�˾����д������4�����ִ�������Ϣ������XX�л���ֻ��һ��������ܵ���������Ա��Ҫ����Ŀǰͣ���ڻ����ĺ���������ɡ�Ϊ���Ϻ����������ɣ�����Ա���Ȱ��պ��չ�˾����д�������ǰ2����ĸ�������к����������ͬһ���չ�˾�ĺ����ٰ��պ���ŵĺ�4�����ֽ����������ջ�ð��źõĺ�������˳�����дһ�δ����������ĺ������Ϣ��������Ա�����������˳��

˵����
1�����չ�˾��д�����մ��������$ & *, 0~9��A~Z����

������������һ�����뺽����Ϣ����������֮���ö��ţ����������ָ�������ĺ���Ų�����100�����磺
CA3385,CZ6678,SC6508,DU7523,HK4456,MK0987
��ע�������Ϊ6λ���ȣ���4λΪ�����֣������Ǵ��ں�4λ�ظ��ĳ���

���������
CA3385,CZ6678,DU7523,HK4456,MK0987,SC6508

ʾ��1
���룺
CA3385,CZ6678,SC6508,DU7523,HK4456,MK0987
�����
CA3385,CZ6678,DU7523,HK4456,MK0987,SC6508
˵����
����Ŀǰͣ���ڸû����ĺ���ţ����Ϊ���յ�����������������ĺ����

ʾ��2
���룺
MU1087,CA9908,3U0045,FM1703
�����
3U0045,CA9908,FM1703,MU1087
˵����
*/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

bool cmp(string &a, string &b)
{
	string airline1 = a.substr(0, 2);
	string airline2 = b.substr(0, 2);
	string number1 = a.substr(2);
	string number2 = b.substr(2);
	if (airline1 != airline2)
	{
		return airline1 < airline2;
	}
	else {
		return number1 < number2;
	}
}

int main()
{
	string str;
	getline(cin, str);
	vector<string> planes;
	string plane;
	istringstream iss(str);
	while (getline(iss, plane, ','))
	{
		planes.push_back(plane);
	}

	sort(planes.begin(), planes.end(), cmp);

	// ���
	for (int i = 0; i < planes.size(); i++)
	{
		cout << planes[i];
		if (i != planes.size() - 1)
		{
			cout << ',';
		}
	}

}