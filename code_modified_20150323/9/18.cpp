#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<string> sd;     // string��deque
    string word;
    while (cin >> word)   // ��ȡ�ַ�����ֱ�������ļ�������
    {
        sd.push_back(word);
    }

    // ��cbegin()��ȡdeque��Ԫ�ص�����������deque������Ԫ��
    for (auto si = sd.cbegin(); si != sd.cend(); si++)
    {
        cout << *si << endl;
    }

    return 0;
}
