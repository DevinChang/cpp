#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i)   // �������캯��
    {
        cout << "Copy Constructor" << endl;
    }
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) // �ƶ����캯��
    {
        p.ps = 0; cout << "Move Constructor" << endl;
    }
    HasPtr& operator=(const HasPtr&);  // ������ֵ�����
    HasPtr& operator=(HasPtr&&) noexcept;  // �ƶ���ֵ�����
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
    cout << "Copy Assignment" << endl;
    auto newps = new string(*rhs.ps); // ����ָ��ָ��Ķ���
    delete ps;					// ����ԭstring
    ps = newps;					// ָ����string
    i = rhs.i; 					// ʹ�����õ�int��ֵ
    return *this; 				// ����һ���˶��������
}

inline HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept
{
    cout << "Move Assignment" << endl;
    if (this != &rhs)
    {
        delete ps;      // �ͷž�string
        ps = rhs.ps;		// ��rhs�ӹ�string
        rhs.ps = nullptr;		// ��rhs����������ȫ״̬
        rhs.i = 0;
    }
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
    {
        HasPtr h2(h);  // �������캯��
        HasPtr h3(std::move(h2));  // �ƶ����캯��
    }

    {
        HasPtr h2, h3;
        h2 = h;  // ������ֵ�����
        h3 = std::move(h2);  // �ƶ���ֵ�����
    }

    return 0;
}
