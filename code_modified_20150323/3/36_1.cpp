#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    const int sz = 5;  //����sz��Ϊ�����ά��
    int a[sz], b[sz], i;
    srand((unsigned) time(NULL));    //�������������
    //ͨ��forѭ��Ϊ����Ԫ�ظ�ֵ
    for (i = 0; i < sz; i++)
    {
        //ÿ��ѭ������һ��10���ڵ����������ӵ�a��
        a[i] = rand() % 10;
    }

    cout << "ϵͳ�����Ѿ����ɣ����������²��5�����֣�0~9���������ظ���" << endl;
    int uVal;
    //ͨ��forѭ��Ϊ����Ԫ�ظ�ֵ
    for (i = 0; i < sz; i++)
    {
        if (cin >> uVal)
        {
            b[i] = uVal;
        }
    }

    cout << "ϵͳ���ɵ������ǣ�" << endl;
    for (auto val : a)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "���²�������ǣ�" << endl;
    for (auto val : b)
    {
        cout << val << " ";
    }
    cout << endl;

    int *p = begin(a), *q = begin(b);  //��p,q�ֱ�ָ������a��b����Ԫ��
    while (p != end(a) && q != end(b))
    {
        if (*p != *q)
        {
            cout << "���Ĳ²�����������鲻���" << endl;
            return -1;
        }
        p++;            //p����ƶ�һλ
        q++;            //q����ƶ�һλ
    }
	cout << "��ϲ��ȫ���¶��ˣ�" << endl;

    return 0;
}
