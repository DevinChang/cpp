#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item trans1, trans2;
    int num = 1;
    std::cout << "�������������ۼ�¼��" << std::endl;
    if (std::cin >> trans1)
    {
        while (std::cin >> trans2)
        {
            if (compareIsbn(trans1, trans2)) // ISBN ��ͬ
            {
                num++;
            }
            else // ISBN ��ͬ
            {
                std::cout << trans1.isbn() << "����" << num << "�����ۼ�¼" << std::endl;
                trans1 = trans2;
                num = 1;
            }
        }
        std::cout << trans1.isbn() << "����" << num << "�����ۼ�¼" << std::endl;
    }
    else
    {
        std::cout << "û������" << std::endl;
        return -1;
    }
    return 0;
}
