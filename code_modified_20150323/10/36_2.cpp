#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    list<int> li = { 0, 1, 2, 0, 3, 4, 5, 0, 6};
    // 利用反向迭代器查找最后一个0
    auto last_z = find(li.rbegin(), li.rend(), 0);
    // 将迭代器向链表头方向推进一个位置
    // 转换为普通迭代器时，将回到最后一个0的位置
    last_z++;
    int p = 1;
    // 用base将last_z转换为普通迭代器
    // 从链表头开始遍历，计数最后一个0的编号
    for (auto iter = li.begin(); iter != last_z.base(); iter++, p++)
    {
    }

    if (p >= li.size())   // 未找到0
    {
        cout << "容器中没有0" << endl;
    }
    else
    {
        cout << "最后一个0在第" << p << "个位置" << endl;
    }

    return 0;
}
