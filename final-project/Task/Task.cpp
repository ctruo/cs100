#include "Task.hpp"
#include <string>

Task::Task(){}

Task::~Task(){}

Task::Task(const Task& rhs){
    name = new string();
    deadline = new string();
    description = new string();
    status = new bool();

    (*name) = (*rhs.name);
    (*deadline) = (*rhs.deadline);
    (*description) = (*rhs.description);
    (*status) = (*rhs.status);
    myTaskParent = 0;
}


void Task::print() {
    if (!(*name).empty())   //tasks need a name
    {
        this->countTabs();
	this->printTabs();
	cout << "Task: " << (*name) << endl;

	if (!(*description).empty())
	{
	    this->printTabs();
	    cout << "Description: " << (*description) << endl;
	}
	if (!(*deadline).empty())
	{
	    this->printTabs();
	    cout << "Deadline: " << (*deadline) << endl;
	}
	if ((*status) == false)
	{
            this->printTabs();
	    cout << "Status: NOT FINISHED" << endl;
	}
	else if ((*status) == true)
	{
	    this->printTabs();
	    cout << "Status: FINISHED" << endl;
	}
    }
}
