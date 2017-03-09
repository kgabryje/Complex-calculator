#ifndef PARSER_PRODUCTION_H
#define PARSER_PRODUCTION_H

#include <exception>
#include <vector>
#include <map>
#include "Complex.h"

class Production;
class Expr;
class Term;
class Unary;
class Number;
class Factor;
class ParseError;


class Production
{
	static std::map<std::string, std::string> formulas;

public:
	virtual ~Production();
	virtual Complex getValue() = 0; 

	std::map<std::string, std::string> getFormMap();
	std::string getFromFormMap(std::string key);
	void putInFormMap(std::string key, std::string formula);
};

//handling exceptions
class ParseError : public std::exception
{
	const char* what() const throw();
};



#endif
