#include "./../taskcommandsheader/printTasks.hpp"

printTasks::printTasks(Prioritize* strategy) {
    myStrategy = strategy;
}

void printTasks::execute() {
    myStrategy->sort()->print();
}

void printTasks::unexecute() {
    //the user should not be allowed to undo a print 
}
