#ifndef TASKS_HPP
#define TASKS_HPP

#include <string>
#include <iostream>
using namespace std;

class Tasks {
protected:
    string* name;
    string* description;
    string* deadline;
    bool* status;
    Tasks* myTaskParent;
    int tabCount;

    int countTabs();
    void printTabs();
    //for testing
    int testVar = 0;

public:
    Tasks();

    virtual ~Tasks();
    Tasks(Tasks&);
    virtual void print() = 0;
    void addName(string _name);
    void addDescription(string _description);
    void addDeadline(string _deadline);
    void setStatus(bool _status);
    void setParent(Tasks* task);
    virtual void addTask(Tasks* task);
    virtual void removeTask(Tasks* targetTask);
    virtual Tasks* findTask(string targetString) { return nullptr; }
    virtual string findClosestDeadline() { return ""; } //default implementation
    //for testing
    virtual int getTestVar(); 

    string getName();
    string getDescription();
    string getDeadline();
    bool getStatus();
    Tasks* getParent();
};
#endif //Tasks.hpp
