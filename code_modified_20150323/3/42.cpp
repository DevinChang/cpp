#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    const int sz = 10;  //常量sz作为vector对象的容量
    vector<int> vInt;
    srand((unsigned) time(NULL)); //生成随机数种子
    cout << "vector对象的内容是：" << endl;
    //利用for循环遍历vector对象的每个元素
    for (int i = 0; i != sz; i++)
    {
        vInt.push_back(rand() % 100);   //生成一个100以内的随机数
        cout << vInt[i] << " ";
    }
    cout << endl;

    auto it = vInt.cbegin();
    int a[vInt.size()];
    cout << "数组的内容是：" << endl;
    //利用范围for循环遍历数组的每个元素
    for (auto &val : a)
    {
        val = *it;
        cout << val << " ";
        it++;
    }
    cout << endl;
    return 0;
}
