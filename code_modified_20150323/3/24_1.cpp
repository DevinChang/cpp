#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vInt;
    int iVal;
    cout << "������һ�����֣�" << endl;
    while (cin >> iVal)
    {
        vInt.push_back(iVal);
    }
    if(vInt.cbegin() == vInt.cend())
    {
        cout << "û���κ�Ԫ��" << endl;
        return -1;
    }

    cout << "��������ĺ������ǣ�" << endl;
    //����auto�ƶ�it������
    for (auto it = vInt.cbegin(); it != vInt.cend() - 1; it++)
    {
        //����������ĺ�
        cout << (*it + *(++it)) << " ";
        //ÿ�����5������
        if ((it - vInt.cbegin() + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    //���Ԫ�����������������������һ��Ԫ��
    if (vInt.size() % 2 != 0)
    {
        cout << *(vInt.cend() - 1);
    }

    return 0;
}
