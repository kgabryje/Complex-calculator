CPPFLAGS = -O2 --std=c++11 -Wall

all: calc

main.o: main.cpp
	g++ -c $(CPPFLAGS) main.cpp

Complex.o: Complex.cpp
	g++ -c $(CPPFLAGS) Complex.cpp -o Complex.o

FactorParser.o: FactorParser.cpp
	g++ -c $(CPPFLAGS) FactorParser.cpp -o FactorParser.o

functions.o: functions.cpp
	g++ -c $(CPPFLAGS) functions.cpp -o functions.o

ParserProduction.o: ParserProduction.cpp
	g++ -c $(CPPFLAGS) ParserProduction.cpp -o ParserProduction.o

TermParser.o: TermParser.cpp
	g++ -c $(CPPFLAGS) TermParser.cpp -o TermParser.o

ExprParser.o: ExprParser.cpp
	g++ -c $(CPPFLAGS) ExprParser.cpp -o ExprParser.o

NumberParser.o: NumberParser.cpp
	g++ -c $(CPPFLAGS) NumberParser.cpp -o NumberParser.o

UnaryParser.o: UnaryParser.cpp
	g++ -c $(CPPFLAGS) UnaryParser.cpp -o UnaryParser.o


calc: Complex.o FactorParser.o functions.o ParserProduction.o TermParser.o ExprParser.o NumberParser.o UnaryParser.o main.o
	g++ -o calc Complex.o FactorParser.o functions.o ParserProduction.o TermParser.o ExprParser.o NumberParser.o UnaryParser.o main.o

clean:
	rm -f *.o
	rm -f calc
