/*
42 GPU��������
��Ŀ����
Ϊ�˳�ַ���GPU��������Ҫ�����ܶ�Ľ����񽻸�GPUִ�У�����һ���������飬����Ԫ�ر�ʾ����1s�������������������ÿ�붼���������񡣼���GPU���һ��ִ��n������һ��ִ�к�ʱ1s���ڱ�֤GPU�����е�����£�������Ҫ�೤ʱ��ִ����ɡ�

��������
��һ������ΪGPU���ִ�е����������ȡֵ��Χ[1,1 0000]
�ڶ�������Ϊ��������ĳ��ȣ�ȡֵ��Χ[1,1 0000]
����������Ϊ�������飬���ַ�Χ[1,1 0000]

�������
ִ������������������Ҫ������

ʾ��1
����
3
5
1 2 3 4 5
���
6

ʾ��2
����
4
5
5 4 1 1 1
���
5

˼����
����ÿ���gpu��������ģ����̣�ÿ������������飬����������ʣ�����ʱ�䡣

*/
#include<iostream>
#include<vector>


using namespace std;

int main()
{
	int m_work;	// ÿ��gpu���������
	int w_len;	// �������鳤��
	cin >> m_work >> w_len;
	vector<int> vec(w_len);
	for (auto& i : vec)
	{
		cin >> i;
	}

	int time = 0;	// ��ʱ��
	int remain = 0;	// ʣ���ʱ��
	for (auto i : vec)
	{
		if (remain + i > m_work)
		{
			remain = remain + i - m_work;
		}
		else {
			remain = 0;
		}
		time++;
	}
	// ����ʱ��
	time += ceil((double)remain / m_work);
	cout << time;

}