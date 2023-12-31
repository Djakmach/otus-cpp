#include "complex.h"
#include <iostream>
#include <math.h>

Complex::Complex() {
	std::cout << "Default constructor" << std::endl;
}

Complex::Complex(double real, double img)
	: m_real(real), m_img(img) {
	std::cout << "constructor with arguments" << std::endl;
}

Complex::Complex(const Complex &rhs)
	: m_real{rhs.m_real}, m_img{rhs.m_img} {
}

Complex::~Complex() {
	std::cout << "destructor" << std::endl;
}

Complex &Complex::operator=(const Complex &rhs) {
	m_real = rhs.m_real;
	m_img = rhs.m_img;
	return *this;
}

double Complex::abs() const {
	return sqrt(m_real * m_real + m_img * m_img);
}

double Complex::angle() const {
	return atan2(m_img, m_real);
}

void Complex::set_real(double real) {
	m_real = real;
}

void Complex::set_img(double img) {
	m_img = img;
}

double Complex::real() const { return m_real; }
double Complex::im() const { return m_img; }

Complex operator+(const Complex &lhs, const Complex &rhs) {
	Complex result{
		lhs.real() + rhs.real(),
		lhs.im() + rhs.im()};
	return result;
}