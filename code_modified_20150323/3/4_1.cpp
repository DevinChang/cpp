#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cout << "�����������ַ�����" << endl;
    cin >> s1 >> s2;
    if (s1 == s2)
    {
        cout << "�����ַ������" << endl;
    }
    else if (s1 > s2)
    {
        cout << s1 << " ���� " << s2 <<endl;
    }
    else
    {
        cout << s2 << " ���� " << s1 <<endl;
    }
    return 0;
}
