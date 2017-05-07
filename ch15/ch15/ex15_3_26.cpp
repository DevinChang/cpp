#include "ex15_3_26.h"

void Quote::debug() const{
	std::cout << "data nembers of this class: \n" << "bookNo = " << bookNo << std::endl << "price = " << price << std::endl;
}

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}