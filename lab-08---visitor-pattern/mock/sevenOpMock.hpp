#ifndef __SEVENOPMOCK_HPP__
#define __SEVENOPMOCK_HPP__

#include "../base.hpp"

class SevenOpMock: public Base {
    public:
        SevenOpMock() { }

        virtual double evaluate() { return 7.5; }
        virtual std::string stringify() { return "7.5"; }
        virtual int number_of_children() { return 0; }
        virtual Base* get_child(int i) { return nullptr; }
};

#endif
