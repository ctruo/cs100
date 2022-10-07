#ifndef CHANGETASKDESCRIPTION_HPP
#define CHANGETASKDESCRIPTION_HPP

#include <string>

#include "./taskcommand.hpp"

class changetaskdescription : public TaskCommand {
public:
    changetaskdescription(Tasks* task, std::string description);
    changetaskdescription(Tasks* task);
    virtual void execute();
    virtual void unexecute();

private:
    std::string setDescription;
};

#endif //changetaskdescription.hpp
