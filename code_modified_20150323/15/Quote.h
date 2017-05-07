#include <iostream>
#include <string>
using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book = "", double sales_price = 0.0) : bookNo(book), price(sales_price)
    {
        cout << "Quote constructor is running" << endl;
    }

    string isbn() const
    {
        return bookNo;
    }

    virtual double net_price(size_t n) const   //返回给定数量的书籍的销售总额，派生类改写并使用不同的折扣计算方法
    {
        return n * price;
    }

    virtual void debug()
    {
        cout << "bookNo=" << bookNo << " price=" << price << endl;
    }

    virtual ~Quote()
    {
        cout << "Quote destructor is running" << endl;
    }
    
    friend ostream &operator<<(ostream&, Quote&);
    
private:
    string bookNo;             //书籍的ISBN编号
protected:
    double price = 0.0;               //代表普通状态下不打折的价格
};

ostream & operator<<(ostream &os, Quote &)
{
    os << "\tUsing operator<<(ostream &, Quote &);" << endl;
    return os;
};
