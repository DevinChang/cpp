#include <iostream>
#include <string>
using namespace std;

// 用来终止递归并打印最后一个元素的函数
// 此函数必须在可变参数版本的print定义之前声明
template<typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t << endl; // 包中最后一个元素之后不打印分隔符
}

// 包中除了最后一个元素之外的其他元素都会调用这个版本的print
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)//扩展Args
{
    os << t << ", ";            // 打印第一个实参
    return print(os, rest...);  // 扩展rest，递归打印其他参数
}

int main()
{
    int i = 0;
    string s = "Hello";

    print(cout, i);
    print(cout, i, s);
    print(cout, i, s, 42.1, 'A', "End");
	return 0;
}

