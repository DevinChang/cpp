#include <iostream>
#include <string>
using namespace std;

bool HasUpper(const string& str)	//判断字符串是否含有大写字母
{
    for (auto c : str)
    {
        if (isupper(c))
        {
            return true;
        }
    }
    return false;
}

void ChangeToLower(string& str)	//把字符串中的所有大写字母转成小写
{
    for (auto &c : str)
    {
        c = tolower(c);
    }
}

int main()
{
    cout << "请输入一个字符串：" << endl;
    string str;
    cin >> str;
    if (HasUpper(str))
    {
        ChangeToLower(str);
        cout << "转换后的字符串是：" << str << endl;
    }
    else
    {
        cout << "该字符串不含大写字母，无需转换。" << endl;
    }
    return 0;
}
