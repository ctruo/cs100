#ifndef TASKMOCK_HPP
#define TASKMOCK_HPP

#include "./../Tasks/Tasks.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cout; 
using std::endl;

class TaskMock : public Tasks {
public:
    TaskMock();
    ~TaskMock();
    TaskMock(const TaskMock& rhs);
    virtual void print();
    void addName(string _name);
    void addDescription(string _description);
    void addDeadline(string _deadline);
    void setStatus(bool _status);
    void addTask(Tasks* task);
    void removeTask(Tasks* targetTask);
};
#endif //TaskMock.hpp
