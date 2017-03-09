#include <sstream>
#include <fstream>
#include <algorithm>
#include "functions.h"
#include "ParserProduction.h"
#include "Parser.h"

char getChar(std::istream& in)
{
	return in.get();
}

std::vector<std::string> splitString(std::string str) //if there's '=', split string into 2 parts
{
	std::vector<std::string> values;
	std::string part;
	std::istringstream f(str);

	while (getline(f, part, '='))
		values.push_back(part);

	return values;
}

int assert(std::string str) //if there's '=' initializes a variable; else calculates an expression
{
	std::stringstream ss(str);

	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == '=')
			return 1;

	return 2;
}

std::string delSpaces(std::string str) //deletes spaces from input string
{
	str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
	return str;
}

void startParsing()
{
	std::string input, lvalue, pvalue;
	std::stringstream sinput(input);
	std::stringstream spvalue(pvalue);
	std::vector<std::string> LPvalues;
	std::ifstream file;

	file.open("complex.txt"); //open a file

	if (!file.is_open()) //check opening a file succeeded
		std::cout << "Can't open a file" << std::endl;

	while (true)
	{
		input.clear();
		lvalue.clear();
		pvalue.clear();
		sinput.clear();
		spvalue.clear();
		LPvalues.clear();

		if (!file.eof() && file.is_open()) //reading from file
			std::getline(file, input);

		else
			std::getline(std::cin, input); //reading from console input

		input = delSpaces(input);
		std::stringstream sinput(input);

		if (input == "q") //quit
			return;

		try
		{
			switch (assert(input))
			{
				case 1: //initializing variable and calculating expression
				{
					LPvalues = splitString(input);
					lvalue = LPvalues[0]; //variable name
					pvalue = LPvalues[1]; //expression
					if (lvalue == "i")
						throw ParseError();

					std::stringstream spvalue(pvalue);

					Expr expr(spvalue);

				//	expr.putInVarMap(lvalue, expr.getValue());
					expr.putInFormMap(lvalue, pvalue);

					break;
				}

				case 2: //calculating expression
				{
					Expr expr(sinput);
					std::cout << expr.getValue() << std::endl;
					break;
				}
			}
		}

		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}