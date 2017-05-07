#include <iostream>
#include <string>

using namespace std;

class Sales_data
{
    friend std::istream& operator>>(std::istream&, Sales_data&);		//��Ԫ����
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);//��Ԫ����
    friend bool operator<(const Sales_data&, const Sales_data&);		//��Ԫ����
    friend bool operator==(const Sales_data&, const Sales_data&);		//��Ԫ����
public:		//���캯����3����ʽ
    Sales_data() = default;
    Sales_data(const std::string &book) : bookNo(book) {}
    Sales_data(std::istream &is) { is >> *this; }
public:
    Sales_data& operator+=(const Sales_data&);
    std::string isbn() const { return bookNo; }
private:
    std::string bookNo;     	//�鼮��ţ���ʽ��ʼ��Ϊ�մ�
    unsigned units_sold = 0; 	//����������ʽ��ʼ��Ϊ0
    double sellingprice = 0.0;	//ԭʼ�۸���ʽ��ʼ��Ϊ0.0
	double saleprice = 0.0;		//ʵ�ۼ۸���ʽ��ʼ��Ϊ0.0
	double discount = 0.0;		//�ۿۣ���ʽ��ʼ��Ϊ0.0
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
    return !(lhs == rhs); 	//���������==����!=�Ķ���
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
    Sales_data ret(lhs);  	//��lhs�����ݿ�������ʱ����ret�У�����������������
    ret += rhs;           	//��rhs�����ݼ�������
    return ret;           	//����ret
}

std::istream& operator>>(std::istream& in, Sales_data& s)
{
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
    if (in && s.sellingprice != 0)
    {
        s.discount = s.saleprice / s.sellingprice;
    }
    else
    {
        s = Sales_data();  	//��������������������
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Sales_data& s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.sellingprice << " " << s.saleprice << " " << s.discount;
    return out;
}

int main()
{
    Sales_data book;
    std::cout << "���������ۼ�¼��"<< std::endl;
    while (std::cin >> book)
    {
        std::cout << " ISBN���۳�������ԭʼ�۸�ԭʼ�۸�ʵ�ۼ۸��ۿ�Ϊ" << book << std::endl;
    }

    Sales_data trans1, trans2;
    std::cout << "����������ISBN��ͬ�����ۼ�¼��"<< std::endl;
    std::cin.clear(); // ����������Ĵ���״̬��־λ���Ա����������롣
    std::cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2))
    {
        std::cout << "������Ϣ��ISBN���۳�������ԭʼ�۸�ʵ�ۼ۸��ۿ�Ϊ " << trans1 + trans2 << std::endl;
    }
    else
    {
        std::cout << "�������ۼ�¼��ISBN��ͬ" << std::endl;
    }

    Sales_data total, trans;
    std::cout << "�����뼸��ISBN��ͬ�����ۼ�¼��"<< std::endl;
    std::cin.clear(); // ����������Ĵ���״̬��־λ���Ա����������롣
    if (std::cin >> total)
    {
        while (std::cin >> trans)
        {
            if (compareIsbn(total, trans)) // ISBN ��ͬ
            {
                total = total + trans;
            }
            else // ISBN ��ͬ
            {
                std::cout << "��ǰ�鼮ISBN��ͬ" << std::endl;
                break;
            }
        }
        std::cout << "��Ч������Ϣ��ISBN���۳�������ԭʼ�۸�ʵ�ۼ۸��ۿ�Ϊ" << total << std::endl;
    }
    else
    {
        std::cout << "û������" << std::endl;
        return -1;
    }

    int num = 1;    //��¼��ǰ�鼮�����ۼ�¼����
    std::cout << "�������������ۼ�¼��"<< std::endl;
    std::cin.clear();  // ����������Ĵ���״̬��־λ���Ա����������롣
    if (std::cin >> trans1)
    {
        while (std::cin >> trans2)
        {
            if (compareIsbn(trans1, trans2)) // ISBN ��ͬ
            {
                num++;
            }
            else // ISBN ��ͬ
            {
                std::cout << trans1.isbn() << "����" << num << "�����ۼ�¼" << std::endl;
                trans1 = trans2;
                num = 1;
            }
        }
        std::cout << trans1.isbn() << "����" << num << "�����ۼ�¼" << std::endl;
    }
    else
    {
        std::cout << "û������" << std::endl;
        return -1;
    }

    return 0;
}
