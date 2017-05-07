#include "ex15_5.h"

double Bulk_quote::net_price(std::size_t cnt) const{
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

void Bulk_quote::debug() const{
	Quote::debug();
	std::cout << "min_qty = " << quantity << std::endl << "discount = " << discount << std::endl;
}

