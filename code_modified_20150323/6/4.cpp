#include <iostream>
using namespace std;

int fact(int val)
{
    if (val < 0)
    {
        return -1;
    }

    int ret = 1;
    //��1���˵�val
    for (int i = 1; i != val + 1; ++i)
    {
        ret *= i;
    }
    return ret;
}

int main()
{
    int num;
    cout << "������һ��������";
    cin >> num;
    cout << num << "�Ľ׳��ǣ�" << fact(num) << endl;
    return 0;
}
