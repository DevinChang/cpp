#include <iostream>
using namespace std;

//�ú���ͬʱʹ�����βΡ���ͨ�ֲ������;�̬�ֲ�����
double myADD(double val1, double val2)  //val1��val2���β�
{
    double result = val1 + val2;    //result����ͨ�ֲ�����
    static unsigned iCnt = 0;       //iCnt�Ǿ�̬�ֲ�����
    ++iCnt;
    cout << "�ú����Ѿ��ۼ�ִ����" << iCnt << "��" << endl;
    return result;
}

int main()
{
    double num1, num2;
    cout << "��������������";
    while (cin >> num1 >> num2)
    {
        cout << num1 << "��" << num2 << "����ͽ���ǣ�" << myADD(num1, num2) << endl;
    }
    return 0;
}
