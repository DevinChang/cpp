#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    // ���캯�������µ�string���µļ�����������������Ϊ1
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
    // �������캯�����������������ݳ�Ա��������������
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }  // �������캯��
    HasPtr& operator=(const HasPtr&);  // ������ֵ�����
    HasPtr& operator=(const string&);  // ������string
    string& operator*();       // ������
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *use; // ������¼�ж��ٸ�������*ps�ĳ�Ա
};

HasPtr::~HasPtr()
{
    if (--*use == 0) 	// ������ü�����Ϊ0
    {
        delete ps; 		// �ͷ�string�ڴ�
        delete use; 		// �ͷż������ڴ�
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use; // �����Ҳ������������ü���
    if (--*use == 0) 	// Ȼ��ݼ�����������ü���
    {
        delete ps; 		// ���û�������û�
        delete use; 		// �ͷű��������ĳ�Ա
    }
    ps = rhs.ps; 		// �����ݴ�rhs������������
    i = rhs.i;
    use = rhs.use;
    return *this; 		// ���ر�����
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
    HasPtr h2 = h;  // δ������string��h2��hָ����ͬ��string
    h = "hi dad!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    return 0;
}
