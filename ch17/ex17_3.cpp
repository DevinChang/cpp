#include "ex17_3.h"


TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>) {
	std::string text;
	while (std::getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);

		}
	}
}

QueryResult TextQuery::query(const std::string &sought) const {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

TextQuery::result_tuple TextQuery::query_tuple(const std::string &sought) const {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return result_tuple(sought, nodata, file);
	else
		return result_tuple(sought, loc->second, file);
}

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending) {
	return (ctr > 1) ? word + ending : word;
}

std::ostream & operator<<(std::ostream & os, TextQuery::result_tuple &qr){
	os << std::get<0>(qr) << " occurs " << std::get<1>(qr)->size() << ((std::get<1>(qr)->size() > 1) ? " times" : " time") << std::endl;
	for (auto num : *std::get<1>(qr))
		os << "\t(line" << num + 1 << ") " << *(std::get<2>(qr)->begin() + num) << std::endl;
	return os;
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << ((qr.lines->size() > 1) ? " times" : " time") << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line" << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	return os;
}

