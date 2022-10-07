#include "Tasks/Tasks.hpp"
#include "Task/Task.hpp"
#include "taskcommandsheader/addtask.hpp"
#include "taskcommandsheader/changetaskname.hpp"
#include "taskcommandsheader/changetaskdescription.hpp"
#include "taskcommandsheader/changetaskdeadline.hpp"
#include "taskcommandsheader/changetaskstatus.hpp"
#include "taskcommandsheader/taskcommand.hpp"
#include "taskcommandsheader/printTasks.hpp"
#include "Project/Project.hpp"
#include "menu/menu.hpp"
#include "Strategyheaders/Prioritize.hpp"
#include "Strategyheaders/Completed.hpp"
#include "Strategyheaders/Scheduler.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

void name(Menu*, Tasks*);
void description(Menu*, Tasks*);
void deadline(Menu*, Tasks*);
void status(Menu*, Tasks*);

void simpleTask(Menu*, Tasks*);
void projectTask(Menu*, Tasks*);
void printTask(Menu*,Tasks*);
void editTask(Menu*, Tasks*);

int main() {
    Menu* menu = new Menu();
    string input;
    string userInput;
    Project* taskList = new Project(); 
    TaskCommand* t= new changetaskname(taskList, "TASK SCHEDULER"); t->execute(); delete t;
    
    
    while (input != "q") {
        menu->generalMenu();
        cin >> input;

        if (input == "a") {
          simpleTask(menu, taskList);  
             
        }
        else if (input == "p") {
          projectTask(menu, taskList);
            
        }
        else if (input == "o") {
            printTask(menu, taskList);
        }
        else if (input == "e") {
            editTask(menu, taskList);
        }
    }
    
    delete menu;
   delete taskList; 

    return 0;
}

void printTask(Menu* menu, Tasks* taskList) {
    int input;

    cout << "Print options: \n0 - Scheduler \n1 - Completed\n2 - Print all\n";
    cin >> input;
    if (input == 0) {
	    Prioritize* s = new Scheduler(taskList);
            TaskCommand* t = new printTasks(s); 
	    t->execute();
	    delete s; delete t;
	}
    
    else if (input == 1) {
	    Prioritize* c = new Completed(taskList);
            TaskCommand* t = new printTasks(c);
            t->execute();
            delete c; delete t;

        }
    
    else {
	    Prioritize* p = new Scheduler(taskList);
            TaskCommand* t = new printTasks(p);
            t->execute();
            delete p; delete t;

       }
}      




void simpleTask(Menu* menu, Tasks* taskList) {
    string input;

    Tasks* task = new Task();
    name(menu, task);
    while (input != "q") {
        menu->simpleMenu();
        cin >> input;

        if (input == "d") {
            description(menu, task);
        }
        else if (input == "t") {
            deadline(menu, task);
        }
        else if (input == "b") {
            status(menu, task);
        }
    }
    TaskCommand* t = new addtask(task, taskList);   
      t->execute(); delete t;
}

void projectTask(Menu* menu,Tasks* taskList) {
    string input;

    Tasks* project = new Project();
	name(menu, project);
     while (input != "q") {
        menu->complexMenu();
        cin >> input;

        if (input == "d") {
            description(menu, project);
        }
        else if (input == "t") {
            deadline(menu, project);
        }
        else if (input == "b") {
            status(menu, project);
        }
        else if (input == "c") {
	   projectTask(menu, project);
                   
        }
        else if (input == "s") {
            simpleTask(menu, project);
        }
    }
    TaskCommand* t = new addtask(project, taskList); t->execute(); delete t;   
 
}

void editTask(Menu* menu, Tasks* taskList){
    string input;
    string taskName;

    cout << "Name of Task: " << endl; cin.ignore();

    getline(cin, taskName);

    Tasks* task = taskList->findTask(taskName);

    while(input != "q"){
        menu->editMenu();
        cin >> input;
        if(input == "en"){
           name(menu, task);
        }    
	else if (input == "ed" ){description(menu, task);}
	else if(input == "et"){deadline(menu, task);}
        else if(input == "eb"){status(menu, task);}

    }

}

void name(Menu* menu, Tasks* task) {
    string userInput;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, userInput);
    cout << endl;
                    
    menu->setUserInput(userInput);
    TaskCommand *cmd1 = new changetaskname(task, menu->UserInput());
    menu->setCommand(cmd1);
    menu->ExecuteCommand();delete cmd1;
}

void description(Menu* menu, Tasks* task) {
    string userInput;

    cout << "Enter description: ";
    cin.ignore();
    getline(cin, userInput);
    cout << endl;
                    
    menu->setUserInput(userInput);
    TaskCommand *cmd1 = new changetaskdescription(task, menu->UserInput());
    menu->setCommand(cmd1);
    menu->ExecuteCommand();delete cmd1;
}

void deadline(Menu* menu, Tasks* task) {
    string userInput;

    cout << "Enter deadline: ";
    cin.ignore();
    getline(cin, userInput);
    cout << endl;
                    
    menu->setUserInput(userInput);
    TaskCommand *cmd1 = new changetaskdeadline(task, menu->UserInput());
    menu->setCommand(cmd1);
    menu->ExecuteCommand(); delete cmd1;
}

void status(Menu* menu, Tasks* task) {
    bool userInput;

    cout << "Update status: \n0 - Not Finished \n1 - Finished\n";
    cin >> userInput;
    cout << endl;
    
    TaskCommand *cmd1 = new changetaskstatus(task, userInput); 
    menu->setCommand(cmd1);
    menu->ExecuteCommand(); delete cmd1;
}
