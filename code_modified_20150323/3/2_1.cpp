#include <iostream>
#include <string>
using namespace std;

int main()  //使用getline一次读入一整行，遇回车结束
{
    string line;
    // 循环读取，每次读入一整行，直至文件结束或遇到异常输入
    cout << "请输入您的字符串，可以包含空格：" << endl;
    while (getline(cin, line))
    {
        cout << line << endl;
    }

    return 0;
}
