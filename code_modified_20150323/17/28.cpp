#include <iostream>
#include <random>
using namespace std;

unsigned int rand_int()
{
    // ����0��9999֮�䣨���������ȷֲ��������
    static uniform_int_distribution<unsigned> u(0,9999);
    static default_random_engine e; // �����޷����������

    return u(e);
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << rand_int() << " ";
    }
    cout << endl;
	return 0;
}
