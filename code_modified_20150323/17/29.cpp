#include <iostream>
#include <random>
using namespace std;

unsigned int rand_int(long seed = -1)
{
    // ����0��9999֮�䣨���������ȷֲ��������
    static uniform_int_distribution<unsigned> u(0,9999);
    static default_random_engine e; // �����޷����������

    if (seed >= 0)
    {
        e.seed(seed);
    }
    return u(e);
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << rand_int() << " ";
    }
    cout << endl;

    cout << rand_int(0) << " ";
    for (int i = 0; i < 9; i++)
    {
        cout << rand_int() << " ";
    }
    cout << endl;

    cout << rand_int(19743) << " ";
    for (int i = 0; i < 9; i++)
    {
        cout << rand_int() << " ";
    }
    cout << endl;

  	return 0;
}
