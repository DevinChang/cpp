#include <iostream>
#include <string>

using namespace std;

template <typename T, size_t N>
void print(const T (&a)[N])
{
    for (auto iter = begin(a); iter != end(a); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int main()
{
    int a[6] = { 0, 2, 4, 6, 8, 10 };
    string vs[3] = { "Hello", "World", "!" };

    print(a);
    print(vs);

    return 0;
}

