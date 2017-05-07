#include <iostream>
using namespace std;

int main()
{
    const int sz = 10;  //常量sz作为数组的维度
    int a[sz];
    //通过for循环为数组元素赋值
    for (int i = 0; i < sz; i++)
    {
        a[i] = i;
    }
    //通过范围for循环输出数组的全部元素
    for (auto val : a)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
