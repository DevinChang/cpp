#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "�������ļ�ʧ�ܣ�" << endl;
        exit(1);
    }

    // ���������������ļ������ַ���
    istream_iterator<string> in_iter(in);
    // β�������
    istream_iterator<string> eof;
    vector<string> words;
    while (in_iter != eof)
    {
        words.push_back(*in_iter++);  // ����vector������������
    }

    for (auto word : words)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
