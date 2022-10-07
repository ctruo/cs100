#include "./../taskcommandsheader/changetaskname.hpp"

changetaskname::changetaskname(Tasks* task, std::string name) {
    setTask = task;
    setName = name;
}

void changetaskname::execute() {
    setTask->addName(setName);
}

void changetaskname::unexecute() {
    //the user cant whipe a name, they must change the name 
}
