#include "ex12_33.h"
#include "ex12_19.h"

using chapter10::QueryResult3;
using chapter10::TextQuery3;

TextQuery3::TextQuery3(std::ifstream &is)  {
	std::string text;
	while (std::getline(is, text)) {
		file.push_back(text);
		int n = file.size() - 1;
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

QueryResult3 TextQuery3::query(const std::string &sought) const {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult3(sought, nodata, file);
	else
		return QueryResult3(sought, loc->second, file);
}

std::ostream &chapter10::print(std::ostream &os, QueryResult3 &qr) {
	os << qr.word << " occurs " << qr.lines->size() << ((qr.lines->size() > 1) ? " times." : " time.") << std::endl;
	for (auto it = qr.begin(); it != qr.end(); ++it) {
		StrBolbPtr p(*qr.get_file(), *it);
		os << "\t(line " << *it + 1 << ") " << p.deref() << std::endl;
	}
	return os;
}

std::ostream & chapter10::operator<<(std::ostream &os, QueryResult3 &qr){
	os << qr.word << " occurs " << qr.lines->size() << ((qr.lines->size() > 1) ? " times." : " time.") << std::endl;
	for (auto it = qr.begin(); it != qr.end(); ++it) {
		StrBolbPtr p(*qr.get_file(), *it);
		os << "\t(line " << *it + 1 << ") " << p.deref() << std::endl;
	}
	return os;
}
