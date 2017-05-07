#include <iostream>
//使用using声明使得cout和endl在程序中可见
using std::cout;
using std::endl;

int main()
{
    int i = 10;
    while (i >= 0)
    {
        cout << i << " ";
        i--;
    }
    cout << endl;
    return 0;
}
