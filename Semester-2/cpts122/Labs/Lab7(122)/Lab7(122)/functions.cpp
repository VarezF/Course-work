#include "Header.h"

Complex::Complex(double realPart, double iPart)
{
	mRealPart = realPart;
	mIPart = iPart;
}

double Complex::getRealPart()
{
	return mRealPart;
}

double Complex::getiPart()
{
	return mIPart;
}

void Complex::setRealPart(double realPart)
{
	mRealPart = realPart;
}

void Complex::setiPart(double iPart)
{
	mIPart = iPart;
}

Complex Complex::add(Complex RHS)
{
	Complex result;
	result.mRealPart = mRealPart + RHS.mRealPart;
	result.mIPart = mIPart + RHS.mIPart;

	return result;
}

void Complex::print()
{
	std::cout << mRealPart << "+" << mIPart << "i" << std::endl;
}

void Complex::read()
{
	char temp[] = { '\0' };
	std::cin >> temp;
}

Complex operator +(Complex LHS, Complex RHS)
{
	Complex result;
	result.setRealPart(LHS.getRealPart + RHS.getRealPart);
	result.setiPart(LHS.getiPart + LHS.getiPart);

	return result;
}

Complex add(Complex num1, Complex num2)
{
	Complex result;
	result.setRealPart(num1.getRealPart + num2.getRealPart);
	result.setiPart(num1.getiPart + num2.getiPart);
}

Complex operator - (Complex num1, Complex num2)
{
	Complex result;
	result.setRealPart(num1.getRealPart - num2.getRealPart);
	result.setiPart(num1.getiPart - result.getiPart);

	return result;
}

std::istream &operator >>(std::istream&LHS, Complex RHS)
{
	double temp = 0.0;
	LHS >> temp;
	RHS.setRealPart(temp);
	char sign = '\0';
	LHS >> sign;
	LHS >> temp;
	RHS.setiPart(temp);
	LHS >> sign;

	return LHS;
}

std::ostream & operator<< (std::ostream &LHS, const Complex &RHS)
{
	LHS << RHS.getRealPart << "+" << RHS.getiPart << "i" << std::endl;

	return LHS;
}