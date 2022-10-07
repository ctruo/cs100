#include "./../Tasks/Tasks.hpp"
#include "./../Task/Task.hpp"
#include "./../Project/Project.hpp"

using namespace std;

void creatingProject();
void creatingTask();          
void addingTask2Project();    //single task is added to a project
void addingTasks2Project();   //multple tasks are added to a project
void addingProject2Project(); //adding a project to a project

int main() {
    creatingProject();
    creatingTask();
    addingTask2Project();
    addingTasks2Project();
    addingProject2Project(); 
}

void creatingProject() {
    Project* project = new Project();
    project->addName("project1");
    project->addDescription("description1");
    project->addDeadline("12/05/21");

    delete project; 
}

void creatingTask() {
    Tasks* item = new Task();
    item->addName("task1");
    item->addDescription("description1_1");
    item->addDeadline("11/28/21");

    delete item;
}

void addingTask2Project() {
    Project* project = new Project();
    project->addName("project1");
    project->addDescription("description1");
    project->addDeadline("12/05/21");

    Tasks* item = new Task();
    item->addName("task1");
    item->addDescription("description1_1");
    item->addDeadline("11/28/21");

    project->addTask(item); 

    delete project; 
}

void addingTasks2Project() {
    Project* project = new Project();
    project->addName("project1");
    project->addDescription("description1");
    project->addDeadline("12/05/21");

    Tasks* item1 = new Task();
    item1->addName("project1_task1");
    item1->addDescription("description1_1");
    item1->addDeadline("11/28/21");

    Tasks* item2 = new Task();
    item2->addName("project1_task2");
    item2->addDescription("description1_2");
    item2->addDeadline("11/28/21");
    item2->setStatus(true);

    project->addTask(item1);
    project->addTask(item2);

    delete project;
}

void addingProject2Project() {
    Project* project1 = new Project();
    project1->addName("project1");
    project1->addDescription("description1");
    project1->addDeadline("12/05/21");

    Tasks* item1 = new Task();
    item1->addName("project1_task1");
    item1->addDescription("description1_1");
    item1->addDeadline("11/28/21");

    Tasks* item2 = new Task();
    item2->addName("project1_task2");
    item2->addDescription("description1_2");
    item2->addDeadline("11/28/21");
    item2->setStatus(true);

    Project* project2 = new Project(); 
    project2->addName("project2");

    project1->addTask(item1);
    project1->addTask(item2);
    project1->addTask(project2);

    delete project1;
}
