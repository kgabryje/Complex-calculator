#include "ParserProduction.h"
#include "Parser.h"
#include "functions.h"

Expr::Expr(std::istream& in) //Expr = Term +- Term
{
	values.push_back(new Term(in)); 
	while (in.peek() == '+' || in.peek() == '-') 
	{
		ops.push_back(getChar(in));
		values.push_back(new Term(in));
	}
}

Expr::~Expr()
{
	for (unsigned int i = 0; i<values.size(); ++i)
		delete values[i];
}

Complex Expr::getValue()
{
	Complex cplx = values[0]->getValue();

	for (unsigned int i = 1; i<values.size(); ++i)
	{
		if (ops[i - 1] == '+')
			cplx += values[i]->getValue();
		else
			cplx -= values[i]->getValue();
	}
	return cplx;
}
