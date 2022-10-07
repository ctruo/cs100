#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "../base.hpp"
#include <string>

class Sub : public Base {
    private:
       double value;
       Base* op1;
       Base* op2;

    public:
        Sub(Base* op1 ,Base* op2){
 	    this->op1 = op1;
   	    this->op2 = op2;
	    this->value = op1->evaluate() - op2->evaluate();
	}// : Base() { }
        virtual double evaluate() { return value; }
        virtual std::string stringify() {
	     return "(" + op1->stringify() + "-" + op2->stringify() + ")";
        }
};

#endif //__SUB_HPP__
