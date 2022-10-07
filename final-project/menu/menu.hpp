#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "../taskcommandsheader/taskcommand.hpp"
//#include "../taskcommandsheader/taskcommand.hpp"
#include <iostream>

class Menu {
    private:
	std::string userinput;
	TaskCommand *taskcommand;
    public: 
	void simpleMenu();
	void complexMenu();
	void generalMenu();
	void editMenu();
	std::string UserInput();
	void setUserInput(std::string input);
	void setCommand(TaskCommand *command);
	TaskCommand* Command();
	void ExecuteCommand();
	void UnexecuteCommand();

};
#endif//menu.hpp
