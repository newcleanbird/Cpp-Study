/*
358������ճ���ҡ����ӳ���
��Ŀ������
����հ�����ң���һ��������԰����������͵�ԡ���֪���԰��N��������ÿ�����϶������ӣ���������HСʱ�������
����տ��Ծ���������ҵ��ٶ�K����/Сʱ����ÿ��Сʱѡһ���������������ϳԵ�K����������ϵ���������K������ȫ���Ե���������һСʱʣ���ʱ���ﲻ�ٳ��ҡ�
�����ϲ�������ԣ�����������������ǰ�������ӡ�
�뷵������տ�����HСʱ�ڳԵ��������ӵ���С�ٶ�K��KΪ��������������κ��ٶȶ��Բ����������ӣ��򷵻�0��

����������
��һ������ΪN�����֣�N��ʾ��������������N�����ֱ�ʾÿ����������ҵ�������
�ڶ�������Ϊһ�����֣���ʾ�����뿪��ʱ��H��
��������ͨ���ո�ָN��HΪ��������ÿ�����϶�����ң���0<N<10000��0<H<10000��

���������
�Ե�������ҵ���С�ٶ�K���޽�������쳣ʱ���0��

ʾ��1
���룺
2 3 4 5
4
�����
5
˵����

ʾ��2
���룺
2 3 4 5
3
�����
0
˵����

ʾ��3
���룺
30 11 23 4 20
6
�����
23
˵����
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<int>& p, int H)
{
	if (H < p.size()) return 0;
	int speed = 1;
	while(speed++)
	{
		int count = 0;
		for (int i = 0; i < p.size(); i++)
		{
			count += ceil((double)p[i] / speed);
			// cout << "speed" << speed << " " << "p[i]:" << p[i] << " " << ceil((double)p[i] / speed) << endl;
		}
		if (count <= H)
		{
			return speed;
			break;
		}
	}

}


int main()
{
	vector<int> p;		// ����
	int tmp;
	while (cin >> tmp)
	{
		p.push_back(tmp);
		if (cin.get() == '\n') break;
 	}
	int H; 
	cin >> H; // �����뿪��ʱ��
	int res = 0;
	sort(p.begin(), p.end(), less<int>());
	res = solution(p, H);
	cout << res << endl;


	//cout << ceil((double)2 / 3);
}