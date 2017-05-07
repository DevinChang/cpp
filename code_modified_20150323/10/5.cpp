#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
    char *p[] = { "Hello", "World", "!" };
    char *q[] = { strdup(p[0]), strdup(p[1]), strdup(p[2])};
    char *r[] = { p[0], p[1], p[2] };

    cout << equal(begin(p), end(p), q) << endl;
    cout << equal(begin(p), end(p), r) << endl;
    return 0;
}
