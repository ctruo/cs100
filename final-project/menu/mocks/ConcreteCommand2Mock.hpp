#ifndef __CONCRETECOMMAND2MOCK_HPP__
#define __CONCRETECOMMAND2MOCK_HPP__

#include "../../taskcommandsheader//taskcommand.hpp"

class ConcreteCommand2Mock: public TaskCommand {
    private:
	std::string word;
    public:
        ConcreteCommand2Mock(){}
        void execute(){ std::cout << "ConcreteCommand2Mock executed" << std::endl;}
        void unexecute(){std::cout << "ConcreteCommand2Mock unexecuted" << std::endl;}
};
#endif //ConcreteCommand2Mock.hpp
