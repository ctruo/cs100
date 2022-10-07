#ifndef TASKCOMMAND_HPP
#define TASKCOMMAND_HPP

//#include "./../taskmock/TasksMock.hpp"

#include "./../Tasks/Tasks.hpp"
#include "./../Task/Task.hpp"
#include "./../Project/Project.hpp"

class TaskCommand {
public:
    TaskCommand() {}
    virtual ~TaskCommand() {}
    virtual void execute() = 0;
    virtual void unexecute() = 0;
protected:
    Tasks* setTask = nullptr;
};

#endif //taskcommand.hpp
