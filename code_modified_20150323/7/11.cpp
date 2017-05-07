#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
    Sales_data data1;
    Sales_data data2("978-7-121-15535-2");
    Sales_data data3("978-7-121-15535-2", 100, 128, 109);
    Sales_data data4(cin);

    cout << "书籍的销售情况是：" << endl;
    cout << data1 << "\n" << data2 << "\n" << data3 << "\n" << data4 << "\n";
    return 0;
}
