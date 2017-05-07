#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    list<int> li = { 0, 1, 2, 0, 3, 4, 5, 0, 6 };
    // 用普通迭代器查找第一个0的位置
    auto prev = find(li.begin(), li.end(), 0);
    if (prev == li.end())   // 未找到
    {
        cout << "容器中没有0" << endl;
    }
    else
    {
        auto curr = prev;
        // 继续寻找后续0，直到到达尾后位置
        while (curr != li.end())
        {
            // 记住上一个0的位置
            prev = curr;
            curr++;
            // 寻找下一个0
            curr = find(curr, li.end(), 0);
        }
        // 从链表头开始计数prev的位置编号
        int p = 1;
        for (auto iter = li.begin(); iter != prev; iter++, p++)
        {
        }

        cout << "最后一个0在第" << p << "个位置" << endl;
    }

    return 0;
}
