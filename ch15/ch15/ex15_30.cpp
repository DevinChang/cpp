#include "ex15_30.h"



void Basket::add_item(const Quote & sale){
	items.insert(std::shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote && sale){
	items.insert(std::shared_ptr<Quote>(sale.clone()));
}

double Basket::total_receipt(std::ostream &os) const{
	double sum = 0.0;
	for (auto iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter))
		sum += print_total(os, **iter, items.count(*iter));
	os << "Total Sale: " << sum << std::endl;
	return sum;
}
