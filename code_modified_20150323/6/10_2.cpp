#include <iostream>
using namespace std;

//在函数体内部交换了两个形参指针本身的值，未能影响实参
void mySWAP(int *p, int *q)
{
    int *tmp = p;	//tmp是个指针
    p = q;
    q = tmp;
}

int main()
{
    int a = 5, b = 10;
    int *r = &a, *s = &b;
    cout << "交换前：a = " << a << "，b = " << b << endl;
    mySWAP(r, s);
    cout << "交换后：a = " << a << "，b = " << b << endl;
    return 0;
}
