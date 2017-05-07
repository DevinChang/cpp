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
    if(vInt.cbegin() == vInt.cend())
    {
        cout << "没有任何元素" << endl;
        return -1;
    }

    cout << "相邻两项的和依次是：" << endl;
    //利用auto推断it的类型
    for (auto it = vInt.cbegin(); it != vInt.cend() - 1; it++)
    {
        //求相邻两项的和
        cout << (*it + *(++it)) << " ";
        //每行输出5个数字
        if ((it - vInt.cbegin() + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    //如果元素数是奇数，单独处理最后一个元素
    if (vInt.size() % 2 != 0)
    {
        cout << *(vInt.cend() - 1);
    }

    return 0;
}
