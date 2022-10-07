#ifndef SCHEDULERMOCK_H
#define SCHEDULERMOCK_H

#include "./../Strategyheaders/Prioritize.hpp"

#include <vector>
#include <typeinfo>
#include <string>
using std::string;

class SchedulerMock : public Prioritize {
public:
    SchedulerMock(Tasks* task); 
    virtual Tasks* sort(); 
};
#endif
