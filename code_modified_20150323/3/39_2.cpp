#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[80], str2[80];
    cout << "�����������ַ�����" << endl;
    cin >> str1 >> str2;
    //����cstringͷ�ļ������strcmp�����Ƚϴ�С
    auto result = strcmp(str1, str2);
    switch (result)
    {
    case 1:
        cout << "��һ���ַ������ڵڶ����ַ���" << endl;
        break;
    case -1:
        cout << "��һ���ַ���С�ڵڶ����ַ���" << endl;
        break;
    case 0:
        cout << "�����ַ������" <<endl;
        break;
    default:
        cout << "δ����Ľ��" << endl;
        break;
    }

    return 0;
}
