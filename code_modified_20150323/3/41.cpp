#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    const int sz = 10;  //常量sz作为数组的维度
    int a[sz];
    srand((unsigned) time(NULL)); //生成随机数种子
    cout << "数组的内容是：" << endl;
    //利用范围for循环遍历数组的每个元素
    for (auto &val : a)
    {
        val = rand() % 100;   //生成一个100以内的随机数
        cout << val << " ";
    }
    cout << endl;

    //利用begin和end初始化vector对象
    vector<int> vInt(begin(a), end(a));
    cout << "vector的内容是：" << endl;
    //利用范围for循环遍历vector的每个元素
    for (auto val : vInt)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
