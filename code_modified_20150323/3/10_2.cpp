#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s, result;
    cout << "������һ���ַ�������ú���ĳЩ�����ţ�" << endl;
    getline(cin, s);
    for (decltype(s.size()) i = 0; i < s.size(); i++)
    {
        if (!ispunct(s[i]))
        {
            result += s[i];
        }
    }
    cout << result << endl;
    return 0;
}
