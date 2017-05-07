#include <iostream>
using namespace std;
//定义在全局作用域中的数组
string sa[10];
int ia[10];

int main()
{
    //定义在局部作用域中的数组
    string sa2[10];
    int ia2[10];
    for (auto c : sa)
    {
        cout << c << " ";
    }
    cout << endl;

    for (auto c : ia)
    {
        cout << c << " ";
    }
    cout << endl;

    for (auto c : sa2)
    {
        cout << c << " ";
    }
    cout << endl;
    
    for (auto c : ia2)
    {
        cout << c << " ";
    }
    return 0;
}
