#pragma once
#include "ex12_33.h"

using chapter10::QueryResult3;
using chapter10::TextQuery3;

namespace chapter15{

	class Query;

	class Query_base {
		friend class Query;
	protected:
		using line_no = chapter10::TextQuery3::line_no;
		virtual ~Query_base() = default;
	private:
		virtual chapter10::QueryResult3 eval(const chapter10::TextQuery3&) const = 0;
		virtual std::string rep() const = 0;
	};



	class Query {
		friend Query operator~ (const Query &);
		friend Query operator| (const Query &, const Query &);
		friend Query operator& (const Query &, const Query &);
	public:
		Query(const std::string &s);

		chapter10::QueryResult3 eval(const chapter10::TextQuery3 &t) const { return q->eval(t); }
		std::string rep() const { return q->rep(); }
	private:
		Query(std::shared_ptr<Query_base> query) : q(query) { }
		std::shared_ptr<Query_base> q;
	};

	inline std::ostream &operator<< (std::ostream &os, const Query &query) {
		return os << query.rep();
	}

	class WordQuery : public Query_base {
		friend class Query;
		WordQuery(const std::string &s) : query_word(s) { std::cout << "WordQuery(const std::string &s)" << std::endl; }
		chapter10::QueryResult3 eval(const chapter10::TextQuery3 &t) const { return t.query(query_word); }
		std::string rep() const { return query_word; }
		std::string query_word;
	};

	class NotQuery : public Query_base {
		friend Query operator~ (const Query &);
		NotQuery(const Query &q) : query(q) { std::cout << "NotQuery(const Query &q)" << std::endl; }
		std::string rep() const { return "~(" + query.rep() + ")"; }
		chapter10::QueryResult3 eval(const chapter10::TextQuery3&) const;
		Query query;
	};


	class BinaryQuery : public Query_base {
	protected:
		BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) { std::cout << "BinaryQuery(const Query &l, const Query &r, std::string s)" << std::endl; }
		std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
		Query lhs, rhs;
		std::string opSym;
	};

	class AndQuery : public BinaryQuery {
		friend Query operator& (const Query &, const Query &);
		AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") { std::cout << "AndQuery(const Query &le" << std::endl; }

		QueryResult3 eval(const TextQuery3&) const;
	};

	class OrQuery : public BinaryQuery {
		friend Query operator| (const Query&, const Query &);
		OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") { std::cout << "OrQuery(const Query &left, const Query &right)" << std::endl; }
		QueryResult3 eval(const TextQuery3&) const;
	};

}


