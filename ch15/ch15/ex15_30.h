#pragma once
#include "ex15_5.h"
#include <memory>
#include <set>




class Basket {
public:
	//void add_item(const std::shared_ptr<Quote> &sale);
	void add_item(const Quote &sale);
	void add_item(Quote &&sale);
	double total_receipt(std::ostream &) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	//此处compare为何是static以及为何初始化items用{},而在类外却是{}()都可以？？？
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
};