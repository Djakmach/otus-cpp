#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
	Complex();
	Complex(double real, double im);
	Complex(const Complex &rhs);
	~Complex();

	Complex &operator=(const Complex &rhs);

	double real() const;
	double im() const;

	double abs() const;
	double angle() const;

	void set_real(double real);
	void set_img(double img);

private:
	double m_real;
	double m_img;
};

Complex operator+(const Complex &lhs, const Complex &rhs);

#endif // COMPLEX_H
