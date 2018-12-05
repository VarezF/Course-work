#pragma once
#include <iostream>

class Complex {
public:
	Complex(double realPart = 0.0, double iPart = 0.0);
	double getRealPart();
	double getiPart();
	void setRealPart(double realPart);
	void setiPart(double iPart);
	Complex add(Complex RHS);
	void print();
	void read();

private:
	double mRealPart;
	double mIPart;
};

Complex operator+ (const Complex &lhs, const Complex &rhs);

std::istream & operator>> (std::istream &lhs, Complex &rhs);

std::ostream & operator<< (std::ostream &lhs, const Complex &rhs);