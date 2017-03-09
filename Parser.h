#ifndef PARSER_H
#define PARSER_H

#include <istream>
#include <deque>
#include "ParserProduction.h"
#include "Complex.h"

class Number : public Production
{
	double value;
	Complex cplx;

public:
	Number(std::istream& in);
	Complex getValue();
};


class Factor : public Production
{
	Production* prod;

public:
	Factor(std::istream& in);
	~Factor();

	Complex getValue();
};


class Unary : public Production
{
	int sign;
	Factor* value;

public:
	Unary(std::istream& in);
	~Unary();
	
	Complex getValue();
};


class Term : public Production
{
	std::deque<Unary*> values;
	std::deque<char> ops;

public:
	Term(std::istream& in);
	~Term();

	Complex getValue();
};


class Expr : public Production
{
	std::deque<Term*> values;
	std::deque<char> ops;

public:
	Expr(std::istream& in);
	~Expr();
	
	Complex getValue();
};

#endif