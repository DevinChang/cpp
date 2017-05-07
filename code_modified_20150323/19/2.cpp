// g++ -std=c++11 StrVec.cpp main.cpp
#include "StrVec.h"
#include <iostream>

using namespace std;

int main()
{
    StrVec sv;
    sv.push_back("hello");
    sv.push_back("world");
    for (auto p = sv.begin(); p != sv.end(); ++p)
    {
        cout << (*p) << endl;
    }
    return 0;
}
