#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total, trans;
    std::cout << "�����뼸��ISBN��ͬ�����ۼ�¼��" << std::endl;
    if (std::cin >> total)
    {
        while (std::cin >> trans)
        {
            if (compareIsbn(total, trans)) // ISBN ��ͬ
            {
                total = total + trans;
            }
            else // ISBN ��ͬ
            {
                std::cout << "ISBN��ͬ" << std::endl;
                return -1;
            }
        }
        std::cout << "������Ϣ��ISBN���۳����������۶��ƽ���ۼ�Ϊ " << total << std::endl;
    }
    else
    {
        std::cout << "û������" << std::endl;
        return -1;
    }
    return 0;
}
