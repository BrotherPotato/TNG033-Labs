/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include <cmath>
#include <iomanip>

// ADD implementation of the member functions for class Logarithm
Logarithm::Logarithm() 
:  c1{ 0.0 }, c2{ 1.0 }
, b{ 2 }, E{ new Polynomial{{0,1}} } {
	/*
	c1 = 0.0;
	c2 = 1.0;
	b = 2;
	std::vector<double> coeff = { 0,1 }; // 0 + 1*x^1 = x
	E = new Polynomial{coeff};
	*/
}

Logarithm::Logarithm(const Expression& E_arg, double c1_arg, double c2_arg, int b_arg){
	c1 = c1_arg;
	c2 = c2_arg;

	if (b_arg > 1) {
		b = b_arg;
	} else {
		b = 2;
	}
	
	E = E_arg.clone();
}

// copy constructor
Logarithm::Logarithm(const Logarithm& L){
	c1 = L.c1;
	c2 = L.c2;
	b = L.b;
	E = (*L.E).clone(); // dereference the expression and copy
}

Logarithm::~Logarithm(){ // destructor needed because pointer E 
	delete E;
	E = nullptr;
	c1 = 0;
	c2 = 0;
	b = 0;

}
// deep copy
Logarithm& Logarithm::operator=(const Logarithm& rhs) {
	if (this != &rhs) {
		c1 = rhs.c1;
		c2 = rhs.c2;
		b = rhs.b;
		delete E; //nessesary to avoid memory leak
		E = (*rhs.E).clone();
	}
	return *this;
}

double Logarithm::operator()(double x) const{
	double evaluatedE = (*E)(x);
	return c1 + c2 * (log(evaluatedE) / log(b));
}
// use copy constructor to copy a instance of Logarithm
Logarithm* Logarithm::clone() const{
	return new Logarithm(*this);
}

void Logarithm::display(std::ostream& os) const{
	
	std::string s = " + ";
	if(c2 < 0) {
		s = " - ";
	}
	os << std::fixed << std::setprecision(2) << c1 << s << std::abs(c2) << " * Log_" << b << "( " << *E << " )";
}

void Logarithm::set_base(int b_arg){
	if(b_arg > 1){ //assumed
		b = b_arg;
	} 
}