#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> iflst = {1, 2, 3, 4, 5, 6, 7, 8};
    auto prev = iflst.before_begin();     // ǰ��Ԫ��
    auto curr = iflst.begin();            // ��ǰԪ��
    while (curr != iflst.end())
    {
        if (*curr & 1)                      // ����
        {
            curr = iflst.erase_after(prev);   // ɾ�����ƶ�����һԪ��
        }
        else
        {
            prev = curr;                // ǰ���͵�ǰ����������ǰ�ƽ�
            curr++;
        }
    }

    for (curr = iflst.begin(); curr != iflst.end(); curr++)
    {
        cout << *curr << " ";
    }
    cout << endl;

    return 0;
}
