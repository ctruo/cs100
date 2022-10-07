#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "../base.hpp"
#include "../visitor.hpp"
#include "../visitorLatex.hpp"
#include <string>
#include <stdlib.h>

class Rand : public Base {
    private:
        double value;

    public:
        Rand(){
            this->value = rand() % 100;
        }

        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }
        virtual int number_of_children() {return 0; }
        virtual Base* get_child(int i) {return nullptr; }

	virtual void accept(Visitor* visitor, int index){
            if(index == 0){
                visitor->visit_rand(this);
            }
        }


};

#endif
