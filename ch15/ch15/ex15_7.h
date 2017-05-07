#pragma once
#include "ex15_15.h"


class Limit_quote : public Disc_quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string &book, double p, std::size_t lm, double disc) : Disc_quote(book, p, lm, disc){}
	double net_price(std::size_t cnt) const override;
	void debug() const override;
};