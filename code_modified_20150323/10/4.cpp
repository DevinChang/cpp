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

    vector<double> vd;
    double val;
    while (in >> val)
    {
        vd.push_back(val);
    }

    cout << "�����и�����֮��Ϊ" << accumulate(vd.begin(), vd.end(), 0) << endl;
    return 0;
}
