#ifndef __TASKCOMMAND_HPP__
#define __TASKCOMMAND_HPP__

#include "../../Tasks/Tasks.hpp"

class TaskCommand {
    protected:
	Tasks* setTask;
    public:
	virtual void execute() =0;
	virtual void unexecute() =0;

};
#endif// TaskCommand.hpp
