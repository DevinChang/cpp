#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> ilst = {0,1,2,3,4,5,6,7,8,9};
    auto curr = ilst.begin();        // �׽��

    while (curr != ilst.end())
    {
        if (*curr & 1)  // ����
        {
            curr = ilst.insert(curr, *curr); // ���뵽��ǰԪ��֮ǰ
            curr++; curr++; // �ƶ�����һԪ��
        }
        else            // ż��
        {
            curr = ilst.erase(curr);   // ɾ����ָ����һԪ��
        }
    }

    for (curr = ilst.begin(); curr != ilst.end(); curr++)
    {
        cout << *curr << " ";
    }
    cout << endl;

    return 0;
}
