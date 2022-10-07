#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "../base.hpp"
#include "../visitor.hpp"
#include "../visitorLatex.hpp"
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
        virtual int number_of_children() { return 2; }
        virtual Base* get_child(int i) {
         if (i == 0) {
            return val1;
         }
         else if (i == 1 ) {
            return val2;
         }
        }

	virtual void accept(Visitor* visitor, int index){
            if(index == 0){
                visitor->visit_mult_begin(this);
            }
            if(index == 1){
                visitor->visit_mult_middle(this);
            }
            if(index == 2){
                visitor->visit_mult_end(this);
            }

        }


};

#endif
