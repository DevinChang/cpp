#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
    Sales_data total(cin); 							// 保存当前求和结果的变量
    if ( cin )
    { 					// 读入第一笔交易
        Sales_data trans(cin); 						// 保存下一条交易数据的变量
        do
        { 				// 读入剩余的交易
            if (total.isbn() == trans.isbn()) 	// 检查isbn
            {
                total.combine(trans); 			// 更新变量total当前的值
            }
            else
            {
                print(cout, total) << endl; 	// 输出结果
                total = trans; 					// 处理下一本书
            }
        } while( read(cin, trans) );
        print(cout, total) << endl; 			// 输出最后一条交易
    }
    else
    { 									// 没有输入任何信息
        cerr << "No data?!" << endl; 			// 通知用户
    }

    return 0;
}
