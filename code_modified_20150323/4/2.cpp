#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    vector<int> vec;
    srand((unsigned) time(NULL));
    cout << "ϵͳ�Զ�Ϊ��������һ��Ԫ��......" << endl;
    for (int i = 0; i != 10; i++)
    {
        vec.push_back(rand() % 100);
    }
    cout << "���ɵ����������ǣ�" << endl;
    for (auto c : vec)
    {
        cout << c << " ";
    }
    cout << endl;
    cout << "��֤��ӵ������Ƿ���ȷ��" << endl;
    cout << "*vec.begin()��ֵ�ǣ�" << *vec.begin() <<endl;
    cout << "*(vec.begin())��ֵ�ǣ�" << *(vec.begin()) << endl;
    cout << "*vec.begin()+1��ֵ�ǣ�" << *vec.begin() + 1 <<endl;
    cout << "(*(vec.begin()))+1��ֵ�ǣ�" << (*(vec.begin())) + 1 << endl;

    return 0;
}
