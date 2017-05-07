//
//#include "exm_7_2.h"
////
//
////Sales_data  &Sales_data::combine(const Sales_data &rhs) {
////	unite_told += rhs.unite_told;
////	revenue += rhs.revenue;
////	return *this;
////}
//
//std::istream &read(std::istream &is, Sales_data &item){
//	double price = 0.0;
//	is >> item.bookNo >> item.unite_told >> price;
//	item.revenue = price *item.unite_told;
//	return is;
//}
//
//std::ostream &print(std::ostream &os, const Sales_data &item){
//	os << item.isbn() << " " << item.unite_told << " "
//		<< item.revenue;
//	return os;
//}
//
//
//
//Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
//	Sales_data sum = lhs;
//	sum.combine(rhs);
//	return sum;
//}