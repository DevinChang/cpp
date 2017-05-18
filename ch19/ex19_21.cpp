#include "ex19_21.h"

Token & Token::operator=(const Token &t){
	if (tok == STR && t.tok != STR) sval.std::string::~string();
	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}

Token & Token::operator=(Token &&other){
	if (this != &other) {
		tok = other.tok;
		ival = other.ival;
		other.tok = INT;
		other.ival = 0;
	}
	return *this;
}

Token & Token::operator=(const std::string &s){
	if (tok == STR)
		sval = s;
	else
		new (&sval) std::string(s);
	tok = STR;
	return *this;
}

Token & Token::operator=(char c){
	if (tok == STR)
		sval.std::string::~string();
	cval = c;
	tok = CHAR;
	return *this;
}

Token & Token::operator=(double d){
	if (tok == STR)
		sval.std::string::~string();
	dval = d;
	tok = DBL;
	return *this;
}

Token & Token::operator=(int i){
	if (tok == STR)
		sval.std::string::~string();
	ival = i;
	tok = INT;
	return *this;
}

void Token::copyUnion(const Token &t){
	switch (t.tok) {
	case Token::INT: ival = t.ival; break;
	case Token::CHAR: cval = t.cval; break;
	case Token::DBL: dval = t.dval; break;
	case Token::STR: new(&sval) std::string(t.sval); break;
	}
}
