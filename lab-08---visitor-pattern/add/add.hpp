#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "../base.hpp"
#include "../visitor.hpp"
#include "../visitorLatex.hpp"
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
		visitor->visit_add_begin(this);
	    }
	    if(index == 1){
                visitor->visit_add_middle(this);
            }
	    if(index == 2){
                visitor->visit_add_end(this);
            }

	} 
};

#endif //__ADD_HPP__
