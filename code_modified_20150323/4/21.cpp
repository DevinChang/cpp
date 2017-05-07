#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    vector<int> vInt;
    const int sz = 10;  //使用sz作为数组的维度
    srand((unsigned) time(NULL)); //生成随机数种子
    //使用普通for循环为数组赋初值
    cout << "数组的初始值是：" << endl;
    for (int i = 0; i != sz; ++i)
    {
        vInt.push_back(rand() % 100);   //生成100以内的随机数
        cout << vInt[i] << " "; //使用下标运算符输出数组内容
    }
    cout << endl;
    
    //使用范围for循环把数组中的奇数翻倍
    for (auto &val : vInt)
    {
        val = (val % 2 != 0) ? val * 2 : val;   //条件表达式
    }
    //使用范围for循环和迭代器输出数组的当前值
    cout << "调整后的数组值是：" << endl;
    for (auto it = vInt.cbegin(); it != vInt.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
