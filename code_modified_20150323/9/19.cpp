#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<string> sl;     // string��list
    string word;
    while (cin >> word)   // ��ȡ�ַ�����ֱ�������ļ�������
    {
        sl.push_back(word);
    }

    // ��cbegin()��ȡlist��Ԫ�ص�����������list������Ԫ��
    for (auto si = sl.cbegin(); si != sl.cend(); si++)
    {
        cout << *si << endl;
    }

    return 0;
}
