#include <string>
#include "TaskMock.hpp"

TaskMock::TaskMock() {}

TaskMock::~TaskMock() {}

TaskMock::TaskMock(const TaskMock& rhs) {
    name = new string();
    deadline = new string();
    description = new string();
    status = new bool();

    (*name) = (*rhs.name);
    (*deadline) = (*rhs.deadline);
    (*description) = (*rhs.description);
    (*status) = (*rhs.status);
    myTaskParent = nullptr;
}

void TaskMock::print() {
    testVar = -1; 
}

void TaskMock::addName(string _name) {
    testVar = 5;
}

void TaskMock::addDescription(string _description) {
    testVar = 4;
}

void TaskMock::addDeadline(string _deadline) {
    testVar = 2;
}

void TaskMock::setStatus(bool _status) {
    testVar = 3;
}

void TaskMock::addTask(Tasks* task) {
    testVar = 6;
}

void TaskMock::removeTask(Tasks* targetTask) {
    testVar = 7;
}

