#include "Complex.h"
#include <cmath>

Complex::Complex(double real, double imaginary) : m_real(real), m_imaginary(imaginary)
{
}

void Complex::SetReal(double real)
{
	m_real = real;
}

void Complex::SetImaginary(double imaginary)
{
	m_imaginary = imaginary;
}


double Complex::GetReal() const
{
	return m_real;
}

double Complex::GetImaginary() const
{
	return m_imaginary;
}

// overloading '=' for Complex numbers
Complex& Complex::operator=(const Complex & t)
{
	SetReal(t.GetReal());
	SetImaginary(t.GetImaginary());

	return *this;
}

// overloading arithmetic operators for Complex numbers
Complex& Complex::operator+=(const Complex & t)
{
	m_real += t.GetReal();
	m_imaginary += t.GetImaginary();

	return *this;
}

Complex& Complex::operator-=(const Complex & t)
{
	m_real -= t.GetReal();
	m_imaginary -= t.GetImaginary();

	return *this;
}

Complex& Complex::operator*=(const Complex & t)
{
	double a = m_real;
	double b = m_imaginary;
	double c = t.GetReal();
	double d = t.GetImaginary();

	m_real = a*c - b*d;
	m_imaginary = a*d + b*c;

	return *this;
}

Complex& Complex::operator/=(const Complex & t)
{
	double a = m_real;
	double b = m_imaginary;
	double c = t.GetReal();
	double d = t.GetImaginary();

	m_real = (a*c + b*d) / (c*c + d*d);
	m_imaginary = (b*c - a*d) / (c*c + d*d);

	return *this;
}

Complex Complex::operator+(const Complex & t) const
{
	Complex output = *this;
	output += t;

	return output;
}

Complex Complex::operator-(const Complex & t) const
{
	Complex output = *this;
	output -= t;

	return output;
}

Complex Complex::operator*(const Complex & t) const
{
	Complex output = *this;
	output *= t;

	return output;
}

Complex Complex::operator/(const Complex & t) const
{
	Complex output = *this;
	output /= t;

	return output;
}

Complex operator*(double t, const Complex & s) //used in UnaryParser
{
	return Complex(s.GetReal() * t, s.GetImaginary() * t);
}

// overloading <<
std::ostream& operator<<(std::ostream& os, const Complex & t)
{
	os << t.GetReal() << std::showpos << t.GetImaginary() << std::noshowpos << "i";
	return os;
}