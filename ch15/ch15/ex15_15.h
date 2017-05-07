#pragma once
#include <iostream>
#include <string>
#include "ex15_3_26.h"

class Disc_quote : public Quote{
public:
	Disc_quote() = default;
	Disc_quote(const Disc_quote &rhs) : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) { 
		std::cout << "call Disc_quote(const Disc_quote &rhs)" << std::endl; }
	Disc_quote(Disc_quote &&rhs) : Quote(std::move(rhs)), quantity(std::move(rhs.quantity)), discount(std::move(rhs.discount)){
		std::cout << "call Disc_quote(Disc_quote &&rhs)" << std::endl;}
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc){
		std::cout << "call Disc_quote(const std::string &book, double price, std::size_t qty, double disc)" << std::endl;}
	Disc_quote &operator= (const Disc_quote &rhs);
	Disc_quote &operator= (Disc_quote &&rhs) noexcept;
	~Disc_quote() override { std::cout << "call ~Disc_quote()" << std::endl; }

	double net_price(std::size_t) const = 0;
	//Disc_quote *clone() const & = 0;
	//Disc_quote *clone() && = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};