#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<string> sd;     // string的deque
    string word;
    while (cin >> word)   // 读取字符串，直至遇到文件结束符
    {
        sd.push_back(word);
    }

    // 用cbegin()获取deque首元素迭代器，遍历deque中所有元素
    for (auto si = sd.cbegin(); si != sd.cend(); si++)
    {
        cout << *si << endl;
    }

    return 0;
}
