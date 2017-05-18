#include "ex7_23_24_27_32.h"
#include "ex7_2_11_21.h"



int main3() {
	//ex19_12
	Screen::pos Screen::*p = Screen::cus();

	//ex19_13
	auto sp = Sales_data::bN();

	//ex19_16
	Sales_data::AVG avg = &Sales_data::avg_price;
	system("pause");
	return 0;
}