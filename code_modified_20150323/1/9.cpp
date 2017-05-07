#include <iostream>

int main()
{
    int sum = 0;
    int i = 50;
    while (i <= 100)
    {
        sum += i;
        i++;
    }
    std::cout << "50到100之间的整数之和为" << sum << std::endl;
    return 0;
}
