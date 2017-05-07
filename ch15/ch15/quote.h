#ifndef quote_H
#define quote_H

#include <string>
#include <iostream>

class quote
{
	friend bool operator !=(const quote& lhs, const quote& rhs);
public:
	quote() { std::cout << "default constructing quote\n"; }
	quote(const std::string &b, double p) :
		bookNo(b), price(p) {
		std::cout << "quote : constructor taking 2 parameters\n";
	}

	// copy constructor
	quote(const quote& q) : bookNo(q.bookNo), price(q.price)
	{
		std::cout << "quote: copy constructing\n";
	}

	// move constructor
	quote(quote&& q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
	{
		std::cout << "quote: move constructing\n";
	}

	// copy =
	quote& operator =(const quote& rhs)
	{
		if (*this != rhs)
		{
			bookNo = rhs.bookNo;
			price = rhs.price;
		}
		std::cout << "quote: copy =() \n";

		return *this;
	}

	// move =
	quote& operator =(quote&& rhs)  noexcept
	{
		if (*this != rhs)
		{
			bookNo = std::move(rhs.bookNo);
			price = std::move(rhs.price);
		}
		std::cout << "quote: move =!!!!!!!!! \n";

		return *this;
	}

	std::string     isbn() const { return bookNo; }
	virtual double  net_price(std::size_t n) const { return n * price; }
	virtual void    debug() const;

	virtual ~quote()
	{
		std::cout << "destructing quote\n";
	}

private:
	std::string bookNo;

protected:
	double  price = 10.0;
};

bool inline
operator !=(const quote& lhs, const quote& rhs)
{
	return lhs.bookNo != rhs.bookNo
		&&
		lhs.price != rhs.price;
}

#endif // quote_H
