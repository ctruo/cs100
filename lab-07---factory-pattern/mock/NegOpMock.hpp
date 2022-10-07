#ifndef  __NEG_OP_MOCK__
#define __NEG_OP_MOCK__

#include "../base.hpp"

class NegOpMock: public Base {
    public:
        NegOpMock() { }

        virtual double evaluate() { return -7.5; }
        virtual std::string stringify() { return "-7.5"; }
};
#endif
