#include <iostream>
#include <string>
using namespace std;

//������û����ʽ����Ĭ�Ϲ��캯����������Ҳ����Ϊ���ϳ�һ��
class NoDefault
{
public:
    NoDefault(int i)
    {
        val = i;
    }
    int val;
};

class C
{
public:
    NoDefault nd;
    //������ʽ����Nodefault�Ĵ��ι��캯����ʼ��nd
    C(int i = 0) : nd(i) { }
};

int main()
{
    C c;    //ʹ��������C��Ĭ�Ϲ��캯��
    cout << c.nd.val << endl;
    return 0;
}
