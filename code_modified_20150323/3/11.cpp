#include <iostream>
#include <string>
using namespace std;

int main()
{
    const string s = "Keep out!";
    for (auto &c : s)
    {
        c='X';  // error: assignment of read-only reference to 'c'.
        //其它对c的操作
    }
    return 0;
}
