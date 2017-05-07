#include "token.h"

Token &Token::operator=(int i)
{
    if (tok == SDATA)  // 如果当前存储的是Sales_data，释放它
    {
        sval.~Sales_data();
    }

    ival = i;  // 为成员赋值
    tok = INT;  // 更新判别式
    return *this;
}

Token &Token::operator=(char c)
{
    if (tok == SDATA)  // 如果当前存储的是Sales_data，释放它
    {
        sval.~Sales_data();
    }

    cval = c;  // 为成员赋值
    tok = CHAR;  // 更新判别式
    return *this;
}

Token &Token::operator=(double d)
{
    if (tok == SDATA)  // 如果当前存储的是Sales_data，释放它
    {
        sval.~Sales_data();
    }

    dval = d;  // 为成员赋值
    tok = DBL;  // 更新判别式
    return *this;
}

Token &Token::operator=(const Sales_data &sd)
{
    if (tok == SDATA)  // 如果当前存储的是Sales_data，可以直接赋值
    {
        sval = sd;
    }
    else  // 否则需要先构造一个Sales_data
    {
        new (&sval) Sales_data(sd);
    }

    tok = SDATA;  // 更新判别式
    return *this;
}

void Token::copyUnion(const Token &t)
{
    swith (t.tok)
    {
        case Token::INT:
            ival = t.ival;
            break;

        case Token::CHAR:
            cval = t.cval;
            break;

        case Token::DBL:
            dval = t.dval;
            break;

        case Token::SDATA:
            new(&sval) Sales_data(t.sval);
            break;
    }
}

Token &Token::operator=(const Token &t)
{
    // 如果this 此对象的值是string而t的值不是，则我们必须释放原来的string
    if (tok == SDATA && t.tok != SDATA)
    {
        sval.~Sales_data();
    }

    if (tok == SDATA && t.tok == SDATA)
    {
        sval = t.sval;  // 无需构造一个新string
    }
    else
    {
        copyUnion(t);  // 如果t.tok是STR，则需要构造一个string
    }

    tok = t.tok;
    return *this;
}

