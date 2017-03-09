#ifndef COMPLEX_H
#define COMPLEX_H
#include <cmath>
#include <iostream>

class Complex {
	
	double m_real; //real part
	double m_imaginary; //imaginary part

public:
	
	Complex(double real = 0, double imaginary = 0);

	void SetReal(double real);
	void SetImaginary(double imaginary);

	double GetReal() const;
	double GetImaginary() const;

	Complex& operator=(const Complex & t);

	//overloading operators for Complex numbers
	Complex& operator+=(const Complex & t);
	Complex& operator-=(const Complex & t);
	Complex& operator*=(const Complex & t);
	Complex& operator/=(const Complex & t);

	Complex operator+(const Complex & t) const;
	Complex operator-(const Complex & t) const;
	Complex operator*(const Complex & t) const;
	Complex operator/(const Complex & t) const;

	// overloading '<<'
	friend std::ostream& operator<<(std::ostream & os, const Complex & t);
};

Complex operator*(double t, const Complex & s);


#endif