#include <iostream>
using namespace std;

//�ú���������ͳ��ִ�еĴ���
unsigned myCnt()  //��ɸú�����������Ҫ�κβ���
{
    static unsigned iCnt = -1;       //iCnt�Ǿ�̬�ֲ�����
    ++iCnt;
    return iCnt;
}

int main()
{
    cout << "�����������ַ��󰴻س�������" << endl;
    char ch;
    while (cin >> ch)
    {
        cout << "����myCnt()��ִ�д����ǣ�" << myCnt() << endl;
    }
    return 0;
}
