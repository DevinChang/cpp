#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<string> sl;     // string的list
    string word;
    while (cin >> word)   // 读取字符串，直至遇到文件结束符
    {
        sl.push_back(word);
    }

    // 用cbegin()获取list首元素迭代器，遍历list中所有元素
    for (auto si = sl.cbegin(); si != sl.cend(); si++)
    {
        cout << *si << endl;
    }

    return 0;
}
