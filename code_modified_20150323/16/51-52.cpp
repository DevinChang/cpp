#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest)
{
    cout << sizeof...(Args) << " "; // ģ�����Ͳ�������Ŀ
    cout << sizeof...(rest) << endl; // ������������Ŀ
}

int main()
{
    int i = 0; double d = 3.14; string s = "how now brown cow";
    foo(i, s, 42, d); 	// ��������������
    foo(s, 42, "hi"); 	// ��������������
    foo(d, s); 			// ������һ������
    foo("hi"); 			// �հ�

    return 0;
}
