#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> iv = {1, 1, 2, 1};  // int��vector
    int some_val = 1;

    vector<int>::iterator iter = iv.begin();
    int org_size = iv.size(), new_ele = 0;  // ԭ��С����Ԫ�ظ���

    // ÿ��ѭ���������¼��㡰mid������֤��ȷָ��ivԭ����Ԫ��
    while (iter != (iv.begin() + org_size / 2 + new_ele))
    {
        if (*iter == some_val)
        {
            iter = iv.insert(iter, 2 * some_val); // iterָ����Ԫ��
            new_ele++;
            iter++; iter++;  // ��iter�ƽ�����Ԫ�ص���һ��λ��
        }
        else
        { 
            iter++;          // ���ƽ�iter
        }
    }

  // ��begin()��ȡvector��Ԫ�ص�����������vector������Ԫ��
  for (iter = iv.begin(); iter != iv.end(); iter++)
  {
      cout << *iter << endl;
  }

  return 0;
}
