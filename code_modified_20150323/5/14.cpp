#include <iostream>
#include <string>
using namespace std;

int main()
{
    //����3���ַ����������ֱ��ʾ��
    //��ǰ�������ַ�����ǰһ���ַ�������ǰ���ִ��������ַ���
    string currString, preString = "", maxString;
    //����2�����ͱ������ֱ��ʾ��
    //��ǰ�������ֵ��ַ�����������ǰ���ִ��������ַ�������
    int currCnt = 1, maxCnt = 0;
    while (cin >> currString)    //���ÿ���ַ���
    {
        if (currString == preString) //�����ǰ�ַ�����ǰһ���ַ���һ�£�����״̬
        {
            ++currCnt;
            if (currCnt > maxCnt)
            {
                maxCnt = currCnt;
                maxString = currString;
            }
        }
        else //�����ǰ�ַ�����ǰһ���ַ�����һ�£�����currCnt
        {
            currCnt = 1;
        }
        preString = currString; //����preString�Ա�����һ��ѭ��ʹ��
    }

    if (maxCnt > 1)
    {
        cout << "���������ַ����ǣ�" << maxString << "�������ǣ�" << maxCnt << endl;
    }
    else
    {
        cout << "ÿ���ַ�����ֻ������һ��" << endl;
    }
    return 0;
}
