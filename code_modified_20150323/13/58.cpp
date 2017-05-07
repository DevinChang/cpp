#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo
{
public:
    Foo sorted() &&; 		// 可用于可改变的右值
    Foo sorted() const &; 	// 可用于任何类型的Foo
    // Foo的其他成员的定义
private:
    vector<int> data;
};

// 本对象为右值，因此可以原址排序
Foo Foo::sorted() &&
{
    cout << "右值引用版本" << endl;
    sort(data.begin(), data.end());
    return *this;
}

// 本对象是const或是一个左值，哪种情况我们都不能对其进行原址排序
Foo Foo::sorted() const &
{
    cout << "左值引用版本" << endl;
    Foo ret(*this); 							// 拷贝一个副本
    return ret.sorted();
    // return Foo(*this).sorted();
}

int main(int argc, char **argv)
{
    Foo f;
    f.sorted();
    return 0;
}
