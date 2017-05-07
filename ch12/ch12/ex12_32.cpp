#include "ex12_32.h"
#include "ex12_19.h"



TextQuery2::TextQuery2(std::ifstream &is){
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


QueryResult2 TextQuery2::query(const std::string &sought) const {
	static std::shared_ptr<std::set<line_no>> no_data(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult2(sought, no_data, file);
	else
		return QueryResult2(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult2 &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << ((qr.lines->size() > 1) ? " times." : " time.") << std::endl;
	for (auto num : *qr.lines) {
		StrBolbPtr p(qr.file, num);
		os << "\t(line " << num + 1 << ") " << p.deref() << std::endl;
	}
	return os;
}