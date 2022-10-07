
#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <math.h>
#include <string>

class Pow : public Base {
    private:
       double value;
       Base* op1;
       Base* op2;

    public:
        Pow(Base* op1 ,Base* op2){
 	    this->op1 = op1;
   	    this->op2 = op2;
	    this->value = pow(op1->evaluate(), op2->evaluate());
	}// : Base() { }
        virtual double evaluate() { return value; }
        virtual std::string stringify() {
	     return "(" + op1->stringify() + "**" + op2->stringify() + ")";
        }
};

#endif //__POW_HPP__
