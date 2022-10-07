#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "../Tasks/Tasks.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Task : public Tasks {
    public:
        Task();
        ~Task() ;
	Task(const Task& rhs);
        virtual void print();

};

#endif
