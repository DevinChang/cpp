#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "�������ļ�ʧ�ܣ�" << endl;
        exit(1);
    }

    vector<int> vi;
    int val;
    while (in >> val)
    {
        vi.push_back(val);
    }
    cout << "����������֮��Ϊ" << accumulate(vi.begin(), vi.end(), 0) << endl;
    return 0;
}
