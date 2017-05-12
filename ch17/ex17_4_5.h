#include "ex7_2_11_21.h"
#include <tuple>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>


typedef std::tuple<std::vector<Sales_data>::size_type,
	std::vector<Sales_data>::const_iterator,
	std::vector<Sales_data>::const_iterator> matches;



typedef std::pair<std::vector<Sales_data>::size_type,
	std::pair<std::vector<Sales_data>::const_iterator,
	std::vector<Sales_data>::const_iterator>> matches_pair;



std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book) {
	std::vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(std::make_tuple(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

//ex17_5
std::vector<matches_pair> find_book_pair(const std::vector<std::vector<Sales_data>> &files, const std::string &book) {
	std::vector<matches_pair> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = std::equal_range(it->cbegin(), it->cend(),book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(std::make_pair(it - files.cbegin(), std::make_pair(found.first, found.second)));
	}
	return ret;
}

void reportResults(std::istream &is, std::ostream &os, const std::vector<std::vector<Sales_data>> &files) {
	std::string s;
	while (is >> s) {
		auto trans = findBook(files, s);
		if (trans.empty()) {
			std::cout << s << " not find in any stores." << std::endl;
			continue;
		}
		for (const auto &store : trans)
			os << "store " << std::get<0>(store) << " sales: "
			<< std::accumulate(std::get<1>(store), std::get<2>(store), Sales_data(s)) << std::endl;
	}
}


