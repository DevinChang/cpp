#include <cassert>
#include <utility>
using std::pair;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <numeric>
using std::accumulate;

#include <algorithm>
using std::equal_range;

#include <exception>
#include <stdexcept>
using std::domain_error;

#include <iostream>
using std::ostream; using std::istream;
using std::cout; using std::endl;

#include <fstream>
using std::ifstream;

#include "Sales_data.h"

bool lt(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

// need to leave this for as a traditional for loop because we
// use the iterator to compute an index
// matches has three members: an index of a store and iterators into that store's vector
typedef pair<vector<Sales_data>::size_type,
              pair<vector<Sales_data>::const_iterator,
              vector<Sales_data>::const_iterator>> matches;

// files holds the transactions for every store
// findBook returns a vector with an entry for each store that sold the given book
vector<matches>
findBook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret;  // initially empty
	// for each store find the range of matching books, if any
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		// find the range of Sales_data that have the same ISBN
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)  // this store had sales
		{
			// remember the index of this store and the matching range
			ret.push_back(make_pair(it - files.cbegin(), found));
		}
	}
	return ret; // empty if no matches found
}

vector<Sales_data> build_store(const string &s)
{
	Sales_data item;
	vector<Sales_data> ret;
	ifstream is(s);
	while (read(is, item))
	{
		ret.push_back(item);
	}
	sort (ret.begin(), ret.end(), lt);  // need sort for equal_range to work
	return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files)
{
	string s;   // book to look for
	while (in >> s)
	{
		auto trans = findBook(files, s);  // stores that sold this book
		if (trans.empty())
		{
			cout << s << " not found in any stores" << endl;
			continue;  // get the next book to look for
		}
		for (const auto &store : trans)   // for every store with a sale
		{
			// get<n> returns the specified member from the tuple in store
			os << "store " << store.first << " sales: "
			   << accumulate(store.second.first, store.second.second, Sales_data(s))
			   << endl;
		}
	}
}

int main(int argc, char **argv)
{
	assert(argc > 1);
	// each element in files holds the transactions for a particular store
	vector<vector<Sales_data>> files;
	for (int cnt = 1; cnt != argc; ++cnt)
	{
		files.push_back(build_store(argv[cnt]));
	}

	ifstream in("findbook.in");  // ISBNs to search for
	reportResults(in, cout, files);
}
