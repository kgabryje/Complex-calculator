#include "ParserProduction.h"
#include "Parser.h"
#include "functions.h"

Term::Term(std::istream& in) //Term = Unary */ Unary
{
	values.push_back(new Unary(in)); 
	
	while (in.peek() == '*' || in.peek() == '/')
	{
		ops.push_back(getChar(in)); 
		values.push_back(new Unary(in)); 
	}
}

Term::~Term() 
{
	for (unsigned int i = 0; i<values.size(); ++i)
		delete values[i];
}

Complex Term::getValue()
{
	Complex cplx = values[0]->getValue();
	for (unsigned int i = 1; i<values.size(); ++i) 
	{ 
		if (ops[i - 1] == '*') 
			cplx *= values[i]->getValue();
		else
			cplx /= values[i]->getValue();
	}
	return cplx;
}

