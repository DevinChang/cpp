#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> iv;     // intµÄvector

    cout << iv.at(0) << endl;
    cout << iv[0] << endl;
    cout << iv.front() << endl;
    cout << *(iv.begin()) << endl;

    return 0;
}
