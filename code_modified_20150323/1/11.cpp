#include <iostream>

int main()
{
    std::cout << "������������";
    std::cout << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    if (v1 > v2)	// �ɴ���С��ӡ
    {
        while (v1 >= v2)
        {
            std::cout << v1 << " ";
            v1--;
        }
    }
    else				// ��С�����ӡ
    {
        while (v1 <= v2)
        {
            std::cout << v1 << " ";
            v1++;
        }
    }
    std::cout << std::endl;
    return 0;
}
