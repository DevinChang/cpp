#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::to_string;

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { }  // �������캯��
    HasPtr& operator=(const HasPtr&);  // ������ֵ�����
    HasPtr& operator=(const string&);  // ������string
    string& operator*();       // ������
    bool operator<(const HasPtr&) const; // �Ƚ�����
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
    return *this; 				// ���ش˶��������
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

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    cout << "���� " << *lhs.ps << "��" << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);	// ����ָ�룬������string����
    swap(lhs.i, rhs.i);    	// ����int��Ա
}

bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *ps < *rhs.ps;
}

int main(int argc, char **argv)
{
    vector<HasPtr> vh;
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++)
    {
        vh.push_back(to_string(n-i));
    }

    for (auto p : vh)
    {
        cout << *p << " ";
    }
    cout << endl;

    sort(vh.begin(), vh.end());
    for (auto p : vh)
    {
        cout << *p << " ";
    }
    cout << endl;

  	return 0;
}
