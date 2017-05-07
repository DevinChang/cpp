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
    if (vInt.size() == 0)
    {
        cout << "没有任何元素" << endl;
        return -1;
    }

    cout << "首尾两项的和依次是：" << endl;
    //利用decltype推断i的类型
    for (decltype(vInt.size()) i = 0; i < vInt.size() / 2; i++)
    {
        //求首尾两项的和
        cout << vInt[i] + vInt[vInt.size() - i - 1] << " ";
        //每行输出5个数字
        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }
    //如果元素数是奇数，单独处理最后一个元素
    if (vInt.size() % 2 != 0)
    {
        cout << vInt[vInt.size() / 2];
    }

    return 0;
}
