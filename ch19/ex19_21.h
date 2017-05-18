#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <new>




class Token {
public:
	Token() : tok(INT), ival(0){}
	Token(const Token &t) : tok(t.tok) { copyUnion(t); }
	Token(Token &&other) : tok(INT), ival(0) { 
		tok = other.tok;
		ival = other.ival;
		other.tok = INT;
		other.ival = 0;
	}
	Token &operator= (const Token &);
	Token &operator= (Token &&);
	~Token() {if (tok == STR) sval.std::string::~string();}
	Token &operator= (const std::string &);
	Token &operator= (char);
	Token &operator= (double);
	Token &operator= (int);
private:
	enum {INT, CHAR, DBL, STR} tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
	};
	void copyUnion(const Token&);
};