#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> iflst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = iflst.before_begin(); // ǰ�����
    auto curr = iflst.begin();        // �׽��

    while (curr != iflst.end())
    {
        if (*curr & 1)  // ����
        {
            curr = iflst.insert_after(curr, *curr); // ���뵽��ǰԪ��֮��
            prev = curr;    // prev�ƶ����²���Ԫ��
            curr++;         // curr�ƶ�����һԪ��
        }
        else            // ż��
        {
            curr = iflst.erase_after(prev);   // ɾ����currָ����һԪ��
        }
    }

    for (curr = iflst.begin(); curr != iflst.end(); curr++)
    {
        cout << *curr << " ";
    }
    cout << endl;

    return 0;
}
