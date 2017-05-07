#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> iv;
    list<int> il;

    iv.assign(ia, ia + 11);   // 将数据拷贝到vector
    il.assign(ia, ia + 11);   // 将数据拷贝到list

    vector<int>::iterator iiv = iv.begin();
    while (iiv != iv.end())
    {
        if (!(*iiv & 1))        // 偶数
        {
            iiv = iv.erase(iiv);  // 删除偶数，返回下一位置迭代器
        }
        else
        {
            iiv++;             // 推进到下一位置
        }
    }

    list<int>::iterator iil = il.begin();
    while (iil != il.end())
    {
        if (*iil & 1)           // 奇数
        {
            iil = il.erase(iil);  // 删除奇数，返回下一位置迭代器
        }
        else
        {
            iil++;             // 推进到下一位置
        }
    }

    for (iiv = iv.begin(); iiv != iv.end(); iiv++)
    {
        cout << *iiv << " ";
    }
    cout << endl;
  
    for (iil = il.begin(); iil != il.end(); iil++)
    {
        cout << *iil << " ";
    }
    cout << endl;

    return 0;
}
