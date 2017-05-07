#include <iostream>
#include <string>
using namespace std;

int main()      //使用cin一次读入一个词，遇空白结束
{
    string word;
    // 循环读取，每次读入一个词，直至文件结束或遇到异常输入
    cout << "请输入您的单词，不可以包含空格：" << endl;
    while (cin >> word)
    {
        cout << word << endl; 	//为了便于观察，输出每个单词后换行
    }

    return 0;
}
