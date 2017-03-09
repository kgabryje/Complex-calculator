#include <istream>
#include "ParserProduction.h"
#include "Parser.h"

Factor::Factor(std::istream& in) //Factor = (Expr) OR Factor = Number
{
	if (in.peek() == '(') //check to see if a parenthesis was used
	{ 
		in.get();
		prod = new Expr(in); //recursion
	
		if (in.peek() != ')')  //make sure the parenthesis was matched
			throw ParseError();
		else
			in.get();
	}
	else  //if there is no parenthesis
		prod = new Number(in);
}

Factor::~Factor()
{
	delete prod;
}

Complex Factor::getValue()
{
	return prod->getValue();
}
