#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //��vector�����¼�������ε���������ʼֵ��Ϊ0
    vector<unsigned> vUS(11);
    auto it = vUS.begin();
    int iVal, iCount = 0;
    cout << "������һ��ɼ���0~100����" << endl;
    while (cin >> iVal)
    {
        if (iVal < 101)  //�ɼ�Ӧ�ں���Χ֮��
        {
            ++*(it + iVal / 10);    //���õ�������λ����Ӧ��Ԫ�أ���1
            ++iCount;
        }
    }
    cout << "���ܼ������� " << iCount << " ���ɼ�" << endl;
    cout << "�������ε������ֲ��ǣ��ɼ��ӵ͵��ߣ���" << endl;
    //���õ���������vUS��Ԫ�ز�������
    for (it = vUS.begin(); it != vUS.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
