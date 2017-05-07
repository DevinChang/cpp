namespace Exercise
{
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}

int ivar = 0;
// 位置1：插入using声明
using Exercise::ivar;  // compile error: ivar is redefined.
using Exercise::dvar;
using Exercise::limit;

int main()
{
    // 位置2

    double dvar = 3.1416;  // local dvar.
    int iobj = limit + 1;  // Exercise::limit;
    ++ivar;  // ambiguous.
    ++::ivar;  // ambiguous.
    return 0;
}
