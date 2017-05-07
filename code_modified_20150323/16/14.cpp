#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include "tScreen.h"

int main()
{
    Screen<5,3> myScreen;
    myScreen.display(cout);
    // ������ƶ����ض�λ�ã�������������
    myScreen.move(4,0).set('#');

    Screen<5,5> nextScreen('X');
    nextScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    nextScreen.display(cout);
    cout << endl;

    const Screen<5,3> blank;
    myScreen.set('#').display(cout);  // ���÷�const�汾
    cout << endl;
    blank.display(cout);              // ����const�汾
    cout << endl;

    myScreen.clear('Z').display(cout); cout << endl;
    myScreen.move(4,0);
    myScreen.set('#');
    myScreen.display(cout); cout << endl;
    myScreen.clear('Z').display(cout); cout << endl;

    // ����temp������Screen<5,3>����Screen<5,3>&
    Screen<5,3> temp = myScreen.move(4,0); // �򷵻�ֵ������
    temp.set('#'); // �ı�temp�Ͳ���Ӱ��myScreen
    myScreen.display(cout);
    cout << endl;

    cout << endl;
    cin >> myScreen;
    cout << myScreen << endl << nextScreen << endl << temp << endl;

    return 0;
}
