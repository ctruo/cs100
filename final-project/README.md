# Task Scheduler:

Authors: [Jesus Martinez Vega](https://github.com/jesus-mv) , [Surabhi Tadvalkar](https://github.com/SurabhiTadvalkar), [Calvin Truong](https://github.com/ctruo)
 
## Project Description
Being college students, time management is essental to our success. Since its important to keep all assignments, and class schedules in order - we decided on a task scheduler seeing as we all need to be organized to succeed. In this task scheduler, the user will be able to create (or delete) tasks with a title, description, priority, and due date. The user will also be able to create tasks within tasks and be able to edit and undo any operations. Input and output will be all be done in the terminal. 

In this project we will be using the composite design pattern and the command design pattern.

composite pattern: 

 One of the potential problems that could occur in a task scheduler is that the task scheduler is unable to meet the user's needs because it is too vague and uncustomizable. To combat this we thought of making a feature to enhance tasks and tailor to the user's needs, a "subtasks" feature. The composite design pattern will be used for its ability to treat groups of objects as if they are a single object. This will allow us to make task objects within task objects. For example, if a there was a task called "cleaning bedroom", the user would be able to add subtasks and specify what "cleaning  bedroom" entails. The user could add "clean closet", "organize desk", "make bed", "sweep floors", and "take out trash".

command pattern:

A task schedulers handles a user's schedule and resposiblities which can change frequently. Therefore, it is important that the task scheduler be able to execute that needed flexibilty. A problem that might hinder this capability is being unable to reverse tasks. To combat this, we thought of make a feature that would allow a user to reverse their changes, an "undo" feature. The command design pattern givers the ability to choose a given behavior for a command. This will allow us to alter tasks by encapsulate requests from the user of specific changes. For example, the user could type "undo task edit" in the terminal and that request would be encapsulated and the task would be reverted to the state before the user's edit. 

strategy pattern:

When printing, it is important that the task scheduler prints what the user wants to see. If the user wanted to plan which tasks they should take care of first according to the deadlines, then the task scheduler should print the tasks from the closest deadline to the furthest deadline. If the user wanted to see which tasks they already completed and which tasks need to be done, the task scheduler should print the tasks according to the status of each task. The strategy pattern allows the printing of different criteria to be selected during run time depending on the user's wants. 
 
 tools and languages: 
 * [c++](https://www.cplusplus.com/info/description/)      - main programming language
 * [valgrind](https://valgrind.org/info/about.html)        - to track memory
 * [cmake](https://cmake.org/overview/)                    - compilation and testing
 * [draw.io](https://drawio-app.com/uml-diagrams/)         - to draw UML diagrams
 * [github](https://github.com/)                           - host of remote repository
 * [googletest](https://github.com/google/googletest.git)  - for unit testing

## Class Diagram
![entireproject](https://github.com/cs100/final-project-jmart586_stadv001_ctruo032/blob/master/images/overall.png)
This is the overarching UML diagram for our task scheduler project. Details can be found below. 

Composite Design Pattern: 

![compositepattern](https://github.com/cs100/final-project-jmart586_stadv001_ctruo032/blob/master/images/composite.png)

For our task scheduler, one of the design patterns we decided on was the composite design pattern. We used this pattern in order to create our “subtask” feature. The structure breaks down as such 

Tasks class - Component:
 It defines an interface. Both the Task class and Project class derive from this class. This class will be abstract because it holds the pure virtual function print(). 
 
 * The addDeadline() function will allow the user to input a deadline for a task

 * The addName() function will allow the user to input a name for a task

 * The addDescription() function will allow the user to input a description for a task

 * The setStatus() function will allow the user to set whether a task is finished or not

 * The setParent() function will set the current Tasks object's parent pointer
 
 * The following functions are virtual and to be overrided at run time: addTask(), removeTask(), findTask(), and findClosestDeadline(). They are not pure however, as not all of the classes that inherit from this abstract base class need to implement these functions. Instead, we decided to have an "empty" implementation. While we acknowledge that these types of implementations are not good practice, we decided to use them to avoid complications in our design and to keep the composite design consistent.

 * The following getter functions return the specified variables of the Tasks object: getName(), getDescription(), getDeadline(), getStatus(), getParent()

 * The printTabs and countTabs functions are used when printing projects and lists of tasks. Printed tabs denote that a task or project belong to a parent project and this will allow for correct hierarchy of projects and tasks to be printed, while also improving readability

Task class - Leaf: 
It creates an object, specifically a single task, which can have a name, description, deadline, and/or status. It holds no objects of its parent class 

 * The copy constructor will copy the Task object to allow for use within the strategy pattern when printing
 
 * In the print method(), it will list out all the information that has been entered and output it into the terminal

Project class - Composite: It creates an object which can hold the same values as Task, a closest deadline, and a list of tasks within the project (“subtask” feature). The list of tasks within the project is a vector of Tasks pointers.

 * The copy constructor will copy the Task object to allow for use within the strategy pattern when printing
 
 * In the print method(), it will list out all the information that has been entered and output it into the terminal

 * The findClosestDeadline() function will return the closest deadline. The closest deadline will be found among the subtasks of a project to set an overall deadline for the project

 * The addTask() function will add push a task to the vector of the Project object

 * The removeTask() function will remove the specified task from the Project object

 * The findTask() function will search for the specified task within the Project object and return it if found. If it was not found, it will return a null pointer

 

Command Design Pattern: 

![commandpattern](https://github.com/cs100/final-project-jmart586_stadv001_ctruo032/blob/master/images/command.png)
(look in the images folder for a better picture)

For our task scheduler, one of the design patterns we decided on was the command design pattern. We used this pattern in order to create our “undo” feature and to edit/add information to the tasks and projects. The structure breaks down as such:

Menu class - Invoker: \
![menuclass](https://github.com/cs100/final-project-jmart586_stadv001_ctruo032/blob/master/images/invoker.png)

The menu class has six methods.
In the first method, readInput(string input), it will simply take the user’s input and store it in the the class under the private variable string userinput

In simpleMenu(), it will print out a menu (see below) that can be used to add the information for a simple task to the task scheduler. \
n-name *you must enter a name\
d-description\
t-deadline\
b-status\
q-I'm done entering info

In complexMenu(), it will print out a menu (see below) that can be used to add the information for a project to the task scheduler. \
n-name *you must enter a name\
d-description \
t-deadline \
b-status \
c- project subtask \
s-simple subtask \
q-I’m done entering info

In generalMenu(), it will print out a menu (see below) that can be used to add a simple task, project, or edit a task/project \
TASK SCHEDULER \
a- add simple task \
p- add project \
o- print my list \
e- edit task \
q-quit

In editMenu(), it will print out a menu (see below) that presents the options of what can be edited \
en - edit name \
ed - edit desc \
et - edit deadline \
eb - change status

In setCommand(TaskCommand* Command), it will look at the string userinput and determine which concrete command should be called. For example, if a user looks at the general menu and then type in “a”, it will set the private variable TaskCommand* setCommand to point to an addsimpletask object. 

TaskCommand - command interface and all of its associated concrete commands: \
![taskcommand](https://github.com/cs100/final-project-jmart586_stadv001_ctruo032/blob/master/images/taskCommand.png) \
TaskCommand is the abstract base class for all of the concrete commands, it consists of two methods, execute() and unexecute().

addsimpletask - concrete command, adds one task to the task scheduler \
addcomplextask -concrete command, adds one “complex” task, or a project, to the task scheduler \
changetaskname- concrete command, changes a partucular task's name \
changetaskdeadline- concrete command, changes the deadline of a task (note that deadlines are of the form: mm/dd/yyyy) \
changetaskdescription- concrete command, changes the description of a partucular task. \
printTasks- concrete command, prints all tasks in the task scheduler

Task class - reciever: \
![receiver](https://github.com/cs100/final-project-jmart586_stadv001_ctruo032/blob/master/images/reciever.png) \
Tasks - this class functions as the receiver for the command design pattern, in addition to functioning as the component for the composite design pattern 

An example of how the classes interact:

The program will start off seeing the general menu from the generalMenu() method in the menu class.  
TASK SCHEDULER  
a- add simple task  
p- add project  
o- print my list  
e- edit task  
q-quit 

Lets say the user wants to make a project, then they will enter “p”.  
The user will then see the complex menu from the complexMenu() method from the Menu class.  
n-name *you must enter a name  
d-description  
t-deadline  
b-status  
c-project subtask  
s-simple subtask  
q-I’m done entering info 

Then lets say that the user wants to name their project, so they will enter “n”  
the user will enter the desired name and the readInput(string input) method will be called and store this name under the private variable string userinput.  
Then the setCommand() method from the menu class will set the private variable TaskCommand* setCommand to point to a changetaskname object.  
Then execute() from the changetaskname class will be called, indirectly calling addName(string \_name) in the Project class. 

The user will then see the complex menu from the complexMenu() method from the Menu class.  
n-name *you must enter a name  
d-description  
t-deadline  
B-status  
c-complex subtask  
s-simple subtask  
q-I’m done entering info 

The user wants to create a simple subtask for their project, so they will enter “s” \
Then the setCommand() method from the menu class and will set the private variable TaskCommand* setCommand to the addsimpletask concrete command class.  
causing execute() from the addsimpletask concrete command class to be called and setting a new Task object inside the vector of the project  
Then the user will see the Task menu from the method simpleMenu() from the Menu class  
n-name *you must enter a name  
d-description  
t-deadline  
b-status  
q-I'm done entering info 

The user wants to name their subtask, so they will enter “n”  
Then the user will enter the desired name and the readInput(string input) method in the menu class will be called and store this name under the private variable string userinput.  
Then the setCommand() method from the menu class and will set the private variable TaskCommand* setCommand to the changetaskname concrete command class.  
Then execute() from the changetaskname concrete command class will be called which will call addName() in the Task class.  

Then the user will see the Task menu from the method simpleMenu() from the Menu class  
n-name *you must enter a name  
d-description  
t-deadline  
b-status  
q-I'm done entering info 

Then the user has finished making their subtask so they enter “q”  
Then the user will see the project menu from the method complexMenu() from the Menu class  
n-name *you must enter a name  
d-description  
t-deadline  
b-status  
c- project subtask  
s-simple subtask  
q-I’m done entering info 

The user has finished creating subtasks and entering information for their project so they call “q”  
The user will see the general menu from the method generalMenu() from the Menu class  
TASK SCHEDULER  
a- add simple task  
p- add project  
o- print my list  
e- edit task  
q-quit 


Strategy Design Pattern: 

![strategy](https://github.com/cs100/final-project-jmart586_stadv001_ctruo032/blob/master/images/strategy.png)

printTasks class - composition: \
Responsible for making sure the concrete strategy is set correctly. This is a class takes a strategy object that is created depending on the user's selection of criteria for printing. It has a private strategy pointer variable that will be set to the object being passed in. Upon the call of the execute command to print, the strategy object will be sorted and printed according to selected strategy.

Prioritize class - compositor: \
The "abstract" class which all concrete strategies derive from. In this class, sort() has a default implementation which simply prints out the (unsorted) tasks or projects. 

Scheduler - concrete strategy 1: \
In the Scheduler concrete strategy class, sort() will sort the tasks or projects by deadline. The closest deadline will be printed first and the last deadline is the furthest date. The Scheduler sort() function utlizies the copied tasks object that is passed in the constructor. Insertion sort is then used to sort the entire task scheduler and arrange them by dates. Recursion is used to account for composite class cases, such as projects within projects. The deadlines within these complex projects will be sorted by date as well. 

Completed - concrete strategy 2: \
In the Completed concrete strategy class, sort() will sort the tasks or projects by status. Tasks and projects that have not been finished will be output first, followed by the completed tasks and projects. The Completed sort() function utlizies the copied tasks object that is passed in the constructor. Insertion sort is then used to sort the entire task scheduler and arrange them by status. Recursion is used to account for composite class cases, such as projects within projects. The deadlines within these complex projects will be sorted by completion as well. 

 ## Screenshots
 General Menu: \
 <img width="139" alt="general_menu" src="https://user-images.githubusercontent.com/77246269/120323646-8f4ef280-c29a-11eb-867f-a522e83ca2db.png">
 
 Task Input Menu: \
 <img width="209" alt="task_input" src="https://user-images.githubusercontent.com/77246269/120320443-0aaea500-c297-11eb-8589-fc7a62246ec0.png">
 
 Project Input Menu: \
 <img width="185" alt="project_input" src="https://user-images.githubusercontent.com/77246269/120320849-814ba280-c297-11eb-83e9-32fe739281c6.png">
 
 Edit Input Menu: \
<img width="213" alt="edit_input" src="https://user-images.githubusercontent.com/77246269/120320950-97596300-c297-11eb-8d27-4003901284e0.png">

Print Input Menu: \
<img width="139" alt="print_input" src="https://user-images.githubusercontent.com/77246269/120321006-a5a77f00-c297-11eb-9f7a-b6715c20bc83.png">

Prioritized Output (normal output, no sort): \
<img width="437" alt="prioritize_output" src="https://user-images.githubusercontent.com/77246269/120321340-0cc53380-c298-11eb-8243-28ccccd25150.png">

Completed Output (sorted by status): \
<img width="444" alt="completed_output" src="https://user-images.githubusercontent.com/77246269/120321413-21a1c700-c298-11eb-9a21-e9e421a43728.png">

Scheduler Output (sorted by date): \
<img width="413" alt="scheduler_output" src="https://user-images.githubusercontent.com/77246269/120321484-367e5a80-c298-11eb-90d9-dbc70ff87569.png">

 ## Installation/Usage
In a terminal, using git, clone the repository and change the directory as follows: 
```console
git clone --recursive https://github.com/cs100/final-project-jmart586_stadv001_ctruo032.git
cd final-project-jmart586_stadv001_ctruo032
```
If not already installed, install CMake3. Then, run the following commands: 
```console 
cmake3 .
make 
````
This will create multiple executables. For the purpose of running the program only one needs to be run. Type the following command:
```console 
./main
````
After which the Task Scheduler will run. 

The program has a total of four menus: a general menu, edit menu, simple menu, and a complex menu. The general menu is the default menu of the program, from here, all other menus are accessed. Entering "a" will initiate the simple menu, allowing options on simple tasks. Similarly, entering "e" will open the edit menu, enabling edits on existing tasks or projects. Finally, entering "p" will begin the complex menu, permitting various options on projects. \
Additionally, entering "o" will allow for a variety of ways to print the projects / tasks. Entering "q" in the general menu will exit the program, otherwise "q" will simply exit the current menu. 

 ## Testing
Running ```cmake3 .``` and ```make``` will generate, in addition to the executable for the Task Scheduler, various unit test executables. These unit tests were used ensure that the various classes that make up the Task Scheduler would run correctly. \
Valgrind was also used to confirm the absence of memory leaks. To this end, various valgrind tests were created. In these tests, the interactions between classes that make up the Task Scheduler were put to the test, so that no memory leaks would be present in the main executable. 
