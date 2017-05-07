#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //该vector对象记录各分数段的人数，初始值均为0
    vector<unsigned> vUS(11);
    auto it = vUS.begin();
    int iVal, iCount = 0;
    cout << "请输入一组成绩（0~100）：" << endl;
    while (cin >> iVal)
    {
        if (iVal < 101)  //成绩应在合理范围之内
        {
            ++*(it + iVal / 10);    //利用迭代器定位到对应的元素，加1
            ++iCount;
        }
    }
    cout << "您总计输入了 " << iCount << " 个成绩" << endl;
    cout << "各分数段的人数分布是（成绩从低到高）：" << endl;
    //利用迭代器遍历vUS的元素并逐个输出
    for (it = vUS.begin(); it != vUS.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
