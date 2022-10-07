#include "TasksMock.hpp"

Tasks::Tasks() {
    name = new string("");
    description = new string("");;
    deadline = new string("");
    status = new bool(false);
    myTaskParent = nullptr;
    tabCount = 0;

}

Tasks::Tasks(Tasks&) {
    name = new string("");
    description = new string("");;
    deadline = new string("");
    status = new bool(false);
    myTaskParent = nullptr;
    tabCount = 0;
}

Tasks::~Tasks() {
    delete name;
    delete description;
    delete deadline;
    delete status;
    delete myTaskParent;
}

int Tasks::countTabs() {
    //not needed for mock	
    return 0; 
}

void Tasks::printTabs() {
    //not needed for mock
}

void Tasks::addName(string _name) {
    testVar = 5; 
}

void Tasks::addDescription(string _description) {
    testVar = 4;
}

void Tasks::addDeadline(string _deadline) {
    testVar = 2; 
}

void Tasks::setStatus(bool _status) {
    testVar = 3;
}

void Tasks::addTask(Tasks* task) {
    testVar = 6; 
}

void Tasks::removeTask(Tasks* targetTask) {
    testVar = 7; 
}

string Tasks::getName() {
    return "";
}

string Tasks::getDescription() {
    return "";
}

string Tasks::getDeadline() {
    return "";
}

bool Tasks::getStatus() {
    return false;
}

void Tasks::setParent(Tasks* task) {
    //not needed for mock	
}

Tasks* Tasks::getParent() {
    return nullptr;
}

int Tasks::getTestVar() {
    return testVar;
}
