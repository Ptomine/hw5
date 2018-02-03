#include <iostream>
#include <stdexcept>

#include "Complex.h"

Complex::Complex()
	:realPart(0.F),
	imaginaryPart(0.F)
	{} 
Complex::Complex(const float real, const float imaginary)
	:realPart(real),
	imaginaryPart(imaginary)
	{}


Complex::~Complex() {
	realPart = 0.F;
	imaginaryPart = 0.F;
	}

Complex::Complex(const Complex& other) {
	realPart = other.realPart;
	imaginaryPart = other.imaginaryPart;
}
void Complex::setReal(const float real) {
	realPart = real;
}

void Complex::setImaginary(const float imaginary) {
	imaginaryPart = imaginary;
}

float Complex::getReal() const {
	return realPart;
}

float Complex::getImaginary() const {
	return imaginaryPart;
}

Complex Complex::operator+ (const Complex& other) {
	Complex sum;
	sum.realPart = realPart + other.realPart;
	sum.imaginaryPart = imaginaryPart + other.imaginaryPart;
	return sum;
}

Complex Complex::operator- (const Complex& other) {
	Complex difference;
	difference.realPart = realPart - other.realPart;
	difference.imaginaryPart = imaginaryPart - other.imaginaryPart;
	return difference;
}

Complex Complex::operator* (const Complex& other) {
	Complex composition;
	composition.realPart = realPart * other.realPart - imaginaryPart * other.imaginaryPart;
	composition.imaginaryPart = imaginaryPart * other.realPart + realPart * other.imaginaryPart;
	return composition;
}

Complex Complex::operator/ (const Complex& other)  {
	if((other.realPart) == 0 && (other.imaginaryPart == 0)) {
		throw std::invalid_argument("Division by zero.");
	}
	Complex quotient;
	quotient.realPart = (realPart * other.realPart - imaginaryPart * other.imaginaryPart)/(other.realPart * other.realPart 
						+ other.imaginaryPart*other.imaginaryPart);
	quotient.imaginaryPart = (imaginaryPart * other.realPart + realPart * other.imaginaryPart)/(other.realPart * other.realPart 
						+ other.imaginaryPart*other.imaginaryPart);
	return quotient;
}

Complex& Complex::operator= (const Complex& other) {
	realPart = other.realPart;
	imaginaryPart = other.imaginaryPart;
	return *this;
}

std::ostream& operator<< (std::ostream& s, const Complex& number) {
	s << number.realPart << std::showpos << number.imaginaryPart << std::noshowpos << "i";
	return s;
}