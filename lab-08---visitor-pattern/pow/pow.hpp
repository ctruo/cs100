#ifndef __POW_HPP__
#define __POW_HPP__

#include "../base.hpp"
#include "../visitor.hpp"
#include "../visitorLatex.hpp"
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
        virtual int number_of_children() { return 2; }
        virtual Base* get_child(int i) {
         if (i == 0) {
            return op1;
         }
         else if (i == 1 ) {
            return op2;
         }
        }

	virtual void accept(Visitor* visitor, int index){
            if(index == 0){
                visitor->visit_pow_begin(this);
            }
            if(index == 1){
                visitor->visit_pow_middle(this);
            }
            if(index == 2){
                visitor->visit_pow_end(this);
	    }
	}


};

#endif //__POW_HPP__
