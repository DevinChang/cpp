#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    const int sz = 5;  //����sz��Ϊvector������
    int i;
    vector<int> a, b;
    srand((unsigned) time(NULL));    //�������������
    //ͨ��forѭ��Ϊ����Ԫ�ظ�ֵ
    for (i = 0; i < sz; i++)
    {
        //ÿ��ѭ������һ��10���ڵ����������ӵ�a��
        a.push_back(rand() % 10);
    }

    cout << "ϵͳ�����Ѿ����ɣ����������²��5�����֣�0~9���������ظ���" << endl;
    int uVal;
    //ͨ��forѭ��Ϊ����Ԫ�ظ�ֵ
    for (i = 0; i < sz; i++)
    {
        if (cin >> uVal)
        {
            b.push_back(uVal);
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

	//��it1,it2�ֱ�ָ��vector����a��b����Ԫ��
    auto it1 = a.cbegin(), it2 = b.cbegin();
    while (it1 != a.cend() && it2 != b.cend())
    {
        if (*it1 != *it2)
        {
            cout << "���Ĳ²��������vector�����" << endl;
            return -1;
        }
        it1++;            //p����ƶ�һλ
        it2++;            //q����ƶ�һλ
    }
	cout << "��ϲ��ȫ���¶��ˣ�" << endl;

    return 0;
}
