#include "ParserProduction.h"
#include "Parser.h"
#include "functions.h"

Unary::Unary(std::istream& in) //Unary = +- Factor
{
	sign = 1;
	
	while (in.peek() == '-' || in.peek() == '+') 
	{ 
		if (getChar(in) == '-')
		{ 
			sign = -sign;
		}
	}
	value = new Factor(in);
}

Unary::~Unary()
{
	delete value;
}

Complex Unary::getValue() 
{
	return sign * value->getValue();
}
