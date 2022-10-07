#ifndef ADDTASK_HPP
#define ADDTASK_HPP

#include "./taskcommand.hpp"

class addtask : public TaskCommand {
public:
    addtask(Tasks* childTask, Tasks* parentTask);
    ~addtask() {}
    virtual void execute(); 
    virtual void unexecute();
private: 
    Tasks* setChildTask; 
};

#endif//addtask.hpp
