#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream in("data");          // ���ļ�
    if (!in)
    {
        cerr << "�޷��������ļ�" << endl;
        return -1;
    }

    string line;
    vector<string> words;
    while (getline(in, line))   // ���ļ��ж�ȡһ��
    {
        words.push_back(line);      // ��ӵ�vector��
    }

    in.close();                   // ������ϣ��ر��ļ�

    vector<string>::const_iterator it = words.begin();  // ������
    while (it != words.end())  // ����vector
    {
        cout << *it << endl;        // ���vector��Ԫ��
        ++it;
    }

    return 0;
}
