#include "ex12_19.h"



std::shared_ptr<std::vector<std::string>> StrBolbPtr::check(std::size_t i, const std::string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBolbPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

StrBolbPtr & StrBolbPtr::operator++(){
	check(curr, "increment past end of StrBolbPtr");
	++curr;
	return *this;
}

StrBolbPtr StrBolbPtr::operator++(int){
	StrBolbPtr ret = *this;
	++*this;
	return ret;
}

StrBolbPtr & StrBolbPtr::operator--(){
	--curr;
	check(curr, "decrement past begin of StrBolbPtr");
	return *this;
}

StrBolbPtr StrBolbPtr::operator--(int){
	StrBolbPtr ret = *this;
	--*this;
	return ret;
}

StrBolbPtr StrBolbPtr::operator+(int n){
	StrBolbPtr ret = *this;
	ret.curr += n;
	return ret;
}

StrBolbPtr StrBolbPtr::operator-(int n){
	StrBolbPtr ret = *this;
	ret.curr -= n;
	return ret;
}

std::string & StrBolbPtr::operator*() const{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

std::string * StrBolbPtr::operator->() const{
	return &this->operator*();
}

std::string &StrBolbPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBolbPtr &StrBolbPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBolbPtr StrBolb::begin() {
	return StrBolbPtr(*this);
}

StrBolbPtr StrBolb::end() {
	auto ret = StrBolbPtr(*this, data->size());
	return ret;
}

bool operator==(const StrBolbPtr &lhs, const StrBolbPtr &rhs){
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		return (!r || lhs.curr == rhs.curr);
	else
		return false;
}

bool operator!= (const StrBolbPtr &lhs, const StrBolbPtr &rhs){

	return !(lhs == rhs);
}

bool operator< (const StrBolbPtr & lhs, const StrBolbPtr & rhs){
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r) {
		if (!r)
			return false;
		return lhs.curr < rhs.curr;
	}
	else
		return false;
}

bool operator<=(const StrBolbPtr & lhs, const StrBolbPtr & rhs){
	return !(lhs > rhs);
}

bool operator>(const StrBolbPtr & lhs, const StrBolbPtr & rhs){
	/*auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r) {
		if (!r)
			return false;
		return lhs.curr > rhs.curr;
	}
	else
		return false;*/
	return rhs < lhs;
}

bool operator>=(const StrBolbPtr & lhs, const StrBolbPtr & rhs){
	return !(lhs < rhs);
}
