#include <iostream>
#include <vector>
using namespace std;

vector<int>::iterator search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
    for (; beg != end; beg++)     // ������Χ
    {
        if (*beg == val)          // ����Ƿ������ֵ���
        {
            return beg;             // �����ɹ�������Ԫ�ض�Ӧ������
        }
    }
    return end;                 // ����ʧ�ܣ�����β�������
}

int main()
{
  vector<int> ilist = {1, 2, 3, 4, 5, 6, 7};
  cout << search_vec(ilist.begin(), ilist.end(), 3) - ilist.begin() << endl;
  cout << search_vec(ilist.begin(), ilist.end(), 8) - ilist.begin() << endl;

  return 0;
}
