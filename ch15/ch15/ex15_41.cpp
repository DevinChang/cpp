#include "ex15_41.h"
#include <algorithm>
#include <iterator>

query operator~(const query &rhs){
	return new notquery(rhs);
}

query operator&(const query &lhs, const query &rhs)
{
	return new andquery(lhs, rhs);
}

query operator|(const query &lhs, const query &rhs)
{
	return new orquery(lhs, rhs);
}

std::ostream & operator<<(std::ostream & os, const query &qry){
	return os << qry.rep();
}

query::query(const std::string &s) : q(new wordquery(s)){}

query & query::operator=(const query & rhs){
	++*rhs.use;
	if (--*use == 0) {
		delete q;
		delete use;
	}
	q = rhs.q;
	use = rhs.use;
	return *this;
}

query::~query(){
	if (--*use == 0) {
		delete q; 
		delete use;
	}
}

QueryResult3 notquery::eval(const TextQuery3 &text) const{
	auto result = qry.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;
	}
	return QueryResult3(rep(), ret_lines, *result.get_file());
}

QueryResult3 orquery::eval(const TextQuery3 &text) const{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult3(rep(), ret_lines, *left.get_file());
}

QueryResult3 andquery::eval(const TextQuery3 &text) const{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult3(rep(), ret_lines, *left.get_file());
}
