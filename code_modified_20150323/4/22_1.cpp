#include <iostream>
#include <string>
using namespace std;

int main()
{
    string finalgrade;
    int grade;
    cout << "��������Ҫ���ĳɼ���" << endl;
    //ȷ������ĳɼ��Ϸ�
    while (cin >> grade && grade >= 0 && grade <= 100)
    {
        //ʹ������Ƕ�׵��������ʽ
        finalgrade = (grade > 90) ? "high pass"
                              : (grade > 75) ? "pass"
                                             : (grade > 60) ? "low pass" : "fail";
        cout << "�óɼ������ĵ����ǣ�" << finalgrade << endl;
        cout << "��������Ҫ���ĳɼ���" << endl;
    }

    return 0;
}
