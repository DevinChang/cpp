#include <iostream>
//ʹ��using����ʹ��cout��endl�ڳ����пɼ�
using std::cout;
using std::endl;

int main()
{
    int sum = 0;
    int i = 50;
    while (i <= 100)
    {
        sum += i;
        i++;
    }
    cout << "50��100֮�������֮��Ϊ" << sum << endl;
    return 0;
}
