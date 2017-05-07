#include <iostream>

int main()
{
    std::cout << "请输入两个数";
    std::cout << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    if (v1 > v2)	// 由大至小打印
    {
        while (v1 >= v2)
        {
            std::cout << v1 << " ";
            v1--;
        }
    }
    else				// 由小至大打印
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
