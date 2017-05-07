#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

template <typename I, typename T>
I find(I b, I e, const T &v)
{
    while (b != e && *b != v)
    {
        b++;
    }
    return b;
}

int main()
{
    vector<int> vi = { 0, 2, 4, 6, 8, 10 };
    list<string> ls = { "Hello", "World", "!" };

    auto iter = find(vi.begin(), vi.end(), 6);
    if (iter == vi.end())
    {
        cout << "can not find 6" << endl;
    }
    else
    {
        cout << "find 6 at position " << iter - vi.begin() << endl;
    }

    auto iter1 = find(ls.begin(), ls.end(), "mom");
    if (iter1 == ls.end())
    {
        cout << "can not find mom" << endl;
    }
    else
    {
        cout << "found mom" << endl;
    }

    return 0;
}

