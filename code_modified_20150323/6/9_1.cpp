#include "Chapter6.h"
using namespace std;

int fact(int val)
{
    if(val < 0)
        return -1;
    int ret = 1;
    //�䨮1��?3?��?val
    for(int i = 1; i != val + 1; ++i)
        ret *= i;
    return ret;
}
