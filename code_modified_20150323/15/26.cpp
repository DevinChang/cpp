#include <iostream>
#include <string>
#include "Bulk_quote.h"
using namespace std;

int main(int argc, const char *argv[])
{
    Quote base("C++ Primer", 128.0);
    Bulk_quote bulk("Core Python Programming", 89, 5, 0.19);
    cout << base << endl;
    cout << bulk << endl;
    return 0;
}
