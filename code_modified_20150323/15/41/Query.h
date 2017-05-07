#ifndef QUERY_H
#define QUERY_H

#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

// abstract class acts as a base class for concrete query types; all members are private
class Query_base
{
    friend class Query;
protected:
    using line_no = TextQuery::line_no; // used in the eval functions
    virtual ~Query_base() = default;
private:
    // eval returns the QueryResult that matches this Query
    virtual QueryResult eval(const TextQuery&) const = 0;
    // rep is a string representation of the query
	virtual std::string rep() const = 0;
};

// interface class to manage the Query_base inheritance hierarchy
class Query
{
    // these operators need access to the shared_ptr constructor
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&);  // builds a new WordQuery
    // copy constructor
    Query(const Query& query) : q(query.q), uc(query.uc) { ++*uc;}
    Query& operator=(const Query& query); // copy assignment operator

    // interface functions: call the corresponding Query_base operations
    QueryResult eval(const TextQuery &t) const
                            { return q->eval(t); }
    std::string rep() const { return q->rep(); }
    ~Query();
private:
    Query(Query_base* query): q(query), uc(new int(1)) { }
    Query_base* q;
    int* uc;
};

inline std::ostream &operator<<(std::ostream &os, const Query &query)
{
	// Query::rep makes a virtual call through its Query_base pointer to rep()
	return os << query.rep();
}

class WordQuery: public Query_base
{
    friend class Query; // Query uses the WordQuery constructor
    WordQuery(const std::string &s): query_word(s) { }

    // concrete class: WordQuery defines all inherited pure virtual functions
    QueryResult eval(const TextQuery &t) const
                     { return t.query(query_word); }
	std::string rep() const { return query_word; }
    std::string query_word;   // word for which to search
};

inline Query::Query(const std::string &s) : q(new WordQuery(s)), uc(new int(1)) { }

inline Query::~Query()
{
    if (--*uc == 0)
    {
        delete q;
        delete uc;
    }
}

inline Query& Query::operator=(const Query& query)
{
    ++*query.uc;
    if (--*uc == 0)
    {
        delete q;
        delete uc;
    }
    q = query.q;
    uc = query.uc;
    return *this;
}

class NotQuery: public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q) { }

    // concrete class: NotQuery defines all inherited pure virtual functions
	std::string rep() const {return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery&) const;
    Query query;
};

class BinaryQuery: public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) { }

    // abstract class: BinaryQuery doesn't define eval
	std::string rep() const { return "(" + lhs.rep() + " "
	                                     + opSym + " "
		                                 + rhs.rep() + ")"; }

    Query lhs, rhs;    // right- and left-hand operands
    std::string opSym; // name of the operator
};

class AndQuery: public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") { }
    // concrete class: AndQuery inherits rep and defines the remaining pure virtual
    QueryResult eval(const TextQuery&) const;
};

class OrQuery: public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") { }
    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return new OrQuery(lhs, rhs);
}

inline Query operator~(const Query &operand)
{
    return new NotQuery(operand);
}

std::ifstream& open_file(std::ifstream&, const std::string&);
TextQuery get_file(int, char**);
bool get_word(std::string&);
bool get_words(std::string&, std::string&);
std::ostream &print(std::ostream&, const QueryResult&);

#endif
