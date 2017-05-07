#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i)   // 拷贝构造函数
    {
        cout << "Copy Constructor" << endl;
    }
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) // 移动构造函数
    {
        p.ps = 0; cout << "Move Constructor" << endl;
    }
    HasPtr& operator=(const HasPtr&);  // 拷贝赋值运算符
    HasPtr& operator=(HasPtr&&) noexcept;  // 移动赋值运算符
    HasPtr& operator=(const string&);  // 赋予新string
    string& operator*();       // 解引用
    ~HasPtr();
private:
    string *ps;
    int i;
};

HasPtr::~HasPtr()
{
    delete ps; 		// 释放string内存
}

inline HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    cout << "Copy Assignment" << endl;
    auto newps = new string(*rhs.ps); // 拷贝指针指向的对象
    delete ps;					// 销毁原string
    ps = newps;					// 指向新string
    i = rhs.i; 					// 使用内置的int赋值
    return *this; 				// 返回一个此对象的引用
}

inline HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept
{
    cout << "Move Assignment" << endl;
    if (this != &rhs)
    {
        delete ps;      // 释放旧string
        ps = rhs.ps;		// 从rhs接管string
        rhs.ps = nullptr;		// 将rhs置于析构安全状态
        rhs.i = 0;
    }
    return *this; 				// 返回一个此对象的引用
}

HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*()
{
    return *ps;
}

int main(int argc, char **argv)
{
    HasPtr h("hi mom!");
    {
        HasPtr h2(h);  // 拷贝构造函数
        HasPtr h3(std::move(h2));  // 移动构造函数
    }

    {
        HasPtr h2, h3;
        h2 = h;  // 拷贝赋值运算符
        h3 = std::move(h2);  // 移动赋值运算符
    }

    return 0;
}
