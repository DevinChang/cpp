#include "ex15_5.h"
#include "ex15_7.h"
#include "ex15_15.h"
#include <vector>
#include <memory>
#include <set>



	




int main6() {
	std::cout << "ex15_28: " << std::endl;
	std::vector<Quote> vec;
	vec.push_back(Quote("0-201-82470-1", 50));
	vec.push_back(Quote("0-202-83480-8", 10));
	vec.push_back(Quote("2-211-88970-2", 60));
	vec.push_back(Bulk_quote("0-201-82741-3", 50, 10, .25));
	vec.push_back(Bulk_quote("1-211-83852-8", 22, 12, .15));
	vec.push_back(Bulk_quote("2-301-52741-3", 60, 20, .35));

	double sum = 0.0;
	for (auto &p : vec) 
		sum += p.net_price(10);
	std::cout << "Total price: " << sum << std::endl;

	std::cout << "ex15_29: " << std::endl;
	std::vector<std::shared_ptr<Quote>> iv;
	iv.push_back(std::make_shared<Quote>("0-201-82470-1", 50));
	iv.push_back(std::make_shared<Quote>("0-202-83480-8", 10));
	iv.push_back(std::make_shared<Quote>("2-211-88970-2", 60));
	iv.push_back(std::make_shared<Bulk_quote>("0-201-82741-3", 50, 10, .25));
	iv.push_back(std::make_shared<Bulk_quote>("1-211-83852-8", 22, 12, .15));
	iv.push_back(std::make_shared<Bulk_quote>("2-301-52741-3", 60, 20, .35));

	sum = 0.0;
	for (auto &p : iv)
		sum += p->net_price(10);
	std::cout << "Total price: " << sum << std::endl;

	
	system("pause");
	return 0;
}