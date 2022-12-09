/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <cmath>
#include <iomanip>

// ADD implementation of the member functions for class Polynomial

Polynomial::Polynomial(double real_arg) : Expression{} {
	coeff.push_back(real_arg);
}

Polynomial::Polynomial(const std::vector<double>& coeff_arg){
	for (double arg : coeff_arg) {
		this->coeff.push_back(arg);
	}

}

Polynomial::Polynomial(const Polynomial& poly){
	for (double arg : poly.coeff) {
		this->coeff.push_back(arg);
	}
}

double Polynomial::operator()(double x) const {
	double sum = 0;
	for(int i = 0; i < std::ssize(this->coeff) ;i++ ){
		sum += this->coeff[i] * pow(x,i);
	}
	return sum;
}

Polynomial* Polynomial::clone() const{
	return new Polynomial(*this);
}

Polynomial Polynomial::operator+=(const Polynomial& rhs) {
	// Go through rhs, either push back the value or add the value to the existing coeff
	// if rhs is shorter than *this, there is no need to change the remaining values
	
	for (int i = 0; i < std::ssize(rhs.coeff); i++) {
		if (i >= this->coeff.size()) {
			this->coeff.push_back(rhs.coeff[i]);
		} else {
			this->coeff[i] += rhs.coeff[i];
		}
	}
	return *this;
}

Polynomial operator+(Polynomial& lhs, double rhs){
	return lhs + Polynomial(rhs);
}

const double& Polynomial::operator[](int index) const{
	return this->coeff[index];
}

double& Polynomial::operator[](int index) {
	return this->coeff[index];
}

void Polynomial::display(std::ostream& os) const{
	std::string sign;
	
	for (int i = 0; i < std::ssize(this->coeff); i++) {
		if(i == 0){
            os << std::fixed << std::setprecision(2) << coeff[i];
        }
		else {
			if (this->coeff[i] < 0) {
				sign = " - ";
			}
			else {
				sign = " + ";
			}
			os << std::fixed << std::setprecision(2) << sign << abs(coeff[i]) << " * X^" << i;
		}
	}
}

Polynomial operator+(Polynomial lhs, const Polynomial& rhs){ //Mixed-mode arithmetic
	Polynomial temp = lhs += rhs;
	//std::cout << (lhs += rhs).coeff[0];
	return temp;
}
