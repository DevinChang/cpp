#include <iostream>
using namespace std;

int main()
{
    const int sz = 10;  //����sz��Ϊ�����ά��
    int a[sz], b[sz];
    //ͨ��forѭ��Ϊ����Ԫ�ظ�ֵ
    for (int i = 0; i < sz; i++)
    {
        a[i] = i;
    }
    for (int j = 0; j < sz; j++)
    {
        b[j] = a[j];
    }
    //ͨ����Χforѭ����������ȫ��Ԫ��
    for (auto val : b)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
