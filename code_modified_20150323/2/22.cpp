#include <iostream>

int main()
{
    int i = 0;
    int *p1 = nullptr;
    int *p = &i;
    if (p1)	// 检验指针的值（即指针所指对象的地址）
    {
        std::cout<<"p1 pass"<< std::endl;
    }
    if (p)	//检验指针的值（即指针所指对象的地址）
    {
        std::cout<<"p pass"<< std::endl;
    }
    if (*p)	//检验指针所指对象的值
    {
        std::cout<<"i pass"<< std::endl;
    }
    return 0;
}
