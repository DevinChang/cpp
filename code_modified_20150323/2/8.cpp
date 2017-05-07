#include <iostream>

int main()
{
    std::cout<<"2\x4d\012";		//输出2M，然后换行
    std::cout<<"2\tM\n";		//输出2、制表符、M，然后换行
    return 0;
}
