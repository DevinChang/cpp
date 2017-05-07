#include <iostream>
#include <fstream>
#include <string>
#include <list>
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

    list<string> ls;
    string word;
    while (in >> word)
    {
        ls.push_back(word);
    }

    cout << "������Ҫ�������ַ�����";
    cin >> word;
    cout << "�����а���" << count(ls.begin(), ls.end(), word) << "��" << word;
    return 0;
}
