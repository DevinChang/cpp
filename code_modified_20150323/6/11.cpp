#include <iostream>
using namespace std;

void reset(int &i)
{
    i = 0;
}

int main()
{
    int num = 10;
    cout << "����ǰ��num = " << num << endl;
    reset(num);
    cout << "���ú�num = " << num << endl;
    return 0;
}
