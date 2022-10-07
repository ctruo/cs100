#pragma once
#ifndef __COMPLETED_HPP_
#define __COMPLETED_HPP__

#include "../Task/Task.hpp"
#include "../Project/Project.hpp"
#include "./Prioritize.hpp"

#include <vector>
#include <typeinfo>
#include <string>
using std::string;

class Completed: public Prioritize{
	public:
		Completed(Tasks* t2);
		Tasks* sort();

};

#endif
