#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s;
    cout << "请输入一个字符串，最好含有某些标点符号：" << endl;
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
