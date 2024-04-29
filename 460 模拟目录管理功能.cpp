/*
460��ģ��Ŀ¼������
��Ŀ������
ʵ��һ��ģ��Ŀ¼�����ܵ����������һ���������У�������һ���������н����
֧�����
1������Ŀ¼���mkdir Ŀ¼���ƣ���mkdir abcΪ�ڵ�ǰĿ¼����abcĿ¼������Ѵ���ͬ��Ŀ¼��ִ���κβ������������������
2������Ŀ¼���cd Ŀ¼����, ��cd abcΪ����abcĿ¼���ر�أ�cd ..Ϊ�����ϼ�Ŀ¼�����Ŀ¼��������ִ���κβ������������������
3���鿴��ǰ����·�����pwd�������ǰ·���ַ�����

Լ����
 1��Ŀ¼���ƽ�֧��Сд��ĸ��mkdir��cd����Ĳ�����֧�ֵ���Ŀ¼���磺mkdir abc��cd abc����֧��Ƕ��·���;���·������mkdir abc/efg, cd abc/efg, mkdir /abc/efg, cd /abc/efg�ǲ�֧�ֵġ�
 2��Ŀ¼����Ϊ/����Ŀ¼/��Ϊ��ʼĿ¼��
 3���κβ����������������Ч������κδ������������

����������

����N���ַ�����ÿһ���ַ�����һ�����

���������

������һ���������н���ַ�����

����˵����

������������100�����ڣ�Ŀ¼��������10���ַ����ڡ�

ʾ��1
���룺
mkdir abc
cd abc
pwd
�����
abc/
˵����
�ڸ�Ŀ¼����һ��abc��Ŀ¼������abcĿ¼�в鿴��ǰĿ¼·���������ǰ·��/abc/��

ʾ��2
����
mkdir a
mkdir b
cd b
mkdir b1
mkdir b2
pwd  
cd ..
cd a
mkdir a1
cd a1
pwd

����˼·��
1. ���Ŀ¼�ṹ
������Ҫ���һ�����ڴ洢Ŀ¼�ṹ������ģ�͡�����������ʹ��һ����״�ṹ������ÿ���ڵ����һ��Ŀ¼���ڵ�����ж���ӽڵ㣬�������µ���Ŀ¼��ÿ���ڵ㻹Ӧ�洢һЩ������Ϣ����Ŀ¼����
- �ڵ����ԣ�Ŀ¼����ָ���ӽڵ�����ã��б���ϣ����

2. ��ʼ����Ŀ¼
- ��ʼ��һ�����ڵ���ΪĿ¼������㡣����ڵ�����ļ�ϵͳ�ĸ�Ŀ¼�����Ϊ /��

3. ��������
- ��Ҫһ��ѭ�����߼�����ȡ�������û����������롣������Է�Ϊ�������ͣ�mkdir��cd��pwd��
- ����ÿ���������ͣ������������Ĳ���������еĻ�����

4. ʵ�� mkdir ����
- ���ҵ�ǰĿ¼��ȷ����ǰ����Ŀ¼��
- ���Ŀ¼�Ƿ���ڣ��ڵ�ǰĿ¼����Ŀ¼�б��в����Ƿ��Ѵ��ڸ�Ŀ¼��
- ����Ŀ¼����������ڣ����ڵ�ǰĿ¼�´���һ���µ���Ŀ¼�ڵ㡣

5. ʵ�� cd ����
- ����Ŀ¼����������� ..������Ҫ�ƶ�����Ŀ¼�������ܳ�����Ŀ¼��
- ����Ŀ¼������Ǿ����Ŀ¼��������Ŀ¼�Ƿ�����ڵ�ǰĿ¼����Ŀ¼�С�������ڣ����µ�ǰĿ¼Ϊ����Ŀ¼��

6. ʵ�� pwd ����
- �����ǰ·�����Ӹ�Ŀ¼��ʼ����������ǰĿ¼��·��������ͨ���ӵ�ǰ�ڵ����ϱ��������ڵ�������������·���ַ�����
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class FileSystem {
private:
    struct Directory {
        unordered_map<string, Directory*> children;  // �洢Ŀ¼����Ŀ¼
    };

    Directory* root;   // ��Ŀ¼ָ��
    Directory* current;  // ��ǰĿ¼ָ��
    string currentPath;  // ��ǰĿ¼��·���ַ���

public:
    FileSystem() {
        root = new Directory();
        current = root;
        currentPath = "/";  // ��ʼ��ʱ��Ϊ��Ŀ¼
    }

    // ����Ŀ¼�ĺ���
    void mkdir(const string& name) {
        // ��鵱ǰĿ¼���Ƿ����ͬ��Ŀ¼
        if (current->children.find(name) == current->children.end()) {
            current->children[name] = new Directory();  // �������򴴽���Ŀ¼
        }
    }

    // �ı䵱ǰĿ¼�ĺ���
    void cd(const string& path) {
        if (path == "..") {
            // ����Ƿ�����һ��Ŀ¼
            if (current != root) { // ȷ�����Ǹ�Ŀ¼
                size_t pos = currentPath.rfind('/', currentPath.length() - 2);
                currentPath = currentPath.substr(0, pos + 1);
                // �Ӹ�Ŀ¼���±�������һ��Ŀ¼
                current = root; // ����Ϊ��Ŀ¼
                vector<string> dirs = split(currentPath, '/');
                for (const string& dir : dirs) {
                    if (!dir.empty() && current->children.find(dir) != current->children.end()) {
                        current = current->children[dir];
                    }
                }
            }
        }
        else {
            // ����ǽ���һ����Ŀ¼
            if (current->children.find(path) != current->children.end()) {
                current = current->children[path];
                currentPath += path + "/";
            }
        }
    }

    // ��ȡ��ǰĿ¼·���ĺ���
    string pwd() {
        return currentPath;
    }

private:
    // �������������ڷָ��ַ���
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

int main() {
    FileSystem fs;
    string line;
    string lastOutput = "";  // ���ڴ洢���һ�ε�pwd���

    while (getline(cin, line)) {
        lastOutput = "";
        if (line.substr(0, 5) == "mkdir") {
            string dirName = line.substr(6);
            fs.mkdir(dirName);  // ִ��mkdir����
        }
        else if (line.substr(0, 2) == "cd") {
            string dirName = line.substr(3);
            fs.cd(dirName);  // ִ��cd����
        }
        else if (line == "pwd") {
            lastOutput = fs.pwd();      // ִ��pwd������������
            cout << lastOutput << endl; // ��ӡ����pwd������
        }
    }

    //cout << lastOutput << endl;  // ��ӡ����pwd������

    return 0;
}
