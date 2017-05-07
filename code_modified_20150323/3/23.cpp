#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    vector<int> vInt;
    srand((unsigned) time(NULL));    //生成随机数种子
    for (int i = 0; i < 10; i++)     	//循环10次
    {
        //每次循环生成一个1000以内的随机数并添加到vInt中
        vInt.push_back(rand() % 1000);
    }
    cout << "随机生成的10个数字是：" << endl;
    //利用常量迭代器读取原始数据
    for (auto it = vInt.cbegin(); it != vInt.cend(); it++)
    {
        cout << *it << " ";        //输出当前数字
    }
    cout << endl;
    cout << "翻倍后的10个数字是：" << endl;
    //利用非常量迭代器修改vInt内容并输出
    for (auto it = vInt.begin(); it != vInt.end(); it++)
    {
        *it *= 2;
        cout << *it << " ";        //输出当前数字
    }
    cout << endl;

    return 0;
}
