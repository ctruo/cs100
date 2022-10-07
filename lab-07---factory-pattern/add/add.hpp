#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "../base.hpp"
#include <string>

class Add : public Base {
    private:
       double value;
       Base* op1;
       Base* op2;

    public:
        Add(Base* op1 ,Base* op2){
 	    this->op1 = op1;
   	    this->op2 = op2;
	    this->value = op1->evaluate() + op2->evaluate();
	}// : Base() { }
        virtual double evaluate() { return value; }
        virtual std::string stringify() {
	     return "(" + op1->stringify() + "+" + op2->stringify() + ")";
        }
};

#endif //__ADD_HPP__
