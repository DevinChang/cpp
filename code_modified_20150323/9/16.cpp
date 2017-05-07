#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool l_v_equal(vector<int> &ivec, list<int> &ilist)
{
    // 比较list和vector元素个数
    if (ilist.size() != ivec.size())
    {
        return false;
    }

    auto lb = ilist.cbegin();   // list首元素
    auto le = ilist.cend();     // list尾后位置
    auto vb = ivec.cbegin();    // vector首元素
    for (; lb != le; lb++, vb++)
    {
        if (*lb != *vb)         // 元素不等，容器不等
        {
            return false;
        }
    }
    return true;                // 容器相等
}

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7};
    list<int> ilist = {1, 2, 3, 4, 5, 6, 7};
    list<int> ilist1 = {1, 2, 3, 4, 5};
    list<int> ilist2 = {1, 2, 3, 4, 5, 6, 8};
    list<int> ilist3 = {1, 2, 3, 4, 5, 7, 6};

    cout << l_v_equal(ivec, ilist) << endl;
    cout << l_v_equal(ivec, ilist1) << endl;
    cout << l_v_equal(ivec, ilist2) << endl;
    cout << l_v_equal(ivec, ilist3) << endl;

    return 0;
}
