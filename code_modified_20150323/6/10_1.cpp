#include <iostream>
using namespace std;

//�ں������ڲ�ͨ�������ò����ı�ָ����ָ������
void mySWAP(int *p, int *q)
{
    int tmp = *p;	//tmp�Ǹ�����
    *p = *q;
    *q = tmp;
}

int main()
{
    int a = 5, b = 10;
    int *r = &a, *s = &b;
    cout << "����ǰ��a = " << a << "��b = " << b << endl;
    mySWAP(r, s);
    cout << "������a = " << a << "��b = " << b << endl;
    return 0;
}
