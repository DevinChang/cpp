#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // ������������copy���int����
    copy(vi.begin(), vi.end(), out_iter);
    cout << endl;

    list<int> li;
    // ��vi[2]��Ҳ���ǵ�����Ԫ�ص�λ��ת��Ϊ���������
    vector<int>::reverse_iterator re(vi.begin() + 2);
    // ��vi[7]��Ҳ���ǵڰ˸�Ԫ�ص�λ��ת��Ϊ���������
    vector<int>::reverse_iterator rb(vi.begin() + 7);
    // �÷����������Ԫ�����򿽱���list
    copy(rb, re, back_inserter(li));
    copy(li.begin(), li.end(), out_iter);
    cout << endl;
    return 0;
}
