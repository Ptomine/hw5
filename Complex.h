#include <stdexcept>

#pragma once

class Complex {
private:
	float realPart;
	float imaginaryPart;
public:
	// constructors and destructors
	Complex();
	Complex(const float real, const float imaginary);
	~Complex();
	Complex(const Complex& other);
	// methods
	void setReal(const float real);
	void setImaginary(const float imaginary);
	float getReal() const;
	float getImaginary() const;
	// operators
	Complex operator+ (const Complex& other);
	Complex operator- (const Complex& other);
	Complex operator* (const Complex& other);
	Complex operator/ (const Complex& other);
	Complex& operator= (const Complex& other);
	friend std::ostream& operator<< (std::ostream& s, const Complex& number);
};