#include <iostream>
using namespace std;

int main()
{
    const int sz = 10;  //常量sz作为数组的维度
    int a[sz], i = 0;
    //通过for循环为数组元素赋值
    for (i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    cout << "初始状态下数组的内容是：" << endl;
    for (auto val : a)
    {
        cout << val << " ";
    }
    cout << endl;

    int *p = begin(a);  //令p指向数组首元素
    while (p != end(a))
    {
        *p = 0;         //修改p所指元素的值
        p++;            //p向后移动一位
    }
    cout << "修改后的数组内容是：" << endl;
    //通过范围for循环输出数组的全部元素
    for (auto val : a)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

