#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest)
{
    cout << sizeof...(Args) << " "; // 模板类型参数的数目
    cout << sizeof...(rest) << endl; // 函数参数的数目
}

int main()
{
    int i = 0; double d = 3.14; string s = "how now brown cow";
    foo(i, s, 42, d); 	// 包中有三个参数
    foo(s, 42, "hi"); 	// 包中有两个参数
    foo(d, s); 			// 包中有一个参数
    foo("hi"); 			// 空包

    return 0;
}
