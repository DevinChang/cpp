#include <iostream>
using namespace std;

int main()
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << "���÷�Χfor��������ά��������ݣ�" << endl;
    for (auto &row : ia)
    {
        for (auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    cout << "������ͨfor�����±�����������ά��������ݣ�" << endl;
    for (auto i = 0; i != 3; i++)
    {
        for (auto j = 0; j != 4; j++)
        {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }

    cout << "������ͨfor����ָ�������ά��������ݣ�" << endl;
    for (auto p = ia; p != ia + 3; p++)
    {
        for (auto q = *p; q != *p + 4; q++)
        {
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}
