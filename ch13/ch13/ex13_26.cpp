#include "ex13_26.h"


StrBolb::StrBolb() : data(std::make_shared<std::vector<std::string>>()) {}

StrBolb::StrBolb(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBolb::check(StrBolb::size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string &StrBolb::front() const {
	check(0, "front on empty StrBolb");
	return data->front();
}

std::string &StrBolb::back() const {
	check(0, "back on empty StrBolb");
	return data->back();
}

std::string &StrBolb::front() {
	check(0, "front on empty StrBolb");
	return data->front();
}

std::string &StrBolb::back() {
	check(0, "back on empty StrBolb");
	return data->back();
}


void StrBolb::pop_back() {
	check(0, "pop_back on empty StrBolb");
	return data->pop_back();
}


//StrBolb::StrBolb(const StrBolb &sb) {
//	
//}
