#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    list<int> li = { 0, 1, 2, 0, 3, 4, 5, 0, 6};
    // ���÷���������������һ��0
    auto last_z = find(li.rbegin(), li.rend(), 0);
    // ��������������ͷ�����ƽ�һ��λ��
    // ת��Ϊ��ͨ������ʱ�����ص����һ��0��λ��
    last_z++;
    int p = 1;
    // ��base��last_zת��Ϊ��ͨ������
    // ������ͷ��ʼ�������������һ��0�ı��
    for (auto iter = li.begin(); iter != last_z.base(); iter++, p++)
    {
    }

    if (p >= li.size())   // δ�ҵ�0
    {
        cout << "������û��0" << endl;
    }
    else
    {
        cout << "���һ��0�ڵ�" << p << "��λ��" << endl;
    }

    return 0;
}
