#include <iostream>
#include <string>
using namespace std;

int main()
{
    char cont = 'y';
    string s, result;
    cout << "�������һ���ַ�����" << endl;
    while (cin >> s)
    {
        result += s;
        cout << "�Ƿ������y or n����" << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
        {
            cout << "��������һ���ַ�����" << endl;
        }
        else
        {
            break;
        }
    }
    cout << "ƴ�Ӻ���ַ����ǣ�" << result <<endl;
    return 0;
}
