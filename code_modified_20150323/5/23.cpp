#include <iostream>
using namespace std;

int main()
{
    cout << "���������뱻�����ͳ�����" << endl;
    int ival1, ival2;
    cin >> ival1 >> ival2;
    if (ival2 == 0)
    {
        cout << "��������Ϊ0" << endl;
        return -1;
    }
    cout << "��������Ľ���ǣ�" << ival1 / ival2 << endl;
    return 0;
}
