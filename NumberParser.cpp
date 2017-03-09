#include <cstdio>
#include <sstream>
#include "ParserProduction.h"
#include "Parser.h"
#include "Complex.h"

Number::Number(std::istream& in)
{
	std::string str;

	if (!isdigit(in.peek())) //if next char isn't a digit, handles a string
	{
		while (in.peek() != '+' && in.peek() != '-' && in.peek() != '*' && in.peek() != '/' && in.peek() != ')' && in.peek() != EOF)
			str += in.get();
		
		if (str == "i")
			cplx.SetImaginary(1);

		//else if (getVarMap().count(str) != 0)
		//	cplx = getFromVarMap(str);
		else if (getFormMap().count(str) != 0) //handles variables
		{
			std::stringstream sinput(getFromFormMap(str)); //handling formulas
			Expr expr(sinput);
			cplx = expr.getValue();
		}
		else
			throw ParseError();
	}
	
	else
	{
		in >> value;

		if (in.peek() == 'i') //checks if 'i' is imaginary number
		{
			in.get();

			if (in.peek() == '+' || in.peek() == '-' || in.peek() == '*' || in.peek() == '/' || in.peek() == ')' || in.peek() == EOF)
				cplx.SetImaginary(value);
		}
		else
			cplx.SetReal(value);
			
	}
}

Complex Number::getValue() 
{
	return cplx;
}
