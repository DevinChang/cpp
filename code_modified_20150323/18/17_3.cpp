namespace Exercise
{
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}

int ivar = 0;
// 位置1：插入using指示
using namespace Exercise;

int main()
{
    // 位置2

    double dvar = 3.1416;  // Exercise::dvar
    int iobj = limit + 1;  // Exercise::limit
    ++ivar;  // ambiguous
    ++::ivar;  // ambiguous
    return 0;
}
