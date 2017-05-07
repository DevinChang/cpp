#include <iostream>
#include <vector>
using namespace std;

//递归函数输出vector<int>的内容
void print(vector<int> vInt, unsigned index)
{
    unsigned sz = vInt.size();
    if (!vInt.empty() && index < sz)
    {
        cout << vInt[index] << endl;
        print(vInt, index + 1);
    }
}

int main()
{
    vector<int> v = {1, 3, 5, 7, 9, 11, 13, 15};
    print(v, 0);
    return 0;
}
