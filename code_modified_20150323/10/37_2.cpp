#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    copy(vi.begin(), vi.end(), out_iter);
    cout << endl;

    list<int> li;
    copy(vi.rbegin() + vi.size() - 7, vi.rbegin() + vi.size() - 3 + 1, back_inserter(li));
    copy(li.begin(), li.end(), out_iter);
    cout << endl;
    return 0;
}

