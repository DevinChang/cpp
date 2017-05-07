#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::to_string;

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { }  // 拷贝构造函数
    HasPtr& operator=(const HasPtr&);  // 拷贝赋值运算符
    HasPtr& operator=(const string&);  // 赋予新string
    string& operator*();       // 解引用
    bool operator<(const HasPtr&) const; // 比较运算
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
    return *this; 				// 返回此对象的引用
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
    using std::swap;
    cout << "交换 " << *lhs.ps << "和" << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);	// 交换指针，而不是string数据
    swap(lhs.i, rhs.i);    	// 交换int成员
}

bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *ps < *rhs.ps;
}

int main(int argc, char **argv)
{
    vector<HasPtr> vh;
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++)
    {
        vh.push_back(to_string(n-i));
    }

    for (auto p : vh)
    {
        cout << *p << " ";
    }
    cout << endl;

    sort(vh.begin(), vh.end());
    for (auto p : vh)
    {
        cout << *p << " ";
    }
    cout << endl;

  	return 0;
}
