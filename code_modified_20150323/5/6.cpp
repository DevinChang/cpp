#include <iostream>
using namespace std;

int main()
{
    int grade;
    cout << "���������ĳɼ���";
    cin >> grade;
    if (grade < 0 || grade > 100)
    {
        cout << "�óɼ����Ϸ�" << endl;
        return -1;
    }
    if (grade == 100)    //�������ֵ����
    {
        cout << "�ȼ��ɼ��ǣ�" << "A++" << endl;
        return -1;
    }
    if (grade < 60)      //������������
    {
        cout << "�ȼ��ɼ��ǣ�" << "F" << endl;
        return -1;
    }
    
    int iU = grade / 10;    //�ɼ���ʮλ��
    int iT = grade % 10;    //�ɼ��ĸ�λ��
    string score, level, lettergrade;
    //���ݳɼ���ʮλ����ȷ��score
    score = (iU == 9) ? "A"
                      : (iU == 8) ? "B"
                                  : (iU == 7) ? "C" : "D";
    //���ݳɼ��ĸ�λ����ȷ��level
    level = (iT < 3) ? "-"
                     : (iT > 7) ? "+" : "";
    //�ۼ���õȼ��ɼ�
    lettergrade = score + level;
    cout << "�ȼ��ɼ��ǣ�" << lettergrade << endl;

    return 0;
}
