#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << "v1��Ԫ�ظ����ǣ�" << v1.size() << endl;
    if (v1.size() > 0)       //��vector����Ԫ��ʱ������
    {
        cout << "v1��Ԫ�طֱ��ǣ�" << endl;
        for(auto e : v1)    //ʹ�÷�Χfor������ÿһ��Ԫ��
        {
            cout << e << " ";
        }
        cout << endl;
    }

    cout << "v2��Ԫ�ظ����ǣ�" << v2.size() << endl;
    if (v2.size() > 0)       //��vector����Ԫ��ʱ������
    {
        cout << "v2��Ԫ�طֱ��ǣ�" << endl;
        for(auto e : v2)    //ʹ�÷�Χfor������ÿһ��Ԫ��
        {
            cout << e << " ";
        }
        cout << endl;
    }

    cout << "v3��Ԫ�ظ����ǣ�" << v3.size() << endl;
    if (v3.size() > 0)       //��vector����Ԫ��ʱ������
    {
        cout << "v3��Ԫ�طֱ��ǣ�" << endl;
        for(auto e : v3)    //ʹ�÷�Χfor������ÿһ��Ԫ��
        {
            cout << e << " ";
        }
        cout << endl;
    }

    cout << "v4��Ԫ�ظ����ǣ�" << v4.size() << endl;
    if (v4.size() > 0)       //��vector����Ԫ��ʱ������
    {
        cout << "v4��Ԫ�طֱ��ǣ�" << endl;
        for(auto e : v4)    //ʹ�÷�Χfor������ÿһ��Ԫ��
        {
            cout << e << " ";
        }
        cout << endl;
    }

    cout << "v5��Ԫ�ظ����ǣ�" << v5.size() << endl;
    if (v5.size() > 0)       //��vector����Ԫ��ʱ������
    {
        cout << "v5��Ԫ�طֱ��ǣ�" << endl;
        for(auto e : v5)    //ʹ�÷�Χfor������ÿһ��Ԫ��
        {
            cout << e << " ";
        }
        cout << endl;
    }

    cout << "v6��Ԫ�ظ����ǣ�" << v6.size() << endl;
    if (v6.size() > 0)       //��vector����Ԫ��ʱ������
    {
        cout << "v6��Ԫ�طֱ��ǣ�" << endl;
        for(auto e : v6)    //ʹ�÷�Χfor������ÿһ��Ԫ��
        {
            cout << e << " ";
        }
        cout << endl;
    }

    cout << "v7��Ԫ�ظ����ǣ�" << v7.size() << endl;
    if (v7.size() > 0)       //��vector����Ԫ��ʱ������
    {
        cout << "v7��Ԫ�طֱ��ǣ�" << endl;
        for(auto e : v7)    //ʹ�÷�Χfor������ÿһ��Ԫ��
        {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}
