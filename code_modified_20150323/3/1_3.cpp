#include <iostream>
//ʹ��using����ʹ��cin��cout��endl�ڳ����пɼ�
using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "������������";
    cout << endl;
    int v1, v2;
    cin >> v1 >> v2;
    if (v1 > v2)	// �ɴ���С��ӡ
    {
        while (v1 >= v2)
        {
            cout << v1 << " ";
            v1--;
        }
    }
    else				// ��С�����ӡ
    {
        while (v1 <= v2)
        {
            cout << v1 << " ";
            v1++;
        }
    }
    cout << endl;
    return 0;
}
