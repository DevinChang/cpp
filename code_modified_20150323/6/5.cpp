#include <iostream>
#include <cmath>
using namespace std;

//��һ������ͨ��if-else���������ֵ
double myABS(double val)
{
    if (val < 0)
    {
        return val * -1;
    }
    else
    {
        return val;
    }
}

//�ڶ�����������cmathͷ�ļ���abs�����������ֵ
double myABS2(double val)
{
    return abs(val);
}

int main()
{
    double num;
    cout << "������һ������";
    cin >> num;
    cout << num << "�ľ���ֵ�ǣ�" << myABS(num) << endl;
    cout << num << "�ľ���ֵ�ǣ�" << myABS2(num) << endl;
    return 0;
}
