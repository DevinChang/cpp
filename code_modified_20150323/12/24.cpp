#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char **argv)
{
    char c;

    // ����20���ַ��Ķ�̬����
    // ��������19���ַ�
    char *r = new char[20];
    int l = 0;

    while (cin.get(c))
    {
        if (isspace(c)) // �ո��Ʊ�ȿհ׷�
        {
            break;
        }
        r[l++] = c;     // ���붯̬����
        if (l == 20)  // �Ѷ���19���ַ�
        {
            cout << "�ﵽ������������" << endl;
            break;
        }
    }
    r[l] = 0;
    cout << r << endl;

    // �ͷŶ�̬����
    delete [] r;
    return 0;
}
