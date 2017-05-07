#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { }  // 拷贝构造函数
    HasPtr& operator=(const HasPtr&);  // 拷贝赋值运算符
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
    auto newps = new string(*rhs.ps); // 拷贝指针指向的对象
    delete ps;					// 销毁原string
    ps = newps;					// 指向新string
    i = rhs.i; 					// 使用内置的int赋值
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

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "交换 " << *lhs.ps << "和" << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);	// 交换指针，而不是string数据
    swap(lhs.i, rhs.i);    	// 交换int成员
}

int main(int argc, char **argv)
{
    HasPtr h("hi mom!");
    HasPtr h2(h);  // 行为类值，h2、h3和h指向不同string
    HasPtr h3 = h;
    h2 = "hi dad!";
    h3 = "hi son!";
    swap(h2, h3);
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    return 0;
}
