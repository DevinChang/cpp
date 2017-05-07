#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { }  // �������캯��
    HasPtr& operator=(const HasPtr&);  // ������ֵ�����
    HasPtr& operator=(const string&);  // ������string
    string& operator*();       // ������
    ~HasPtr();
private:
    string *ps;
    int i;
};

HasPtr::~HasPtr()
{
    delete ps; 		// �ͷ�string�ڴ�
}

inline HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newps = new string(*rhs.ps); // ����ָ��ָ��Ķ���
    delete ps;					// ����ԭstring
    ps = newps;					// ָ����string
    i = rhs.i; 					// ʹ�����õ�int��ֵ
    return *this; 				// ����һ���˶��������
}

HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*()
{
    return *ps;
}

int main(int argc, char **argv)
{
    HasPtr h("hi mom!");
    HasPtr h2(h);  // ��Ϊ��ֵ��h2��h3��hָ��ͬstring
    HasPtr h3 = h;
    h2 = "hi dad!";
    h3 = "hi son!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    return 0;
}
