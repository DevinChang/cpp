#include <iostream>
#include "Chapter6.h"
using namespace std;

int main()
{
    int num;
    cout << "请输入一个整数：";
    cin >> num;
    cout << num << "的阶乘是：" << fact(num) << endl;
    return 0;
}

