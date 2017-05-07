#pragma once
#include "ex15_15.h"


class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	//Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc){}
	//ex15_27
	using Disc_quote::Disc_quote;
	Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs) { std::cout << "call Bulk_quote(const Bulk_quote &rhs)" << std::endl; }
	Bulk_quote(Bulk_quote &&rhs) : Disc_quote(std::move(rhs)) { std::cout << "call Bulk_quote(Bulk_quote &&rhs)" << std::endl; }
	Bulk_quote &operator= (const Bulk_quote &rhs) {
		if (this != &rhs)
			Disc_quote::operator=(rhs);
		std::cout << "call Bulk_quote &operator= (const Bulk_quote &rhs)" << std::endl;
		return *this;
	}
	Bulk_quote &operator= (Bulk_quote &&rhs) noexcept{
		if (this != &rhs)
			Disc_quote::operator=(std::move(rhs));
		std::cout << "call Bulk_quote &operator= (Bulk_quote &&rhs)" << std::endl;
		return *this;
	}
	~Bulk_quote() override { std::cout << "call ~Bulk_quote()" << std::endl; }

	double net_price(std::size_t) const override;
	void debug() const override;
	virtual Bulk_quote* clone() const & override { return new Bulk_quote(*this); }
	Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }
};