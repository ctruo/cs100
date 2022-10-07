#include "./../taskcommandsheader/changetaskdeadline.hpp"

changetaskdeadline::changetaskdeadline(Tasks* task, std::string deadline) {
    setTask = task;
    setDeadline = deadline; 
}

changetaskdeadline::changetaskdeadline(Tasks* task) {
    setTask = task; 
}

void changetaskdeadline::execute() {
    setTask->addDeadline(setDeadline);
}

void changetaskdeadline::unexecute() {
    setTask->addDeadline(""); 
}
