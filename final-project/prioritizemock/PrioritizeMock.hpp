#ifndef PRIORITIZEMOCK_HPP
#define PRIORITIZEMOCK_HPP

#include "./../Tasks/Tasks.hpp"

class Prioritize {
public:
    Prioritize() {}
    virtual ~Prioritize() {}

    virtual Tasks* sort() = 0; 
protected:
    Tasks* myTask; 
};
#endif
