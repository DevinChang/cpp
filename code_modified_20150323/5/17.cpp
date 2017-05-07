#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    vector<int> v3 = {3, 5, 8};
    vector<int> v4 = {3, 5, 0, 9, 2, 7};

    auto it1 = v1.cbegin(); //定义v1的迭代器
    auto it2 = v2.cbegin(); //定义v2的迭代器
    auto it3 = v3.cbegin(); //定义v3的迭代器
    auto it4 = v4.cbegin(); //定义v4的迭代器
    //设定循环条件：v1和v2都尚未检查完
    while (it1 != v1.cend() && it2 != v2.cend())
    {
        //如果当前位置的两个元素不相等，则肯定没有前缀关系，退出循环
        if (*it1 != *it2)
        {
            cout << "v1和v2之间不存在前缀关系" << endl;
            break;
        }
        ++it1;  //迭代器移动到下一个元素
        ++it2;  //迭代器移动到下一个元素
    }
    if (it1 == v1.cend())    //如果v1较短
    {
        cout << "v1是v2的前缀" << endl;
    }
    if (it2 == v2.cend())    //如果v2较短
    {
        cout << "v2是v1的前缀" << endl;
    }
    return 0;
}
