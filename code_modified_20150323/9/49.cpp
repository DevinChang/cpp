#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void find_longest_word(ifstream &in)
{
    string s, longest_word;
    int max_length = 0;

    while (in >> s)
    {
        if (s.find_first_of("bdfghjklpqty") != string::npos)
        {
            continue;     // �����ϳ�ͷ���³�ͷ��ĸ
        }

        cout << s << " ";
        if (max_length < s.size())  // �µ��ʸ���
        {
            max_length = s.size();  // ��¼���Ⱥ͵���
            longest_word = s;
        }
    }
    cout << endl << "��ַ�����" << longest_word << endl;
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);          // ���ļ�
    if (!in)
    {
        cerr << "�޷��������ļ�" << endl;
        return -1;
    }

    find_longest_word(in);
    return 0;
}
