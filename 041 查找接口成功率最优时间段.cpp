/*
041 ���ҽӿڳɹ�������ʱ���

��Ŀ������
����֮�佻���Ľӿڳɹ�����Ϊ������ùؼ��������ԣ�ĳ��ʱ����ڵĽӿ�ʧ����ʹ��һ�������ʾ��������ÿ��Ԫ�ض��ǵ�λʱ����ʧ������ֵ�������е���ֵΪ0~100��������
����һ����ֵ(minAverageLost)��ʾĳ��ʱ�����ƽ��ʧ��������ֵ����ƽ��ʧ����С�ڵ���minAverageLost���ҳ��������ʱ��Σ����δ�ҵ���ֱ�ӷ���NULL��

����������
�������������ݣ���һ��Ϊ{minAverageLost}���ڶ���Ϊ{����}������Ԫ��ͨ���ո�(" ")�ָ���minAverageLost��������Ԫ��ȡֵ��ΧΪ0~100������������Ԫ�صĸ������ᳬ��100����

���������
�ҳ�ƽ��ֵС�ڵ���minAverageLost���ʱ��Σ���������±�ԣ���ʽ{beginIndex}-{endIndx}(�±��0��ʼ)�����ͬʱ���ڶ���ʱ��Σ����������±�����±��֮��ʹ�ÿո�(" ")ƴ�ӣ�����±�԰��±��С��������

����˵����

����

ʾ��1

���룺
1
0 1 2 3 4

�����
0-2

˵����

A��������ͣ�minAverageLost=1������[0, 1, 2, 3, 4]
B��ǰ3��Ԫ�ص�ƽ��ֵΪ1����������һ���������������±꣬��0-2

ʾ��2

���룺
2
0 0 100 2 2 99 0 2
�����

0-1 3-4 6-7
˵����

A��������ͣ�minAverageLost=2������[0, 0, 100, 2, 2, 99, 0, 2]
B��ͨ������С�ڵ���2���ʱ���Ϊ�������±�Ϊ0-1��[0, 0]�������±�Ϊ3-4��[2, 2]�������±�Ϊ6-7��[0, 2]�����������ֶ�����ƽ��ֵС�ڵ�2��Ҫ��������0-1 3-4 6-7

˼·����������
Ŀ�����ҵ����Ĵ��ڳ��ȣ�
ʹ�û������ڣ���ѭ�����ұ߽硣
��ѭ������߽硣
ÿ���ȸ��µ�ǰ�����ڵ�ֵ���������ڵ�ֵ�����ٽ�ֵʱ��������Ҫ�����Ҫ����߽������ƶ���
�������ڵ�ֵС�ڵ����ٽ�ֵʱ�����������󡣼�¼��ǰ�����ֵ


*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	// ����
	int minAverageLost;
	cin >> minAverageLost;
	int input;
	vector<int> vec;
	while (cin >> input)
	{
		vec.push_back(input);
		if (cin.peek() != ' ') break;
	}

	int left = 0;
	int sum = 0;	// �����ڵ���ֵ
	int avg = 0;	// �����ڵ�ƽ��ֵ
	int max_length = 0;
	vector<string> res;	// ��Ž��
	for(int right = 0; right < vec.size(); right++)
	{
		sum += vec[right];	// ���㵱ǰ��ֵ
		avg = ceil((double)sum / (right - left + 1));	// ����ƽ��ֵ
		if (avg <= minAverageLost)	// ���������
		{
			if (max_length < right - left + 1)	// �ҵ������Ĵ���
			{
				max_length = right - left + 1;
				res.clear();
				res.push_back(to_string(left) + '-' + to_string(right));
			}
			else if (max_length == right - left + 1)	// �ҵ�ͬ���ȵĴ���
			{
				res.push_back(to_string(left) + '-' + to_string(right));
			}
		}
		else {
			while (avg > minAverageLost && left < right)	// ֻҪƽ��ֵ��������ʣ�һֱ������߽�
			{
				sum -= vec[left];
				left++;
				avg = ceil((double)sum / (right - left + 1));
			}
		}
	}
	for (auto i : res)
	{
		cout << i << " ";
	}





}

/*
ceil()����ȡ���д�ӣ��ǵü�(double)
*/