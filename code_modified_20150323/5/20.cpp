#include <iostream>
#include <string>
using namespace std;

int main()
{
    string currString, preString;
    bool bl = true;
    cout << "������һ���ַ�����" << endl;
    while (cin >> currString)
    {
        if (currString == preString)
        {
            bl = false;
            cout << "�������ֵ��ַ����ǣ�" << currString << endl;
            break;
        }
        preString = currString;
    }
    
    if (bl)
    {
        cout << "û���������ֵ��ַ���" << endl;
    }
    return 0;
}
