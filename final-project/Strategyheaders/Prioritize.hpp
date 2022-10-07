#pragma once
#ifndef __PRIORITIZE_HPP_
#define __PRIORITIZE_HPP__

#include "../Task/Task.hpp"
#include "../Project/Project.hpp"

#include <typeinfo>

class Prioritize{
	protected:
		Tasks* myTask;
	public:
		Prioritize(Tasks* t);
                Prioritize(); 
		virtual	Tasks* sort();

};

#endif
