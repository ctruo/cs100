#include "SchedulerMock.hpp"
#include "../taskmock/ProjectMock.hpp"
#include "../taskmock/TaskMock.hpp"

SchedulerMock::SchedulerMock(Tasks* task) : Prioritize() {
    myTask = task; 
} 

Tasks* SchedulerMock::sort() {
    return myTask; 
} 
