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
    if (vInt.cbegin() == vInt.cend())
    {
        cout << "û���κ�Ԫ��" << endl;
        return -1;
    }

    cout << "��β����ĺ������ǣ�" << endl;
    auto beg = vInt.begin();
    auto end = vInt.end();
    //����auto�ƶ�it������
    for (auto it = beg; it != beg + (end - beg) / 2; it++)
    {
        //����β����ĺ�
        cout << (*it + *(beg + (end - it) - 1)) << " ";
        //ÿ�����5������
        if ((it - beg + 1) % 5 == 0)
        {
            cout << endl;
        }
    }
    //���Ԫ�����������������������һ��Ԫ��
    if (vInt.size() % 2 != 0)
    {
        cout << *(beg + (end - beg) / 2);
    }

    return 0;
}
