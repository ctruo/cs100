#include "./../taskcommandsheader/changetaskdescription.hpp" 

changetaskdescription::changetaskdescription(Tasks* task, std::string description) {
    setTask = task;
    setDescription = description;
}

changetaskdescription::changetaskdescription(Tasks* task) {
    setTask = task;
}

void changetaskdescription::execute() {
    setTask->addDescription(setDescription);
}

void changetaskdescription::unexecute() {
    setTask->addDescription(""); 
}
