#include <iostream>
using namespace std;

class Base
{
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base
{
    int f() { return prot_mem; }
    void memfcn(Base &b)
    {
        b=*this;
        cout<<"Pub_Derv"<<endl;
    }
};

struct Priv_Derv : private Base
{
    int f1() const { return prot_mem; }
    void memfcn(Base &b)
    {
        b=*this;
        cout<<"Priv_Derv"<<endl;
    }
};

struct Prot_Derv : protected Base
{
    int f2() { return prot_mem; }
    void memfcn(Base &b)
    {
        b=*this;
        cout<<"Prot_Derv"<<endl;
    }
};

struct Derived_from_Public : public Pub_Derv
{
    int use_base() { return prot_mem; }
    void memfcn(Base &b)
    {
        b=*this;
        cout<<"Derived_from_Public"<<endl;
    }
};

struct Derived_from_Protected : protected Prot_Derv
{
    int use_base() { return prot_mem; }
    void memfcn(Base &b)
    {
        b=*this;
        cout<<"Derived_from_Protected"<<endl;
    }
};

int main(int argc, const char *argv[])
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
   // Derived_from_Private dd2;
    Derived_from_Protected dd3;
    Base base;
    Base *p=new Base;
    p=&d1;              //d1的类型是Pub_Derv
    //p=&d2;              //d2的类型是Priv_Derv
    //p=&d3;              //d3的类型是Prot_Derv
    p=&dd1;             //dd1的类型是Derived_from_Public
    //p=&dd2;             //dd2的类型是Derived_from_Private
    //p=&dd3;             //dd3的类型是Derived_from_Protected
    
    d1.memfcn(base);
    d2.memfcn(base);
    d3.memfcn(base);
    dd1.memfcn(base);
    //dd2.memfcn(base);
    dd3.memfcn(base);
    return 0;
}
