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
    if (vInt.size() == 0)
    {
        cout << "û���κ�Ԫ��" << endl;
        return -1;
    }

    cout << "��β����ĺ������ǣ�" << endl;
    //����decltype�ƶ�i������
    for (decltype(vInt.size()) i = 0; i < vInt.size() / 2; i++)
    {
        //����β����ĺ�
        cout << vInt[i] + vInt[vInt.size() - i - 1] << " ";
        //ÿ�����5������
        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }
    //���Ԫ�����������������������һ��Ԫ��
    if (vInt.size() % 2 != 0)
    {
        cout << vInt[vInt.size() / 2];
    }

    return 0;
}
