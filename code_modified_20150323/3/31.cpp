#include <iostream>
using namespace std;

int main()
{
    const int sz = 10;  //����sz��Ϊ�����ά��
    int a[sz];
    //ͨ��forѭ��Ϊ����Ԫ�ظ�ֵ
    for (int i = 0; i < sz; i++)
    {
        a[i] = i;
    }
    //ͨ����Χforѭ����������ȫ��Ԫ��
    for (auto val : a)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
