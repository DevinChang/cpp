#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s;
    cout << "������һ���ַ�������ú���ĳЩ�����ţ�" << endl;
    getline(cin, s);
    for (auto c : s)
    {
        if (!ispunct(c))
        {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}
