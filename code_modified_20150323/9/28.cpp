#include <iostream>
#include <forward_list>
using namespace std;

void test_and_insert(forward_list<string> &sflst, const string &s1, const string &s2)
{
    auto prev = sflst.before_begin();     // 前驱元素
    auto curr = sflst.begin();            // 当前元素
    bool inserted = false;

    while (curr != sflst.end())
    {
        if (*curr == s1)  // 找到给定字符串
        {
            curr = sflst.insert_after(curr, s2);  // 插入新字符串，curr指向它
            inserted = true;
        }
        prev = curr;                        // 前驱迭代器向前推进
        curr++;                             // 当前迭代器向前推进
    }

    if (!inserted)
    {
        sflst.insert_after(prev, s2);        // 未找到给定字符串，插入尾后
    }
}

int main()
{
    forward_list<string> sflst = {"Hello", "!", "world", "!"};

    test_and_insert(sflst, "Hello", "你好");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
    {
      cout << *curr << " ";
    }
    cout << endl;

    test_and_insert(sflst, "!", "?");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
    {
      cout << *curr << " ";
    }
    cout << endl;

    test_and_insert(sflst, "Bye", "再见");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
    {
      cout << *curr << " ";
    }
    cout << endl;

    return 0;
}
