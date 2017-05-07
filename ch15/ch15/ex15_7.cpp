#include "ex15_7.h"

double Limit_quote::net_price(std::size_t cnt) const{
	if (cnt <= quantity)
		return cnt * (1 - discount) * price;
	else
		return (quantity * (1 - discount) * price + (cnt - quantity) * price);
}

void Limit_quote::debug() const{
	Quote::debug();
	std::cout << "limit = " << quantity
		<< std::endl << "discount = " << discount << std::endl;
}
