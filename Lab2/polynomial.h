/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>

#include "expression.h"

class Polynomial : public Expression { //polly är overrated
	// ADD CODE HERE TO IMPLEMENT CLASS Polynomial suck ya dad
	// AAAAAAAAAAAAAAAAAAAAA
	
public:
	
	Polynomial(double real); //conversion constructor to convert a real constant into a polynomial. real g
	Polynomial(const std::vector<double>& coeff); //constructor that takes a vector of coefficients.
	Polynomial(const Polynomial& poly);

	~Polynomial() override = default; //desturctor for the polynomial class
	
	double operator()(double x) const override;

	Polynomial* clone() const override;

	Polynomial& operator=(const Polynomial& rhs) = default;

	Polynomial operator+=(const Polynomial& rhs);

	friend Polynomial operator+(Polynomial lhs, const Polynomial& rhs);

	friend Polynomial operator+(Polynomial& lhs, double rhs);

	
	// const member function, can be called for const instance 
	const double& operator[](int index)const;

	double& operator[](int index);

	
private:
	std::vector<double> coeff;
	// = std::cout
	void display(std::ostream& os) const override;
	
};
