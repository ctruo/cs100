#include "./../taskcommandsheader/addtask.hpp"

addtask::addtask(Tasks* childTask, Tasks* parentTask) {
    setTask = parentTask;
    setChildTask = childTask; 
}

void addtask::execute() {
    setTask->addTask(setChildTask); 
}
    
void addtask::unexecute() {
    setTask->removeTask(setChildTask);
}
