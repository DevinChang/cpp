#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data book;
    std::cout << "请输入销售记录："<< std::endl;
    while (std::cin >> book)
    {
        std::cout << " ISBN、售出本数、原始价格、原始价格、实售价格、折扣为" << book << std::endl;
    }

    Sales_data trans1, trans2;
    std::cout << "请输入两条ISBN相同的销售记录：" << std::endl;
    std::cin.clear();  // 清空输入流的错误状态标志位，以便后面继续输入。
    std::cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2))
    {
        std::cout << "汇总信息：ISBN、售出本数、原始价格、实售价格、折扣为 " << trans1 + trans2 << std::endl;
    }
    else
    {
        std::cout << "两条销售记录的ISBN不同" << std::endl;
    }

    Sales_data total, trans;
    std::cout << "请输入几条ISBN相同的销售记录：" << std::endl;
    std::cin.clear(); // 清空输入流的错误状态标志位，以便后面继续输入。
    if (std::cin >> total)
    {
        while (std::cin >> trans)
        {
            if (compareIsbn(total, trans)) // ISBN 相同
            {
                total = total + trans;
            }
            else // ISBN 不同
            {
                std::cout << "当前书籍ISBN不同" << std::endl;
                break;
            }
        }
        std::cout << "有效汇总信息：ISBN、售出本数、原始价格、实售价格、折扣为" << total << std::endl;
    }
    else
    {
        std::cout << "没有数据" << std::endl;
        return -1;
    }

    int num = 1;    //记录当前书籍的销售记录总数
    std::cout << "请输入若干销售记录："<< std::endl;
    std::cin.clear();  // 清空输入流的错误状态标志位，以便后面继续输入。
    if (std::cin >> trans1)
    {
        while (std::cin >> trans2)
        {
            if (compareIsbn(trans1, trans2)) // ISBN 相同
            {
                num++;
            }
            else // ISBN 不同
            {
                std::cout << trans1.isbn() << "共有" << num << "条销售记录" << std::endl;
                trans1 = trans2;
                num = 1;
            }
        }
        std::cout << trans1.isbn() << "共有" << num << "条销售记录" << std::endl;
    }
    else
    {
        std::cout << "没有数据" << std::endl;
        return -1;
    }

    return 0;
}
