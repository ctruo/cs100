#ifndef __TASKS_H__
#define __TASKS_H__

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
    virtual void addName(string _name);
    virtual void addDescription(string _description);
    virtual void addDeadline(string _deadline);
    virtual void setStatus(bool _status);
    virtual void setParent(Tasks* task);
    virtual void addTask(Tasks* task) {} //default implementation
    virtual void removeTask(Tasks* targetTask) {} //default implementation
    virtual Tasks* findTask(string targetString) { return nullptr; } //default implementation
    virtual string findClosestDeadline() { return ""; } //default implementation

    virtual string getName();
    virtual string getDescription();
    virtual string getDeadline();
    virtual bool getStatus();
    virtual Tasks* getParent();
    //for testing
    int getTestVar() { return testVar; }
};
#endif
