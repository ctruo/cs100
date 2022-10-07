#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <string>

class Div : public Base {

    private:
	Base* val1;
	Base* val2;
	double value;

    public:
	Div(Base* val1, Base* val2){
	    this->val1 = val1;
	    this->val2 = val2;
	    this->value = val1->evaluate() / val2->evaluate();
	}

	virtual double evaluate() {return value;}
    	virtual std::string stringify(){
	    return "(" + val1->stringify() + "/" + val2->stringify() + ")";
	}

};

#endif
