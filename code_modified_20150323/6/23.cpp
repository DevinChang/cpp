#include <iostream>
using namespace std;

//参数是常量整型指针
void print1(const int *p)
{
    cout << *p << endl;
}

//参数有两个，分别是常量整型指针和数组的容量
void print2(const int *p, const int sz)
{
    int i = 0;
    while (i != sz)
    {
        cout << *p++ << endl;
        ++i;
    }
}

//参数有两个，分别是数组的首尾边界
void print3(const int *b, const int *e)
{
    for (auto q = b; q != e; ++q)
    {
        cout << *q << endl;
    }
}

int main()
{
    int i = 0, j[2] = {0, 1};
    print1(&i);
    print1(j);
    print2(&i, 1);
    
    //计算得到数组j的容量
    print2(j, sizeof(j) / sizeof(*j));
    auto b = begin(j);
    auto e = end(j);
    print3(b, e);
    return 0;
}
