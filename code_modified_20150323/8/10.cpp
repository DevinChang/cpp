#include <iostream>
#include <fstream>
#include <sstream>
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
        istringstream line_str(*it);
        string word;
        while (line_str >> word)    // ͨ��istringstream��vector�ж�ȡ����
        {
            cout << word << " ";
        }
        cout << endl;
        ++it;
    }

    return 0;
}
