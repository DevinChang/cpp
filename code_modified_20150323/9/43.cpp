#include <iostream>
#include <vector>
#include <string>
using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal)
{
    auto l = oldVal.size();
    if (!l)       // 要查找的字符串为空
    {
        return;
    }

    auto iter = s.begin();
    while (iter <= s.end() - l) // 末尾少于oldVal长度的部分无需检查
    {
        auto iter1 = iter;
        auto iter2 = oldVal.begin();
        // s中iter开始的子串必须每个字符都与oldVal相同
        while (iter2 != oldVal.end() && *iter1 == *iter2)
        {
            iter1++;
            iter2++;
        }

        if (iter2 == oldVal.end())    // oldVal耗尽——字符串相等
        {
            iter = s.erase(iter, iter1);  // 删除s中与oldVal相等部分
            if (newVal.size())          // 替换子串是否为空
            {
                iter2 = newVal.end();       // 由后至前逐个插入newVal中字符
                do
                {
                    iter2--;
                    iter = s.insert(iter, *iter2);
                } while (iter2 > newVal.begin());
            }
            iter += newVal.size();        // 迭代器移动到新插入内容之后
        }
        else
        {
            iter++;
        }
    }
}
int main()
{
  	string s="tho thru tho!";
  	replace_string(s, "thru", "through");
  	cout << s << endl;

  	replace_string(s, "tho", "though");
  	cout << s << endl;

  	replace_string(s, "through", "");
  	cout << s << endl;

    return 0;
}
