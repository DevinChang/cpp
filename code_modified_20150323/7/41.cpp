#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
public:		//委托构造函数
    Sales_data(const string &book, unsigned num, double sellp, double salep)
                : bookNo(book), units_sold(num), sellingprice(sellp), saleprice(salep)
    {
        if(sellingprice)
        {
            discount = saleprice / sellingprice;
        }
        cout << "该构造函数接受书号、销售量、原价、实际售价四个信息" << endl;
    }
    Sales_data() : Sales_data("", 0, 0, 0) { cout << "该构造函数无需接受任何信息" << endl; }
    Sales_data(const string &book) : Sales_data(book, 0, 0, 0) { cout << "该构造函数接受书号信息" << endl; }
    Sales_data(std::istream &is) : Sales_data()
    {
        read(is, *this);
        cout << "该构造函数接受用户输入的信息" << endl;
    }

private:
    std::string bookNo;     	//书籍编号，隐式初始化为空串
    unsigned units_sold = 0; 	//销售量，显式初始化为0
    double sellingprice = 0.0;	//原始价格，显式初始化为0.0
	double saleprice = 0.0;		//实售价格，显式初始化为0.0
	double discount = 0.0;		//折扣，显式初始化为0.0
};

std::istream &read(std::istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.bookNo << " " << item.units_sold << " " << item.sellingprice << " " <<item.saleprice << " " << item.discount;
    return os;
}

int main()
{
    Sales_data fist("978-7-121-15535-2", 85, 128, 109);
    Sales_data second;
    Sales_data third("978-7-121-15535-2");
    Sales_data last(cin);
    return 0;
}
