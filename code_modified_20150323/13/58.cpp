#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo
{
public:
    Foo sorted() &&; 		// �����ڿɸı����ֵ
    Foo sorted() const &; 	// �������κ����͵�Foo
    // Foo��������Ա�Ķ���
private:
    vector<int> data;
};

// ������Ϊ��ֵ����˿���ԭַ����
Foo Foo::sorted() &&
{
    cout << "��ֵ���ð汾" << endl;
    sort(data.begin(), data.end());
    return *this;
}

// ��������const����һ����ֵ������������Ƕ����ܶ������ԭַ����
Foo Foo::sorted() const &
{
    cout << "��ֵ���ð汾" << endl;
    Foo ret(*this); 							// ����һ������
    return ret.sorted();
    // return Foo(*this).sorted();
}

int main(int argc, char **argv)
{
    Foo f;
    f.sorted();
    return 0;
}
