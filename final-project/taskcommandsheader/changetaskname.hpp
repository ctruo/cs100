#ifndef CHANGETASKNAME_HPP
#define CHANGETASKNAME_HPP

#include <string>

#include "./taskcommand.hpp"

class changetaskname : public TaskCommand {
public:
    changetaskname(Tasks* task, std::string name);
    virtual void execute();
    virtual void unexecute();

private:
    std::string setName; 
};

#endif //changetaskname.hpp
