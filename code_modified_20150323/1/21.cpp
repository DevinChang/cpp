#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item trans1, trans2;
    std::cout << "����������ISBN��ͬ�����ۼ�¼��" << std::endl;
    std::cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2))
    {
        std::cout << "������Ϣ��ISBN���۳����������۶��ƽ���ۼ�Ϊ " << trans1 + trans2 << std::endl;
    }
    else
    {
        std::cout << "�������ۼ�¼��ISBN��ͬ" << std::endl;
    }
    return 0;
}
