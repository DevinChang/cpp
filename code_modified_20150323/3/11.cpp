#include <iostream>
#include <string>
using namespace std;

int main()
{
    const string s = "Keep out!";
    for (auto &c : s)
    {
        c='X';  // error: assignment of read-only reference to 'c'.
        //������c�Ĳ���
    }
    return 0;
}
