#include <iostream>
using namespace std;

void mySWAP(int &i, int &j)
{
    int tmp = i;
    i = j;
    j = tmp;
}

int main()
{
    int a = 5, b = 10;
    cout << "����ǰ��a = " << a << "��b = " << b << endl;
    mySWAP(a, b);
    cout << "������a = " << a << "��b = " << b << endl;
    return 0;
}
