#pragma once
#ifndef __SCHEDULER_HPP_
#define __SCHEDULER_HPP__



#include "../Task/Task.hpp"
#include "../Project/Project.hpp"
#include "./Prioritize.hpp"

#include <vector>
#include <typeinfo>
#include <string>
using std::string;

class Scheduler: public Prioritize{
	public:
		Scheduler(Tasks* t2);
		Tasks* sort();

};

#endif
