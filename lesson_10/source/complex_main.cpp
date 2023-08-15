#include "complex.h"

int main() {

	Complex default_constructed;

	Complex a{0, 1};
	Complex b{2, 3};

	Complex c{a}; // call the copy constructor here: Complex(const Complex&)

	c = a; // call the operator=(const Complex&) here

	c.abs();
	c.angle();

	Complex d = a + b; // call the operator+ here an then call the copy ctor

	return 0;
}