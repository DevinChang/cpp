#include "ex14_6.h"



Sales_data & Sales_data::operator=(const Sales_data &rhs){
	bookNo = rhs.bookNo;
	unite_told = rhs.unite_told;
	revenue = rhs.revenue;
	return *this;
}

Sales_data & Sales_data::operator=(const std::string &ISBN){
	bookNo = ISBN;
	return *this;
}

Sales_data & Sales_data::operator+=(const Sales_data &rhs){
	unite_told += rhs.unite_told;
	revenue += rhs.revenue;
	return *this;
}

Sales_data & Sales_data::operator-=(const Sales_data &rhs){
	unite_told -= rhs.unite_told;
	revenue -= rhs.revenue;
	return *this;
}

Sales_data  &Sales_data::combine(const Sales_data &rhs) {
	unite_told += rhs.unite_told;
	revenue += rhs.revenue;
	return *this;
}

std::istream &read(std::istream &is, Sales_data &item) {
	double price = 0.0;
	is >> item.bookNo >> item.unite_told >> price;
	item.revenue = price *item.unite_told;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.unite_told << " "
		<< item.revenue;
	return os;
}

std::ostream & operator<<(std::ostream &os, const Sales_data &item){
	os << item.isbn() << " " << item.unite_told << " " << item.revenue << " ";
	return os;
}

std::istream & operator >> (std::istream &is, Sales_data &item){
	double price;
	is >> item.bookNo >> item.unite_told >> price;
	if (is)
		item.revenue = item.revenue * price;
	else
		item = Sales_data();
	return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs){
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs){
	Sales_data div = lhs;
	div -= rhs;
	return div;
}



Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
