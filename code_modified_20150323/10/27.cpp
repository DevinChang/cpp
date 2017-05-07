#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vi = { 1, 2, 2, 3, 4, 5, 5, 6};
    list<int> li;

    unique_copy(vi.begin(), vi.end(), back_inserter(li));

    for (auto v : li)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
