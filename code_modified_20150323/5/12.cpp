#include <iostream>
using namespace std;

int main()
{
    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, prech = '\0';
    cout << "������һ���ı���" << endl;
    while (cin >> ch)
    {
        bool bl = true;
        if (prech == 'f')
        {
            switch(ch)
            {
                case 'f':
                    ++ffCnt;
                    bl = false;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
            }
        }
        if (!bl)
        {
            prech = '\0';
        }
        else
        {
            prech = ch;
        }
    }
    cout << "ff�������ǣ�" << ffCnt << endl;
    cout << "fl�������ǣ�" << flCnt << endl;
    cout << "fi�������ǣ�" << fiCnt << endl;
    return 0;
}
