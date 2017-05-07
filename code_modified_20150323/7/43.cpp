#include <iostream>
#include <string>
using namespace std;

//该类型没有显式定义默认构造函数，编译器也不会为它合成一个
class NoDefault
{
public:
    NoDefault(int i)
    {
        val = i;
    }
    int val;
};

class C
{
public:
    NoDefault nd;
    //必须显式调用Nodefault的带参构造函数初始化nd
    C(int i = 0) : nd(i) { }
};

int main()
{
    C c;    //使用了类型C的默认构造函数
    cout << c.nd.val << endl;
    return 0;
}
