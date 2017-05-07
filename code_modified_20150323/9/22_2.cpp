#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> iv = {1, 1, 1, 1, 1};  // int的vector
    int some_val = 1;

    vector<int>::iterator iter = iv.begin();
    int org_size = iv.size(), i = 0;  // 原大小

    // 用循环变量控制循环次数
    while (i <= org_size / 2)
    {
        if (*iter == some_val)
        {
            iter = iv.insert(iter, 2 * some_val);  // iter指向新元素
            iter++; iter++;  // 将iter推进到旧元素的下一个位置
        }
        else
        {
            iter++;  // 简单推进iter
        }

        i++;
    }

    // 用begin()获取vector首元素迭代器，遍历vector中所有元素
    for (iter = iv.begin(); iter != iv.end(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}
