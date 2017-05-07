#include "ex15_15.h"

Disc_quote & Disc_quote::operator=(const Disc_quote & rhs){
	if (this != &rhs) {
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
	}
	std::cout << "call Disc_quote::operator=(const Disc_quote & rhs)" << std::endl;
	return *this;
}

Disc_quote & Disc_quote::operator=(Disc_quote && rhs) noexcept{
	if (this != &rhs) {
		Quote::operator=(std::move(rhs));
		quantity = (std::move(rhs.quantity));
		discount = (std::move(rhs.discount));
	}
	std::cout << "call Disc_quote::operator=(Disc_quote &&rhs)" << std::endl;
	return *this;
}
