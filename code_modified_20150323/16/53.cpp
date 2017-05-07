#include <iostream>
#include <string>
using namespace std;

// ������ֹ�ݹ鲢��ӡ���һ��Ԫ�صĺ���
// �˺��������ڿɱ�����汾��print����֮ǰ����
template<typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t << endl; // �������һ��Ԫ��֮�󲻴�ӡ�ָ���
}

// ���г������һ��Ԫ��֮�������Ԫ�ض����������汾��print
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)//��չArgs
{
    os << t << ", ";            // ��ӡ��һ��ʵ��
    return print(os, rest...);  // ��չrest���ݹ��ӡ��������
}

int main()
{
    int i = 0;
    string s = "Hello";

    print(cout, i);
    print(cout, i, s);
    print(cout, i, s, 42.1, 'A', "End");
	return 0;
}

