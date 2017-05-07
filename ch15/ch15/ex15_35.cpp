#include "ex15_35.h"
#include <algorithm>
#include <iterator>



Query operator~(const Query &operand){
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

Query operator&(const Query &lhs, const Query &rhs){
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}





Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}



QueryResult3 NotQuery::eval(const TextQuery3 &text) const{
	auto result = query.eval(text);
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

QueryResult3 AndQuery::eval(const TextQuery3 &text) const{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult3(rep(), ret_lines, *left.get_file());
}

QueryResult3 OrQuery::eval(const TextQuery3 &text) const{
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult3(rep(), ret_lines, *left.get_file());
}

Query::Query(const std::string & s) : q(new WordQuery(s)) { std::cout << "Query(const std::string & s)" << std::endl; }
