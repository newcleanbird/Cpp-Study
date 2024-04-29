/*
458�����ڴ�����
��Ŀ������
��һ���ܿռ�Ϊ100�ֽڵĶѣ���Ҫ����������һ���ڴ棬�ڴ����ԭ��Ϊ���Ƚ�����ǰһ����ʹ���ڴ����ռ��㹻����ӽ������С�Ŀ����ڴ档

����������
���룺
��1����1����������ʾ����������ڴ��ֽ�����
��2��N�����ÿո�ָ��������������ʾ��ǰ�ѷ�����ڴ�������ÿһ�б�ʾһ���ѷ���������ڴ�ռ䣬ÿ�еĵ�1�͵�2�������ֱ��ʾƫ�Ƶ�ַ���ڴ���С���磺
0 1
3 2
��ʾ0ƫ�Ƶ�ַ��ʼ��1���ֽں�3ƫ�Ƶ�ַ��ʼ��2���ֽ��ѱ����䣬�����ڴ���С�

���������
���:
������ɹ���������뵽�ڴ��ƫ�ƣ�������ʧ�ܣ����-1��

����˵����
1.��������Ϣ���Ϸ�����Ч��������ʧ�ܡ�
2.��û���㹻�Ŀռ乩���䣬������ʧ�ܡ�
3.���ڴ���Ϣ�������ص����зǷ�ֵ�ȶ�����Ч���롣

ʾ��1
���룺
1
0 1
3 2
�����
1
˵����
������ʹ�õ������ڴ���ƫ�ƴ�0��ʼ1�ֽں�ƫ�ƴ�3��ʼ��2�ֽڣ����е������ڴ���ƫ�ƴ�1��ʼ2���ֽں�ƫ�ƴ�5��ʼ95�ֽڣ����ݷ���ԭ����������ڴ�Ӧ��1��ʼ����1���ֽڣ��������ƫ��Ϊ1.

��ĿҪ��
1. �ܶѴ�С������һ���ܹ�100�ֽڴ�С�Ķ��ڴ档
2. �ڴ����ԭ��
   - ����ѡ�������ǰһ����ʹ���ڴ�Ŀ����ڴ�顣
   - ѡ������ڴ������С�ġ�����������������Ŀ顣

���ⲽ��
1. ��ȡ���룺
   - ��ȡ������ڴ��С��ȷ������һ���Ϸ����������Ҳ������ܶѴ�С��
   - ��ȡ�ѷ�����ڴ����Ϣ������ÿ�������ʼλ�úʹ�С��
2. ��֤����Ϸ��ԣ�
   - ȷ���ڴ�����ʼ��ַ�ʹ�С�ǺϷ��ģ����ҿ鲻�����ѵĽ��ޡ�
   - ����Ƿ����ص����ڴ�顣
3. ��������ڴ�飺
   - ���ѷ����ڴ��֮���Լ����һ���ڴ����ѱ߽�֮��Ѱ�ҿ����ڴ�顣������Щ���п�Ĵ�С����ʼ��ַ��
4. ѡ����ʵĿ��п飺
   - �����ڴ����ԭ�򣬴ӿ����ڴ����ѡ����С�ġ��㹻����ڴ����з��䡣
5. ��������
   - ����ҵ����ʵĿ����ڴ�飬������ÿ����ʼ��ַ��������� -1��
��Ե���
- �Ƿ����룺���ڴ�����ʼ��ַ���С�Ǹ����������Ѵ�С�ȡ�
- �ڴ���ص���ͨ������ͱȽϼ���ص���
- �ռ䲻�㣺�����п��п鶼��������������ʱ���� -1��
- û���ѷ�����ڴ�飺���û���κ��ѷ�����ڴ�飬�����ѱ���Ϊһ����Ŀ��п顣
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
    int start;
    int size;
};

int main() {
    int requestSize;
    cin >> requestSize; // ��ȡ������ڴ��С
    if (requestSize <= 0 || requestSize > 100) {
        cout << -1 << endl;
        return 0;
    }

    vector<Block> usedBlocks; // �洢�ѷ�����ڴ��
    int start, size;

    while (cin >> start >> size) {
        if (start < 0 || size <= 0 || start + size > 100) {
            cout << -1 << endl; // �Ƿ�ֵ��������ʧ��
            return 0;
        }
        usedBlocks.push_back({ start, size });
    }

    // ����ڴ���ص�
    sort(usedBlocks.begin(), usedBlocks.end(), [](const Block& a, const Block& b) {
        return a.start < b.start;
        });
    for (int i = 1; i < usedBlocks.size(); ++i) {
        if (usedBlocks[i].start < usedBlocks[i - 1].start + usedBlocks[i - 1].size) {
            cout << -1 << endl; // �ڴ���ص�
            return 0;
        }
    }

    const int HEAP_SIZE = 100; // ���ڴ��С
    vector<Block> freeBlocks; // �洢���е��ڴ��
    int currentEnd = 0; // ��ǰ�Ѵ������ڴ�λ��

    // �ҳ����п����ڴ��
    for (const auto& block : usedBlocks) {
        if (block.start > currentEnd) {
            freeBlocks.push_back({ currentEnd, block.start - currentEnd });
        }
        currentEnd = block.start + block.size;
    }
    // ������һ�����ÿ�֮���Ƿ��п����ڴ�
    if (currentEnd < HEAP_SIZE) {
        freeBlocks.push_back({ currentEnd, HEAP_SIZE - currentEnd });
    }

    // ���ÿ�������ڴ�飬�ҵ��㹻�����С��
    int bestFitStart = -1;
    int minSizeDiff = HEAP_SIZE + 1;

    for (const auto& block : freeBlocks) {
        if (block.size >= requestSize && block.size - requestSize < minSizeDiff) {
            bestFitStart = block.start;
            minSizeDiff = block.size - requestSize;
        }
    }

    cout << (bestFitStart != -1 ? bestFitStart : -1) << endl; // ������λ�û�-1
    return 0;
}