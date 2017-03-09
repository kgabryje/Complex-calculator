#include <map>
#include "ParserProduction.h"

std::map<std::string, std::string> Production::formulas;

Production::~Production() {}

std::map<std::string, std::string> Production::getFormMap() //returns formulas map
{
	return Production::formulas;
}

std::string Production::getFromFormMap(std::string key) //returns a formula
{
	return Production::formulas.at(key);
}

void Production::putInFormMap(std::string key, std::string formula) //new formula and variable
{
	Production::formulas[key] = formula;
}

const char* ParseError::what() const throw()
{
	return "A parsing error occured";
}
