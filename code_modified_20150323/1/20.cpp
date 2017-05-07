#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book;
    std::cout << "请输入销售记录：" << std::endl;
    while (std::cin >> book)
    {
        std::cout << "ISBN、售出本数、销售额和平均售价为 " << book << std::endl;
    }
    return 0;
}
