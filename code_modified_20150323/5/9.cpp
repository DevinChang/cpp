#include <iostream>
using namespace std;

int main()
{
    unsigned int vowelCnt = 0;
    char ch;
    cout << "������һ���ı���" << endl;
    while (cin >> ch)
    {
        if (ch == 'a')
        {
            ++vowelCnt;
        }
        if (ch == 'e')
        {
            ++vowelCnt;
        }
        if (ch == 'i')
        {
            ++vowelCnt;
        }
        if (ch == 'o')
        {
            ++vowelCnt;
        }
        if (ch == 'u')
        {
            ++vowelCnt;
        }
    }
    cout << "��������ı��й��� " << vowelCnt << "��Ԫ����ĸ" << endl;
    return 0;
}
