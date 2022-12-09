/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression {
	// ADD CODE HERE TO IMPLEMENT CLASS Logarithm
public:
	Logarithm(); // creates the logarithm log2(x)

    Logarithm(const Expression& E, double c1, double c2, int b); // creates the logarithmic expression c1 + c2*logb(E)

	Logarithm(const Logarithm& L); // copy constructor

	~Logarithm() override;

	double operator()(double x) const override;

	Logarithm* clone() const override;

	Logarithm& operator=(const Logarithm& rhs);

	void set_base(int b);

	//void display(std::ostream& os = std::cout) const override;
private:
	int b;
	double c1, c2;
	Expression* E;
protected:
// 
	void display(std::ostream& os = std::cout) const override;
};
