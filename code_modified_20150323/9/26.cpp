#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> iv;
    list<int> il;

    iv.assign(ia, ia + 11);   // �����ݿ�����vector
    il.assign(ia, ia + 11);   // �����ݿ�����list

    vector<int>::iterator iiv = iv.begin();
    while (iiv != iv.end())
    {
        if (!(*iiv & 1))        // ż��
        {
            iiv = iv.erase(iiv);  // ɾ��ż����������һλ�õ�����
        }
        else
        {
            iiv++;             // �ƽ�����һλ��
        }
    }

    list<int>::iterator iil = il.begin();
    while (iil != il.end())
    {
        if (*iil & 1)           // ����
        {
            iil = il.erase(iil);  // ɾ��������������һλ�õ�����
        }
        else
        {
            iil++;             // �ƽ�����һλ��
        }
    }

    for (iiv = iv.begin(); iiv != iv.end(); iiv++)
    {
        cout << *iiv << " ";
    }
    cout << endl;
  
    for (iil = il.begin(); iil != il.end(); iil++)
    {
        cout << *iil << " ";
    }
    cout << endl;

    return 0;
}
