#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <istream>
#include <vector>

char getChar(std::istream& in);
std::vector<std::string> splitString(std::string str);
int assert(std::string str);
std::string delSpaces(std::string str);
void startParsing();

#endif