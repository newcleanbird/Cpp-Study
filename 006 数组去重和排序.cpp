/*
006 ����ȥ�غ�����
����һ����������飬ɾ�����е��ظ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ����Ұ��ճ��ֵĴ����Ӹߵ��ͽ���������ͬ���ִ������յ�һ�γ���˳������Ⱥ�����

����
һ������

���
ȥ������������


����
1,3,3,3,2,4,4,4,5

���
3,4,1,2,5

˵��:
�����С������100 ����Ԫ��ֵ��С������100��
*/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

// ����һ�������ṹ�壬���ڴ洢Ԫ�ص�ֵ�ͳ��ִ���
struct Element {
    int value;
    int count;
};

// �Զ���ȽϺ�����������ĿҪ���������
bool compare(const Element& a, const Element& b) {
    if (a.count == b.count) {
        return a.value < b.value;
    }
    return a.count > b.count;
}

std::vector<int> removeDuplicatesAndSort(std::vector<int>& nums) {
    std::unordered_map<int, int> countMap; // ���ڼ�¼ÿ��Ԫ�صĳ��ִ���
    for (int num : nums) {
        countMap[num]++;
    }

    std::vector<Element> elements; // ���ڴ洢Ԫ�ؼ�����ִ����Ľṹ������
    for (auto& entry : countMap) {
        elements.push_back({ entry.first, entry.second });
    }

    std::sort(elements.begin(), elements.end(), compare); // ���ճ��ִ�����ֵ��������

    std::vector<int> result; // �洢���ս��������
    for (const Element& element : elements) {
        result.push_back(element.value);
    }

    return result;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> nums;
    size_t startPos = 0;
    size_t commaPos = input.find(',');

    while (commaPos != std::string::npos) {
        std::string numStr = input.substr(startPos, commaPos - startPos);
        int num = std::stoi(numStr);
        nums.push_back(num);
        startPos = commaPos + 1;
        commaPos = input.find(',', startPos);
    }

    // �������һ�����ź������
    std::string numStr = input.substr(startPos);
    int num = std::stoi(numStr);
    nums.push_back(num);

    std::vector<int> result = removeDuplicatesAndSort(nums);

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << ",";
        }
    }

    return 0;
}


