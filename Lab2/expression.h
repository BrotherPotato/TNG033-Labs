/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

constexpr double Epsilon = 1.0e-5;

class Expression {
public:
    // Destructor
    virtual ~Expression() {
        --count_expressions;
    }

    // ADD OTHER MEMBER FUNCTIONS

    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

    bool isRoot(double x) const;
	
    // virtual = 0 is a pute virutal function. 
    // pure virtual functions are abstract functions, they are not defined in the base class
	virtual double operator()(double x) const = 0; // we define a base case for the function call operator
	virtual Expression* clone() const = 0;
	
	// move display to protected?
    
    friend std::ostream& operator<<(std::ostream& os, const Expression& aExpression);

protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    }

    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    // Total number of existing expressions -- to help to detect bugs in the code
    static std::size_t count_expressions;


	virtual void display(std::ostream& os = std::cout) const = 0; 
};
