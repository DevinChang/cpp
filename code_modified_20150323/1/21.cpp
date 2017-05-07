#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item trans1, trans2;
    std::cout << "请输入两条ISBN相同的销售记录：" << std::endl;
    std::cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2))
    {
        std::cout << "汇总信息：ISBN、售出本数、销售额和平均售价为 " << trans1 + trans2 << std::endl;
    }
    else
    {
        std::cout << "两条销售记录的ISBN不同" << std::endl;
    }
    return 0;
}
