#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vInt;
    int iVal;
    cout << "请输入一组数字：" << endl;
    while (cin >> iVal)
    {
        vInt.push_back(iVal);
    }
    if (vInt.cbegin() == vInt.cend())
    {
        cout << "没有任何元素" << endl;
        return -1;
    }

    cout << "首尾两项的和依次是：" << endl;
    auto beg = vInt.begin();
    auto end = vInt.end();
    //利用auto推断it的类型
    for (auto it = beg; it != beg + (end - beg) / 2; it++)
    {
        //求首尾两项的和
        cout << (*it + *(beg + (end - it) - 1)) << " ";
        //每行输出5个数字
        if ((it - beg + 1) % 5 == 0)
        {
            cout << endl;
        }
    }
    //如果元素数是奇数，单独处理最后一个元素
    if (vInt.size() % 2 != 0)
    {
        cout << *(beg + (end - beg) / 2);
    }

    return 0;
}
