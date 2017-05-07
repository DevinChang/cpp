#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
    cout << "请输入交易记录（ISBN、销售量、原价、实际售价）：" << endl;
    Sales_data total; //保存下一条交易记录的变量
    // 读入第一条交易记录，并确保有数据可以处理
    if (read(cin, total))
    {
        Sales_data trans; //保存和的变量
        //读入并处理剩余交易记录
        while (read(cin, trans))
        {
            //如果我们仍在处理相同的书
            if (total.isbn() == trans.isbn())
            {
                total = add(total, trans); //更新总销售额
            }
            else
            {
                //打印前一本书的结果
                print(cout, total);
                cout << endl;
                total = trans; //total现在表示下一本书的销售额
            }
        }
        print(cout, total);
        cout << endl; //打印最后一本书的结果
    }
    else
    {
        //没有输入！警告读者
        cerr << "No data?!" << endl;
        return -1; //表示失败
    }
    return 0;
}
