#pragma once
#include <iostream>
#include <string>


class Quote {
	friend double print_total(std::ostream &os, const Quote &item, std::size_t n);
public:
	Quote() = default;
	Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) { std::cout << "call Quote constructor! " << std::endl; }
	Quote(Quote &&q) : bookNo(std::move(q.bookNo)), price(std::move(q.price)) { std::cout << "call Quote move constructor! " << std::endl; }
	Quote &operator= (const Quote &q) { 
		std::cout << "call Quote &operator= (const Quote &)" << std::endl;
		bookNo = q.bookNo; price = q.price; return *this; 
	}
	Quote &operator= (Quote &&q) { 
		if (this != &q) {
			bookNo = std::move(q.bookNo); 
			price = std::move(q.price);
		}
		std::cout << "call Quote &operator= (Quote &&)" << std::endl;
		return *this;
	}
	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price){}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual void debug() const;
	virtual Quote *clone() const & { return new Quote(*this); }
	virtual Quote *clone() && { return new Quote(std::move(*this)); }
	virtual ~Quote() { std::cout << "call ~Quote()" << std::endl; };
private:
	std::string bookNo;
protected:
	double price;
};