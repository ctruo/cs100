#include "gtest/gtest.h"
#include "../Tasks/Tasks.hpp"
#include "Project.hpp"
#include "../Task/Task.hpp"

using std::string;

TEST(ProjectClass, Constructor) {
   Project* project = new Project();
   bool testBool = false;

   if (project->getName() == "" && project->getDescription() == "" && project->getDeadline() == "" & project->getStatus() == false)
   {
      testBool = true;
   }

   EXPECT_EQ(testBool, true);
}

TEST(ProjectClassCopyConstructor, EmptyProjects){
    Tasks* p1 = new Project();
    Tasks* p2 = new Project(*(dynamic_cast<Project*>(p1)));

    EXPECT_FALSE(&(*p1)== &(*p2));


}

TEST(ProjectClassCopyConstructor, Empty_Full_Projects){
    Tasks* p1 = new Project();
    Tasks* p2 = new Project(*(dynamic_cast<Project*>(p1)));
    
    p1->addName("Surabhi");
    p1->addDescription("Surabhi2");
    p1->addDeadline("Surabhi2");
    p1->setStatus(true);

    EXPECT_FALSE(&(*p1)== &(*p2));
    EXPECT_EQ(p2->getName(), "");
    EXPECT_EQ(p2->getDescription(),"");
    EXPECT_EQ(p2->getDeadline(), "");
    EXPECT_FALSE(p2->getStatus()); 

}
TEST(ProjectClassCopyConstructor, Empty_Full_Projects2){
    Tasks* p1 = new Project();
    Tasks* p2 = new Project(*(dynamic_cast<Project*>(p1)));

    p2->addName("Surabhi");
    p2->addDescription("Surabhi2");
    p2->addDeadline("Surabhi3");
    p2->setStatus(true);

    EXPECT_FALSE(&(*p1)== &(*p2));
    EXPECT_EQ(p2->getName(), "Surabhi");
    EXPECT_EQ(p2->getDescription(),"Surabhi2");
    EXPECT_EQ(p2->getDeadline(), "Surabhi3");
    EXPECT_TRUE(p2->getStatus());

    EXPECT_EQ(p1->getName(), "");
    EXPECT_EQ(p1->getDescription(),"");
    EXPECT_EQ(p1->getDeadline(), "");
    EXPECT_FALSE(p1->getStatus());

}

TEST(ProjectClassName, AddName) {
   Project* project = new Project();
   project->addName("New Project");

   EXPECT_EQ(project->getName(), "New Project");
}

TEST(ProjectClassName, AddNameMultipleTimes) {
   Project* project = new Project();
   project->addName("New Project");
   project->addName("Newer Project");
   project->addName("Newest Project");

   EXPECT_EQ(project->getName(), "Newest Project");
}

TEST(ProjectClassName, AddNameEmpty) {
   Project* project = new Project();
   project->addName("");

   EXPECT_EQ(project->getName(), "");
}

TEST(ProjectClassDescription, AddDescription) {
   Project* project = new Project();
   project->addDescription("Add a description");

   EXPECT_EQ(project->getDescription(), "Add a description");
}

TEST(ProjectClassDescription, AddDescriptionMultipleTimes) {
   Project* project = new Project();
   project->addDescription("Clean house");
   project->addDescription("Clean room");
   project->addDescription("Just clean");

   EXPECT_EQ(project->getDescription(), "Just clean");
}

TEST(ProjectClassDescription, AddDescriptionEmpty) {
   Project* project = new Project();
   project->addDescription("");

   EXPECT_EQ(project->getDescription(), "");
}

TEST(ProjectClassDeadline, AddDeadline) {
   Project* project = new Project();
   project->addDeadline("5/14/21");

   EXPECT_EQ(project->getDeadline(), "5/14/21");
}

TEST(ProjectClassDeadline, AddDeadlineMultipleTimes) {
   Project* project = new Project();
   project->addDeadline("5/17/21");
   project->addDeadline("6/17/21");
   project->addDeadline("7/17/21");

   EXPECT_EQ(project->getDeadline(), "7/17/21");
}

TEST(ProjectClassDeadline, ProjectDeadlineEmpty) {
   Project* project = new Project();
   project->addDeadline("");

   EXPECT_EQ(project->getDeadline(), "");
}

TEST(ProjectClass_getTasks, emptyTasks){

Project* p = new Project();
vector<Tasks*>* ptasks = p->getTasks();

EXPECT_EQ(*ptasks, *p->getTasks());


}

TEST(ProjectClass_getTasks, fullTasks){

Project* p = new Project();
vector<Tasks*>* ptasks = p->getTasks();

EXPECT_EQ(*ptasks, *p->getTasks());


}

TEST(ProjectClassDeadline, FindClosestDeadlineDay) {
   Project* project = new Project();
   project->addDeadline("05/20/21");
   Task* task = new Task();
   task->addDeadline("05/19/21");
   Task* task1 = new Task();
   task1->addDeadline("05/21/21");
   project->addTask(task);
   project->addTask(task1);
   
   EXPECT_EQ(project->findClosestDeadline(), "05/19/21");
}

TEST(ProjectClassDeadline, FindClosestDeadlineYear) {
   Project* project = new Project();
   project->addDeadline("05/20/21");
   Task* task = new Task();
   task->addDeadline("05/19/21");
   Project* project1 = new Project();
   project1->addDeadline("04/01/20");
   project->addTask(task);
   project->addTask(project1);

   EXPECT_EQ(project->findClosestDeadline(), "04/01/20");
}

TEST(ProjectClassDeadline, FindClosestDeadlineMonth) {
   Project* project = new Project();
   project->addDeadline("04/20/21");
   Task* task = new Task();
   task->addDeadline("05/19/21");
   Task* task1 = new Task();
   task1->addDeadline("05/21/21");
   project->addTask(task);
   project->addTask(task1);

   EXPECT_EQ(project->findClosestDeadline(), "04/20/21");
}

TEST(ProjectClassDeadline, FindClosestDeadlineProjectSimple) {
   Tasks* project1 = new Project();
   project1->addDeadline("03/20/21");

   Tasks* task1_1 = new Task();
   task1_1->addDeadline("01/15/21");
   Tasks* task1_2 = new Task();
   task1_2->addDeadline("02/13/21");

   project1->addTask(task1_1);
   project1->addTask(task1_2);

   Tasks* project2 = new Project();
   project2->addDeadline("05/05/21");

   Tasks* task2_1 = new Task();
   task2_1->addDeadline("07/03/00");
   Tasks* task2_2 = new Task();
   task2_2->addName("project2_task2");

   project2->addTask(task2_1);
   project2->addTask(task2_2);
   project1->addTask(project2);

   EXPECT_EQ(project1->findClosestDeadline(), "07/03/00"); 
}

TEST(ProjectClassDeadline, FindClosestDeadlineProjectComplex) {
    Project* project1 = new Project();
    project1->addDeadline("12/05/21");

    Tasks* item1_1 = new Task();
    item1_1->addDeadline("11/28/21");
    Tasks* item1_2 = new Task();
    item1_2->addDeadline("12/27/21");

    Project* project2 = new Project();
    project2->addDeadline("12/29/21");

    Tasks* item2_1 = new Task();
    item2_1->addDeadline("11/13/21");
    Tasks* item2_2 = new Task();
    item2_2->addDeadline("11/16/21");

    Project* project3 = new Project();
    project3->addDeadline("12/25/21");

    Tasks* item3_1 = new Task();
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

    EXPECT_EQ(project1->findClosestDeadline(), "01/11/11");
}

TEST(ProjectClassStatus, AddStatusFalse) {
   Project* project = new Project();
   project->setStatus(false);

   EXPECT_EQ(project->getStatus(), false);
}

TEST(ProjectClassStatus, AddStatusTrue) {
   Project* project = new Project();
   project->setStatus(true);

   EXPECT_EQ(project->getStatus(), true);
}

TEST(ProjectClassFind, FindFirst) {
   Tasks* project1 = new Project();
   project1->addName("project1");

   Tasks* task1_1 = new Task();
   task1_1->addName("project1_task1");
   Tasks* task1_2 = new Task();
   task1_2->addName("project1_task2");

   project1->addTask(task1_1);
   project1->addTask(task1_2);

   Tasks* project2 = new Project();
   project2->addName("project2");

   Tasks* task2_1 = new Task();
   task2_1->addName("project2_task1");
   Tasks* task2_2 = new Task();
   task2_2->addName("project2_task2");

   project2->addTask(task2_1);
   project2->addTask(task2_2);

   project1->addTask(project2);

   Tasks* foundTask = project1->findTask("project1");

   EXPECT_EQ(foundTask, project1); 
}

TEST(ProjectClassFind, FindInProject) {
   Tasks* project1 = new Project();
   project1->addName("project1");

   Tasks* task1_1 = new Task();
   task1_1->addName("project1_task1");
   Tasks* task1_2 = new Task();
   task1_2->addName("project1_task2");

   project1->addTask(task1_1);
   project1->addTask(task1_2);

   Tasks* project2 = new Project();
   project2->addName("project2");

   Tasks* task2_1 = new Task();
   task2_1->addName("project2_task1");
   Tasks* task2_2 = new Task();
   task2_2->addName("project2_task2");

   project2->addTask(task2_1);
   project2->addTask(task2_2);

   project1->addTask(project2);

   Tasks* foundTask = project1->findTask("project1_task2");

   EXPECT_EQ(foundTask, task1_2);
}

TEST(ProjectClassFind, FindProject) {
   Tasks* project1 = new Project();
   project1->addName("project1");

   Tasks* task1_1 = new Task();
   task1_1->addName("project1_task1");
   Tasks* task1_2 = new Task();
   task1_2->addName("project1_task2");

   project1->addTask(task1_1);
   project1->addTask(task1_2);

   Tasks* project2 = new Project();
   project2->addName("project2");

   Tasks* task2_1 = new Task();
   task2_1->addName("project2_task1");
   Tasks* task2_2 = new Task();
   task2_2->addName("project2_task2");

   project2->addTask(task2_1);
   project2->addTask(task2_2);

   project1->addTask(project2);

   Tasks* foundTask = project1->findTask("project2");

   EXPECT_EQ(foundTask, project2);
}

TEST(ProjectClassFind, FindInNestedProject) {
   Tasks* project1 = new Project();
   project1->addName("project1");

   Tasks* task1_1 = new Task();
   task1_1->addName("project1_task1");
   Tasks* task1_2 = new Task();
   task1_2->addName("project1_task2");

   project1->addTask(task1_1);
   project1->addTask(task1_2);

   Tasks* project2 = new Project();
   project2->addName("project2");

   Tasks* task2_1 = new Task();
   task2_1->addName("project2_task1");
   Tasks* task2_2 = new Task();
   task2_2->addName("project2_task2");

   project2->addTask(task2_1);
   project2->addTask(task2_2);

   project1->addTask(project2);

   Tasks* foundTask = project1->findTask("project2_task1");

   EXPECT_EQ(foundTask, task2_1);
}

TEST(ProjectClassFind, NotFound) {
   Tasks* project1 = new Project();
   project1->addName("project1");

   Tasks* task1_1 = new Task();
   task1_1->addName("project1_task1");
   Tasks* task1_2 = new Task();
   task1_2->addName("project1_task2");

   project1->addTask(task1_1);
   project1->addTask(task1_2);

   Tasks* project2 = new Project();
   project2->addName("project2");

   Tasks* task2_1 = new Task();
   task2_1->addName("project2_task1");
   Tasks* task2_2 = new Task();
   task2_2->addName("project2_task2");

   project2->addTask(task2_1);
   project2->addTask(task2_2);

   project1->addTask(project2);

   Tasks* foundTask = project1->findTask("project3");

   EXPECT_EQ(foundTask, nullptr);
}

TEST(ProjectClassPrint, ProjectInProject) {
   Tasks* project1 = new Project();
   project1->addName("project1");

   Tasks* task1_1 = new Task();
   task1_1->addName("project1_task1");
   Tasks* task1_2 = new Task();
   task1_2->addName("project1_task2");

   project1->addTask(task1_1);
   project1->addTask(task1_2);

   Tasks* project2 = new Project();
   project2->addName("project2");

   Tasks* task2_1 = new Task();
   task2_1->addName("project2_task1");
   Tasks* task2_2 = new Task();
   task2_2->addName("project2_task2");

   project2->addTask(task2_1);
   project2->addTask(task2_2);

   project1->addTask(project2);

   testing::internal::CaptureStdout();
   project1->print();
   string taskOutput = testing::internal::GetCapturedStdout();

   std::ostringstream output;
   output << "Project: project1" << std::endl;
   output << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Task: project1_task1" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Task: project1_task2" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Project: project2" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "\t" << "Task: project2_task1" << std::endl;
   output << "\t" << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "\t" << "Task: project2_task2" << std::endl;
   output << "\t" << "\t" << "Status: NOT FINISHED" << std::endl;

   EXPECT_EQ(taskOutput, output.str());
}

TEST(ProjectClassPrint, PNPWithAdditionalTasks) {
   Tasks* project1 = new Project();
   project1->addName("project1");

   Tasks* task1_1 = new Task();
   task1_1->addName("project1_task1");
   Tasks* task1_2 = new Task();
   task1_2->addName("project1_task2");

   project1->addTask(task1_1);
   project1->addTask(task1_2);

   Tasks* project2 = new Project();
   project2->addName("project2");

   Tasks* task2_1 = new Task();
   task2_1->addName("project2_task1");
   Tasks* task2_2 = new Task();
   task2_2->addName("project2_task2");

   project2->addTask(task2_1);
   project2->addTask(task2_2);

   project1->addTask(project2);

   Tasks* task1_3 = new Task(); 
   task1_3->addName("project1_task3");
   Tasks* task1_4 = new Task(); 
   task1_4->addName("project1_task4");

   project1->addTask(task1_3);
   project1->addTask(task1_4);

   testing::internal::CaptureStdout();
   project1->print();
   string taskOutput = testing::internal::GetCapturedStdout();

   std::ostringstream output;
   output << "Project: project1" << std::endl;
   output << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Task: project1_task1" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Task: project1_task2" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Project: project2" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "\t" << "Task: project2_task1" << std::endl;
   output << "\t" << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "\t" << "Task: project2_task2" << std::endl;
   output << "\t" << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Task: project1_task3" << std::endl; 
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;  
   output << "\t" << "Task: project1_task4" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;

   EXPECT_EQ(taskOutput, output.str());
}

TEST(ProjectClassRemove, RemoveTask) {
   Tasks* project1 = new Project();
   project1->addName("project1");

   Tasks* task1_1 = new Task();
   task1_1->addName("project1_task1");
   Tasks* task1_2 = new Task();
   task1_2->addName("project1_task2");

   project1->addTask(task1_1);
   project1->addTask(task1_2);

   Tasks* project2 = new Project();
   project2->addName("project2");

   Tasks* task2_1 = new Task();
   task2_1->addName("project2_task1");
   Tasks* task2_2 = new Task();
   task2_2->addName("project2_task2");

   project2->addTask(task2_1);
   project2->addTask(task2_2);

   project1->addTask(project2);

   project1->removeTask(task1_1); 

   testing::internal::CaptureStdout();
   project1->print();
   string taskOutput = testing::internal::GetCapturedStdout();

   std::ostringstream output;
   output << "Project: project1" << std::endl;
   output << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Task: project1_task2" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Project: project2" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "\t" << "Task: project2_task1" << std::endl;
   output << "\t" << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "\t" << "Task: project2_task2" << std::endl;
   output << "\t" << "\t" << "Status: NOT FINISHED" << std::endl;

   EXPECT_EQ(taskOutput, output.str());
}

TEST(ProjectClassRemove, RemoveProject) {
   Tasks* project1 = new Project();
   project1->addName("project1");

   Tasks* task1_1 = new Task();
   task1_1->addName("project1_task1");
   Tasks* task1_2 = new Task();
   task1_2->addName("project1_task2");

   project1->addTask(task1_1);
   project1->addTask(task1_2);

   Tasks* project2 = new Project();
   project2->addName("project2");

   Tasks* task2_1 = new Task();
   task2_1->addName("project2_task1");
   Tasks* task2_2 = new Task();
   task2_2->addName("project2_task2");

   project2->addTask(task2_1);
   project2->addTask(task2_2);

   project1->addTask(project2);

   project1->removeTask(project2);

   testing::internal::CaptureStdout();
   project1->print();
   string taskOutput = testing::internal::GetCapturedStdout();

   std::ostringstream output;
   output << "Project: project1" << std::endl;
   output << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Task: project1_task1" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl; 
   output << std::endl; 
   output << "\t" << "Task: project1_task2" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
  
   EXPECT_EQ(taskOutput, output.str());
}

TEST(ProjectClassRemove, RemoveTaskAfterProject) {
     Tasks* project1 = new Project();
   project1->addName("project1");

   Tasks* task1_1 = new Task();
   task1_1->addName("project1_task1");
   Tasks* task1_2 = new Task();
   task1_2->addName("project1_task2");

   project1->addTask(task1_1);
   project1->addTask(task1_2);

   Tasks* project2 = new Project();
   project2->addName("project2");

   Tasks* task2_1 = new Task();
   task2_1->addName("project2_task1");
   Tasks* task2_2 = new Task();
   task2_2->addName("project2_task2");

   project2->addTask(task2_1);
   project2->addTask(task2_2);

   project1->addTask(project2);

   Tasks* task1_3 = new Task();
   task1_3->addName("project1_task3");
   Tasks* task1_4 = new Task();
   task1_4->addName("project1_task4");

   project1->addTask(task1_3);
   project1->addTask(task1_4);

   project1->removeTask(task1_3);

   testing::internal::CaptureStdout();
   project1->print();
   string taskOutput = testing::internal::GetCapturedStdout();

   std::ostringstream output;
   output << "Project: project1" << std::endl;
   output << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Task: project1_task1" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Task: project1_task2" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Project: project2" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "\t" << "Task: project2_task1" << std::endl;
   output << "\t" << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "\t" << "Task: project2_task2" << std::endl;
   output << "\t" << "\t" << "Status: NOT FINISHED" << std::endl;
   output << std::endl;
   output << "\t" << "Task: project1_task4" << std::endl;
   output << "\t" << "Status: NOT FINISHED" << std::endl;

   EXPECT_EQ(taskOutput, output.str());

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
