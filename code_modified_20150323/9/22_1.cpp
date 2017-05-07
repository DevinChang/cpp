#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> iv = {1, 1, 2, 1};  // int的vector
    int some_val = 1;

    vector<int>::iterator iter = iv.begin();
    int org_size = iv.size(), new_ele = 0;  // 原大小和新元素个数

    // 每个循环步都重新计算“mid”，保证正确指向iv原中央元素
    while (iter != (iv.begin() + org_size / 2 + new_ele))
    {
        if (*iter == some_val)
        {
            iter = iv.insert(iter, 2 * some_val); // iter指向新元素
            new_ele++;
            iter++; iter++;  // 将iter推进到旧元素的下一个位置
        }
        else
        { 
            iter++;          // 简单推进iter
        }
    }

  // 用begin()获取vector首元素迭代器，遍历vector中所有元素
  for (iter = iv.begin(); iter != iv.end(); iter++)
  {
      cout << *iter << endl;
  }

  return 0;
}
