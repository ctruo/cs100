#ifndef PROJECTMOCK_HPP
#define PROJECTMOCK_HPP

#include "./../Tasks/Tasks.hpp" 

#include <iostream>
#include <string>
#include <vector>

using std::string;

class ProjectMock : public Tasks {
public:
    ProjectMock(); 
    ~ProjectMock(); 
    ProjectMock(const ProjectMock& rhs); 
    virtual string findClosestDeadline(); 
    virtual Tasks* findTask(string targetString);
    virtual void print();
    void addName(string _name);
    void addDescription(string _description);
    void addDeadline(string _deadline);
    void setStatus(bool _status);
    void addTask(Tasks* task);
    void removeTask(Tasks* targetTask);
 

private:
    std::vector<Tasks*> tasks; 
    string closestDeadline; 
    bool isLessThan(string, string);
};
#endif //ProjectMock.hpp 
