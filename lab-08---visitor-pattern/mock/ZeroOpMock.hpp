#ifndef __ZERO_OP_MOCK__
#define __ZERO_OP_MOCK__

#include "../base.hpp"

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { }

        virtual double evaluate() { return 0; }
        virtual std::string stringify() { return "0"; }

        virtual int number_of_children() { return 0; }
        virtual Base* get_child(int i) { return nullptr; }
};

#endif
