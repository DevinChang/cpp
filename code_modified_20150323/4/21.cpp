#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    vector<int> vInt;
    const int sz = 10;  //ʹ��sz��Ϊ�����ά��
    srand((unsigned) time(NULL)); //�������������
    //ʹ����ͨforѭ��Ϊ���鸳��ֵ
    cout << "����ĳ�ʼֵ�ǣ�" << endl;
    for (int i = 0; i != sz; ++i)
    {
        vInt.push_back(rand() % 100);   //����100���ڵ������
        cout << vInt[i] << " "; //ʹ���±�����������������
    }
    cout << endl;
    
    //ʹ�÷�Χforѭ���������е���������
    for (auto &val : vInt)
    {
        val = (val % 2 != 0) ? val * 2 : val;   //�������ʽ
    }
    //ʹ�÷�Χforѭ���͵������������ĵ�ǰֵ
    cout << "�����������ֵ�ǣ�" << endl;
    for (auto it = vInt.cbegin(); it != vInt.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
