#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
    cout << "�����������ַ�����" << endl;
    cin >> str1 >> str2;

    if (str1 > str2)
    {
        cout << "��һ���ַ������ڵڶ����ַ���" << endl;
    }
    else if (str1 < str2)
    {
        cout << "��һ���ַ���С�ڵڶ����ַ���" << endl;
    }
    else
    {
        cout << "�����ַ������" <<endl;
    }
    return 0;
}
