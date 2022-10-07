#ifndef __PROJECT_HPP__
#define __PROJECT_HPP__

#include "../Tasks/Tasks.hpp"

#include <iostream>
#include <string>
#include <vector>

#include <typeinfo>

using std::string;

class Project : public Tasks {
    private:
        std::vector<Tasks* > tasks;
        string closestDeadline;
       

    public:
        Project();

        ~Project();
	Project(const Project& rhs);
	vector<Tasks*>* getTasks();
        virtual string findClosestDeadline();
        virtual void addTask(Tasks* task);
        virtual void removeTask(Tasks* targetTask); 
        virtual Tasks* findTask(string targetString);
        virtual void print();
	 bool isLessThan(string , string );

};

#endif
