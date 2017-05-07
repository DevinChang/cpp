#include <iostream>
#include <fstream>
#include <vector>
#include "Sales_data.h"
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }

    vector<Sales_data> sds;
    Sales_data sd;
    while (read(in, sd))
    {
        sds.push_back(sd);
    }

    sort(sds.begin(), sds.end(), compareIsbn);

    for (const auto &s : sds)
    {
        print(cout, s);
        cout << endl;
    }
    return 0;
}
