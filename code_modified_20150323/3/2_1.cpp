#include <iostream>
#include <string>
using namespace std;

int main()  //ʹ��getlineһ�ζ���һ���У����س�����
{
    string line;
    // ѭ����ȡ��ÿ�ζ���һ���У�ֱ���ļ������������쳣����
    cout << "�����������ַ��������԰����ո�" << endl;
    while (getline(cin, line))
    {
        cout << line << endl;
    }

    return 0;
}
