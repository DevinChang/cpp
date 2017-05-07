#include <iostream>
//使用using声明使得cin、cout和endl在程序中可见
using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "请输入两个数";
    cout << endl;
    int v1, v2;
    cin >> v1 >> v2;
    if (v1 > v2)	// 由大至小打印
    {
        while (v1 >= v2)
        {
            cout << v1 << " ";
            v1--;
        }
    }
    else				// 由小至大打印
    {
        while (v1 <= v2)
        {
            cout << v1 << " ";
            v1++;
        }
    }
    cout << endl;
    return 0;
}
