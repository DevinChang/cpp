#include <iostream>
using namespace std;

int main()
{
    const int sz = 10;  //常量sz作为数组的维度
    int a[sz], b[sz];
    //通过for循环为数组元素赋值
    for (int i = 0; i < sz; i++)
    {
        a[i] = i;
    }
    for (int j = 0; j < sz; j++)
    {
        b[j] = a[j];
    }
    //通过范围for循环输出数组的全部元素
    for (auto val : b)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
