#ifndef COMPLETEDMOCK_H
#define COMPLETEDMOCK_H

#include "./../Strategyheaders/Prioritize.hpp"

#include <vector>
#include <typeinfo>
#include <string>
using std::string;

class CompletedMock : public Prioritize {
public:
    CompletedMock(Tasks* task);
    virtual Tasks* sort();
};
#endif
