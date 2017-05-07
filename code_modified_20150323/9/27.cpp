#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> iflst = {1, 2, 3, 4, 5, 6, 7, 8};
    auto prev = iflst.before_begin();     // 前驱元素
    auto curr = iflst.begin();            // 当前元素
    while (curr != iflst.end())
    {
        if (*curr & 1)                      // 奇数
        {
            curr = iflst.erase_after(prev);   // 删除，移动到下一元素
        }
        else
        {
            prev = curr;                // 前驱和当前迭代器都向前推进
            curr++;
        }
    }

    for (curr = iflst.begin(); curr != iflst.end(); curr++)
    {
        cout << *curr << " ";
    }
    cout << endl;

    return 0;
}
