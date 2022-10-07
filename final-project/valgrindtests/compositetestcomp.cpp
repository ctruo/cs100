#include "./../Tasks/Tasks.hpp"
#include "./../Task/Task.hpp"
#include "./../Project/Project.hpp"

using namespace std;

void complexStructure();
void complexStructureTaskDel();
void complexStructureProjDel();
void complexStructureProjProjDel();
void complexStructureFindTask(); 

int main() {
    complexStructure();  
    complexStructureTaskDel(); 
    complexStructureProjDel();
    complexStructureProjProjDel(); 
    complexStructureFindTask();
    return 0; 
}

void complexStructure() {
    Project* project1 = new Project();
    project1->addName("project1");
    project1->addDescription("description1");
    project1->addDeadline("12/05/21");

    Tasks* item1_1 = new Task();
    item1_1->addName("project1_task1");
    item1_1->addDescription("description1_1");
    item1_1->addDeadline("11/28/21");
    Tasks* item1_2 = new Task();
    item1_2->addName("project1_task2");
    item1_2->addDescription("description1_2");
    item1_2->addDeadline("12/27/21");

    Project* project2 = new Project();
    project2->addName("project2");
    project2->addDescription("description2");
    project2->addDeadline("12/29/21");

    Tasks* item2_1 = new Task();
    item2_1->addName("project2_task1");
    item2_1->addDescription("description2_1");
    item2_1->addDeadline("11/13/21");
    Tasks* item2_2 = new Task();
    item2_2->addName("project2_task2");
    item2_2->addDescription("description2_2");
    item2_2->addDeadline("11/16/21");

    Project* project3 = new Project();
    project3->addName("project3");
    project3->addDeadline("12/25/21");

    Tasks* item3_1 = new Task();
    item3_1->addName("project3_task1");
    item3_1->addDeadline("01/11/11");
    Tasks* item3_2 = new Task();
    item3_2->addName("project3_task2");



    Tasks* item4_1 = new Task();
    item4_1->addName("project1_task3");
    Tasks* item4_2 = new Task();
    item4_2->addName("project1_task4");


    project1->addTask(item1_1);
    project1->addTask(item1_2);

    project2->addTask(item2_1);
    project2->addTask(item2_2);

    project3->addTask(item3_1);
    project3->addTask(item3_2);
    project2->addTask(project3);
    project1->addTask(project2);

    project1->addTask(item4_1);
    project1->addTask(item4_2);

    delete project1;
}

void complexStructureTaskDel() {
    Project* project1 = new Project();
    project1->addName("project1");
    project1->addDescription("description1");
    project1->addDeadline("12/05/21");

    Tasks* item1_1 = new Task();
    item1_1->addName("project1_task1");
    item1_1->addDescription("description1_1");
    item1_1->addDeadline("11/28/21");
    Tasks* item1_2 = new Task();
    item1_2->addName("project1_task2");
    item1_2->addDescription("description1_2");
    item1_2->addDeadline("12/27/21");

    Project* project2 = new Project();
    project2->addName("project2");
    project2->addDescription("description2");
    project2->addDeadline("12/29/21");

    Tasks* item2_1 = new Task();
    item2_1->addName("project2_task1");
    item2_1->addDescription("description2_1");
    item2_1->addDeadline("11/13/21");
    Tasks* item2_2 = new Task();
    item2_2->addName("project2_task2");
    item2_2->addDescription("description2_2");
    item2_2->addDeadline("11/16/21");

    Project* project3 = new Project();
    project3->addName("project3");
    project3->addDeadline("12/25/21");

    Tasks* item3_1 = new Task();
    item3_1->addName("project3_task1");
    item3_1->addDeadline("01/11/11");
    Tasks* item3_2 = new Task();
    item3_2->addName("project3_task2");
		
    Tasks* item4_1 = new Task();
    item4_1->addName("project1_task3");
    Tasks* item4_2 = new Task();
    item4_2->addName("project1_task4");

    project1->addTask(item1_1);
    project1->addTask(item1_2);

    project2->addTask(item2_1);
    project2->addTask(item2_2);

    project3->addTask(item3_1);
    project3->addTask(item3_2);

    project2->addTask(project3);
    project1->addTask(project2);

    project1->addTask(item4_1);
    project1->addTask(item4_2);

    project1->removeTask(item4_2); 

    delete project1;
}

void complexStructureProjDel() {
    Project* project1 = new Project();
    project1->addName("project1");
    project1->addDescription("description1");
    project1->addDeadline("12/05/21");

    Tasks* item1_1 = new Task();
    item1_1->addName("project1_task1");
    item1_1->addDescription("description1_1");
    item1_1->addDeadline("11/28/21");
    Tasks* item1_2 = new Task();
    item1_2->addName("project1_task2");
    item1_2->addDescription("description1_2");
    item1_2->addDeadline("12/27/21");

    Project* project2 = new Project();
    project2->addName("project2");
    project2->addDescription("description2");
    project2->addDeadline("12/29/21");

    Tasks* item2_1 = new Task();
    item2_1->addName("project2_task1");
    item2_1->addDescription("description2_1");
    item2_1->addDeadline("11/13/21");
    Tasks* item2_2 = new Task();
    item2_2->addName("project2_task2");
    item2_2->addDescription("description2_2");
    item2_2->addDeadline("11/16/21");

    Project* project3 = new Project();
    project3->addName("project3");
    project3->addDeadline("12/25/21");

    Tasks* item3_1 = new Task();
    item3_1->addName("project3_task1");
    item3_1->addDeadline("01/11/11");
    Tasks* item3_2 = new Task();
    item3_2->addName("project3_task2");
	
    Tasks* item4_1 = new Task();
    item4_1->addName("project1_task3");
    Tasks* item4_2 = new Task();
    item4_2->addName("project1_task4");

    project1->addTask(item1_1);
    project1->addTask(item1_2);

    project2->addTask(item2_1);
    project2->addTask(item2_2);

    project3->addTask(item3_1);
    project3->addTask(item3_2);

    project2->addTask(project3);
    project1->addTask(project2);

    project1->addTask(item4_1);
    project1->addTask(item4_2);

    project1->removeTask(project3);

    delete project1;
}

void complexStructureProjProjDel() {
    Project* project1 = new Project();
    project1->addName("project1");
    project1->addDescription("description1");
    project1->addDeadline("12/05/21");

    Tasks* item1_1 = new Task();
    item1_1->addName("project1_task1");
    item1_1->addDescription("description1_1");
    item1_1->addDeadline("11/28/21");
    Tasks* item1_2 = new Task();
    item1_2->addName("project1_task2");
    item1_2->addDescription("description1_2");
    item1_2->addDeadline("12/27/21");

    Project* project2 = new Project();
    project2->addName("project2");
    project2->addDescription("description2");
    project2->addDeadline("12/29/21");

    Tasks* item2_1 = new Task();
    item2_1->addName("project2_task1");
    item2_1->addDescription("description2_1");
    item2_1->addDeadline("11/13/21");
    Tasks* item2_2 = new Task();
    item2_2->addName("project2_task2");
    item2_2->addDescription("description2_2");
    item2_2->addDeadline("11/16/21");

    Project* project3 = new Project();
    project3->addName("project3");
    project3->addDeadline("12/25/21");

    Tasks* item3_1 = new Task();
    item3_1->addName("project3_task1");
    item3_1->addDeadline("01/11/11");
    Tasks* item3_2 = new Task();
    item3_2->addName("project3_task2");
	
    Tasks* item4_1 = new Task();
    item4_1->addName("project1_task3");
    Tasks* item4_2 = new Task();
    item4_2->addName("project1_task4");

    project1->addTask(item1_1);
    project1->addTask(item1_2);

    project2->addTask(item2_1);
    project2->addTask(item2_2);

    project3->addTask(item3_1);
    project3->addTask(item3_2);

    project2->addTask(project3);
    project1->addTask(project2);

    project1->addTask(item4_1);
    project1->addTask(item4_2);

    project1->removeTask(project2);

    delete project1;
}

void complexStructureFindTask() {
    Project* project1 = new Project();
    project1->addName("project1");
    project1->addDescription("description1");
    project1->addDeadline("12/05/21");

    Tasks* item1_1 = new Task();
    item1_1->addName("project1_task1");
    item1_1->addDescription("description1_1");
    item1_1->addDeadline("11/28/21");
    Tasks* item1_2 = new Task();
    item1_2->addName("project1_task2");
    item1_2->addDescription("description1_2");
    item1_2->addDeadline("12/27/21");

    Project* project2 = new Project();
    project2->addName("project2");
    project2->addDescription("description2");
    project2->addDeadline("12/29/21");

    Tasks* item2_1 = new Task();
    item2_1->addName("project2_task1");
    item2_1->addDescription("description2_1");
    item2_1->addDeadline("11/13/21");
    Tasks* item2_2 = new Task();
    item2_2->addName("project2_task2");
    item2_2->addDescription("description2_2");
    item2_2->addDeadline("11/16/21");

    Project* project3 = new Project();
    project3->addName("project3");
    project3->addDeadline("12/25/21");

    Tasks* item3_1 = new Task();
    item3_1->addName("project3_task1");
    item3_1->addDeadline("01/11/11");
    Tasks* item3_2 = new Task();
    item3_2->addName("project3_task2");
	
    Tasks* item4_1 = new Task();
    item4_1->addName("project1_task3");
    Tasks* item4_2 = new Task();
    item4_2->addName("project1_task4");

    project1->addTask(item1_1);
    project1->addTask(item1_2);

    project2->addTask(item2_1);
    project2->addTask(item2_2);

    project3->addTask(item3_1);
    project3->addTask(item3_2);

    project2->addTask(project3);
    project1->addTask(project2);

    project1->addTask(item4_1);
    project1->addTask(item4_2);

    Tasks* foundTask = project1->findTask("project1_task1");
    Tasks* foundProj = project1->findTask("project2");
    Tasks* foundProjInProj = project1->findTask("project3"); 

    delete project1; //found task points at the task in the structure, so this delete should also delete all foundtasks also 
}
