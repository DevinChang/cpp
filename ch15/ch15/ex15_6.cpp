
#include "ex15_3_26.h"
#include "ex15_5.h"
#include "ex15_7.h"




int main3() {
	Quote basic("textbook", 2.1);
	Bulk_quote bulk("textbook", 2.1, 5, 0.5);
	Limit_quote limit("textbook", 2.1, 5, 0.5);
	print_total(std::cout, basic, 6);
	print_total(std::cout, bulk, 6);
	print_total(std::cout, limit, 6);
	system("pause");
	return 0;
}