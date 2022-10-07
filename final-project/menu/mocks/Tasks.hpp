#ifndef __TASKS_HPP__
#define __TASKS_HPP_

#include <iostream>

class Tasks{
    protected:
	std::string name;
	std::string deadline;
	std::string description;
	bool status;
    public:
	virtual void print() =0;
	virtual void addDeadline() =0;
	virtual void setStatus() =0;
	virtual void addDescription() =0;
	virtual void addName() =0;
};
#endif//Tasks.hpp
