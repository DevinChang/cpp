#pragma once
#include "ex12_33.h"

class query;

class query_base {
	friend class query;
protected:
	typedef TextQuery3::line_no line_no;
	virtual ~query_base() = default;
private:
	virtual QueryResult3 eval(const TextQuery3 &) const = 0;
	virtual std::string rep() const = 0;
};


class query {
	friend query operator~ (const query &);
	friend query operator& (const query &, const query &);
	friend query operator| (const query &, const query &);
	friend std::ostream &operator<< (std::ostream &os, const query &);
public:
	query(const std::string &);
	query(const query &q) : q(q.q), use(q.use) { ++*use; }
	query &operator= (const query&rhs);
	~query();
	QueryResult3 eval(const TextQuery3 &t) const { return q->eval(t); }
	std::string rep() const { return q->rep(); }
private:
	query(query_base *query) : q(query), use(new size_t(1)){}
	query_base *q;
	size_t *use;
};


class wordquery : public query_base {
	friend query;
	wordquery(const std::string &s) : query_word(s){}
	QueryResult3 eval(const TextQuery3 &t) const { return t.query(query_word); }
	std::string rep() const { return query_word; }
	std::string query_word;
};


class notquery : public query_base {
	friend query operator~ (const query &);
	notquery(const query &q) : qry(q){}
	QueryResult3 eval(const TextQuery3 &) const;
	std::string rep() const { return "~(" + qry.rep() + ")"; }
	query qry;
};


class binaryquery : public query_base {
protected:
	binaryquery(const query &l, const query &r, std::string s) : lhs(l), rhs(r), opsym(s){}
	std::string rep() const { return "(" + lhs.rep() + " " + opsym + " " + rhs.rep() + ")"; }
	query lhs, rhs;
	std::string opsym;
};

class orquery : public binaryquery {
	friend query operator| (const query &, const query &);
	orquery(const query&lhs, const query &rhs) : binaryquery(lhs, rhs, "|") {}
	QueryResult3 eval(const TextQuery3 &) const;
};

class andquery : public binaryquery {
	friend query operator& (const query &, const query &);
	andquery(const query &lhs, const query &rhs) : binaryquery(lhs, rhs, "&") {}
	QueryResult3 eval(const TextQuery3 &) const;
};