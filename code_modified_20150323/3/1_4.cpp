#include <iostream>
#include <string>
//使用using声明使得以下的名字在程序中可见
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class Sales_data
{
    friend istream& operator>>(istream&, Sales_data&);		//友元函数
    friend ostream& operator<<(ostream&, const Sales_data&);//友元函数
    friend bool operator<(const Sales_data&, const Sales_data&);		//友元函数
    friend bool operator==(const Sales_data&, const Sales_data&);		//友元函数
public:		//构造函数的3种形式
    Sales_data() = default;
    Sales_data(const string &book) : bookNo(book) { }
    Sales_data(istream &is) { is >> *this; }
public:
    Sales_data& operator+=(const Sales_data&);
    string isbn() const { return bookNo; }
private:
    string bookNo;     	//书籍编号，隐式初始化为空串
    unsigned units_sold = 0; 	//销售量，显式初始化为0
    double sellingprice = 0.0;	//原始价格，显式初始化为0.0
	double saleprice = 0.0;		//实售价格，显式初始化为0.0
	double discount = 0.0;		//折扣，显式初始化为0.0

};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

Sales_data operator+(const Sales_data&, const Sales_data&);

inline bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.units_sold == rhs.units_sold &&
           lhs.sellingprice == rhs.sellingprice &&
           lhs.saleprice == rhs.saleprice &&
           lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs); 	//基于运算符==给出!=的定义
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
    if (sellingprice != 0)
    {
        discount = saleprice / sellingprice;
    }
    return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data ret(lhs);  	//把lhs的内容拷贝到临时变量ret中，这种做法便于运算
    ret += rhs;           	//把rhs的内容加入其中
    return ret;           	//返回ret
}

istream& operator>>(istream& in, Sales_data& s)
{
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
    if (in && s.sellingprice != 0)
    {
        s.discount = s.saleprice / s.sellingprice;
    }
    else
    {
        s = Sales_data();  	//输入错误，重置输入的数据
    }
    return in;
}

ostream& operator<<(ostream& out, const Sales_data& s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.sellingprice << " " << s.saleprice << " " << s.discount;
    return out;
}

int main()
{
    Sales_data book;
    cout << "请输入销售记录：" << endl;
    while (cin >> book)
    {
        cout << " ISBN、售出本数、原始价格、原始价格、实售价格、折扣为" << book << endl;
    }

    Sales_data trans1, trans2;
    cout << "请输入两条ISBN相同的销售记录："<< endl;
    cin.clear();
    cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2))
    {
        cout << "汇总信息：ISBN、售出本数、原始价格、实售价格、折扣为 "	<< trans1 + trans2 << endl;
    }
    else
    {
        cout << "两条销售记录的ISBN不同" << endl;
    }

    Sales_data total, trans;
    cout << "请输入几条ISBN相同的销售记录："<< endl;
    cin.clear();
    if (cin >> total)
    {
        while (cin >> trans)
        {
            if (compareIsbn(total, trans)) // ISBN 相同
            {
                total = total + trans;
            }
            else // ISBN 不同
            {
                cout << "当前书籍ISBN不同" << endl;
                break;
            }
        }
        cout << "有效汇总信息：ISBN、售出本数、原始价格、实售价格、折扣为" << total << endl;
    }
    else
    {
        cout << "没有数据" << endl;
        return -1;
    }

    int num = 1;		//记录当前书籍的销售记录总数
    cout << "请输入若干销售记录："<< endl;
    cin.clear();
    if (cin >> trans1)
    {
        while (cin >> trans2)
        {
            if (compareIsbn(trans1, trans2)) // ISBN 相同
            {
                num++;
            }
            else // ISBN 不同
            {
                cout << trans1.isbn() << "共有" << num << "条销售记录" << endl;
                trans1 = trans2;
                num = 1;
            }
        }
        cout << trans1.isbn() << "共有" << num << "条销售记录" << endl;
    }
    else
    {
        cout << "没有数据" << endl;
        return -1;
    }

    return 0;
}
