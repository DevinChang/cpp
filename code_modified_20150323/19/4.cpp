#include <iostream>
#include <typeinfo>
using namespace std;

class A
{
public:
    A() {}
    virtual ~A() {}
};

class B : public A
{
public:
    B() {}
    virtual ~B() {}
};

class C : public B
{
public:
    C() {}
    virtual ~C() {}
};

int main()
{
    A *pa = new A;
    try
    {
        C &c = dynamic_cast<C&>(*pa);
    }
    catch (bad_cast &bc)
    {
        cout << "dynamic_cast failed, and the error message is : " << bc.what() << endl;
    }
    return 0;
}
