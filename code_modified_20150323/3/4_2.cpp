#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cout << "�����������ַ�����" << endl;
    cin >> s1 >> s2;
    auto len1 = s1.size();
    auto len2 = s2.size();
    if (len1 == len2)
    {
        cout << s1 << " �� " << s2 << " �ĳ��ȶ��� " << len1 << endl;
    }
    else if (len1 > len2)
    {
        cout << s1 << " �� " << s2 << " �ĳ��ȶ� " << len1 - len2 << endl;
    }
    else
    {
        cout << s1 << " �� " << s2 << " �ĳ���С " << len2 - len1 << endl;
    }
    return 0;
}
