#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    cout << "���������뱻�����ͳ�����" << endl;
    int ival1, ival2;
    while (cin >> ival1 >> ival2)
    {
        try
        {
            if (ival2 == 0)
            {
                throw runtime_error("��������Ϊ0");
            }
            cout << "��������Ľ���ǣ�" << ival1 / ival2 << endl;
        }
        catch (runtime_error err)
        {
            cout << err.what() << endl;
            cout << "��Ҫ������y or n����";
            char ch;
            cin >> ch;
            if(ch != 'y' && ch != 'Y')
            {
                break;
            }
        }
    }

    return 0;
}
