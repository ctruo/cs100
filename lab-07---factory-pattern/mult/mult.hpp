#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "../base.hpp"
#include <string>

class Mult : public Base {

    private:
        Base* val1;
	Base* val2;
	double value;

    public:
	Mult(Base* val1, Base* val2){
	    this->val1 = val1;
	    this->val2 = val2;
	    this->value = val1->evaluate() * val2->evaluate();
	}

	virtual double evaluate() {return value;}
	virtual std::string stringify(){
	    return "(" + val1->stringify() + "*" + val2->stringify() + ")";
	}

};

#endif
