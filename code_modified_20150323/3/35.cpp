#include <iostream>
using namespace std;

int main()
{
    const int sz = 10;  //����sz��Ϊ�����ά��
    int a[sz], i = 0;
    //ͨ��forѭ��Ϊ����Ԫ�ظ�ֵ
    for (i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    cout << "��ʼ״̬������������ǣ�" << endl;
    for (auto val : a)
    {
        cout << val << " ";
    }
    cout << endl;

    int *p = begin(a);  //��pָ��������Ԫ��
    while (p != end(a))
    {
        *p = 0;         //�޸�p��ָԪ�ص�ֵ
        p++;            //p����ƶ�һλ
    }
    cout << "�޸ĺ�����������ǣ�" << endl;
    //ͨ����Χforѭ����������ȫ��Ԫ��
    for (auto val : a)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

