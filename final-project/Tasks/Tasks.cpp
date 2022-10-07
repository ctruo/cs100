#include "Tasks.hpp"

Tasks::Tasks(){
    name = new string("");
    description = new string ("");;
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
}

int Tasks::countTabs() {

    if (this->myTaskParent != nullptr) {
        tabCount = 0;

        for (Tasks* parent = myTaskParent; parent != nullptr; parent = parent->getParent()) {
	    tabCount++;
	}
	return tabCount;
    }
    return 0;
}

void Tasks::printTabs() {
    for (int i = 0; i < tabCount; i++) {
        std::cout << "\t";
    }
}

void Tasks::addName(string _name) {
    (*name) = _name;
}

void Tasks::addDescription(string _description) {
    (*description) = _description;
}

void Tasks::addDeadline(string _deadline) {
    (*deadline) = _deadline;
}

void Tasks::setStatus(bool _status) {
    (*status) = _status;
}

string Tasks::getName() {
    return (*name);
}

string Tasks::getDescription() {
    return (*description);
}

string Tasks::getDeadline() {
    return (*deadline);
}

bool Tasks::getStatus() {
    return (*status);
}

void Tasks::setParent(Tasks* task) {
    myTaskParent = task;
}

Tasks* Tasks::getParent() {
    return myTaskParent;
}
