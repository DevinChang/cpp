#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    const int sz = 10;  //����sz��Ϊvector���������
    vector<int> vInt;
    srand((unsigned) time(NULL)); //�������������
    cout << "vector����������ǣ�" << endl;
    //����forѭ������vector�����ÿ��Ԫ��
    for (int i = 0; i != sz; i++)
    {
        vInt.push_back(rand() % 100);   //����һ��100���ڵ������
        cout << vInt[i] << " ";
    }
    cout << endl;

    auto it = vInt.cbegin();
    int a[vInt.size()];
    cout << "����������ǣ�" << endl;
    //���÷�Χforѭ�����������ÿ��Ԫ��
    for (auto &val : a)
    {
        val = *it;
        cout << val << " ";
        it++;
    }
    cout << endl;
    return 0;
}
