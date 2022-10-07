#include "ProjectMock.hpp"

#include <string> 
#include <sstream> 
#include <typeinfo>

using std::string; 
using std::cout; 
using std::endl;

ProjectMock::ProjectMock() {}

ProjectMock::~ProjectMock() 
{ 
    for (int i = 0; i < tasks.size(); ++i) {
        delete this->tasks.at(i); 
    }
    tasks.clear(); 
}

ProjectMock::ProjectMock(const ProjectMock& rhs) {
    //not needed for mock
}

bool ProjectMock::isLessThan(string lhs, string rhs) {
    //not needed for mock
    return false;
}

string ProjectMock::findClosestDeadline() {
    //not needed for mock
    return "";
}

void ProjectMock::print() {
    testVar = 1; 
}

Tasks* ProjectMock::findTask(string targetString) {
    //not needed for mock
    return nullptr; 
}

void ProjectMock::addName(string _name) {
    testVar = 5;
}

void ProjectMock::addDescription(string _description) {
    testVar = 4;
}

void ProjectMock::addDeadline(string _deadline) {
    testVar = 2;
}

void ProjectMock::setStatus(bool _status) {
    testVar = 3;
}

void ProjectMock::addTask(Tasks* task) {
    testVar = 6;
}

void ProjectMock::removeTask(Tasks* targetTask) {
    testVar = 7;
}

