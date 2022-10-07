#ifndef CHANGETASKDEADLINE_HPP
#define CHANGETASKDEADLINE_HPP

#include <string>

#include "./taskcommand.hpp"

class changetaskdeadline : public TaskCommand {
public:
    changetaskdeadline(Tasks* task, std::string deadline);
    changetaskdeadline(Tasks* task); 
    virtual void execute();
    virtual void unexecute();

private:
    std::string setDeadline;
};

#endif //changetaskdeadline.hpp
