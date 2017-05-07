#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> svec;     // string的vector
    string word;
    auto iter = svec.begin(); // 获取vector首位置迭代器
    while (cin >> word)   // 读取字符串，直至遇到文件结束符
    {
        iter = svec.insert(iter, word);
    }

    // 用cbegin()获取vector首元素迭代器，遍历vector中所有元素
    for (auto iter = svec.cbegin(); iter != svec.cend(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}
