#include "gtest/gtest.h"

#include "Tasks/Tasks.hpp"
#include "taskmock/TaskMock.hpp"
#include "taskmock/ProjectMock.hpp" 

#include "Strategyheaders/Prioritize.hpp"
#include "prioritizemock/CompletedMock.hpp"
#include "prioritizemock/SchedulerMock.hpp"

#include "taskcommandsheader/taskcommand.hpp"
#include "taskcommandsheader/addtask.hpp" 
#include "taskcommandsheader/changetaskname.hpp"
#include "taskcommandsheader/changetaskdeadline.hpp"
#include "taskcommandsheader/changetaskstatus.hpp"
#include "taskcommandsheader/changetaskdescription.hpp"
#include "taskcommandsheader/printTasks.hpp"

TEST(TaskCommands, printTasks) {
    Tasks* myTask = new TaskMock(); 

    Tasks* myTask2 = new ProjectMock(); 

    Prioritize* myStrat = new CompletedMock(myTask); 
    TaskCommand* myCommand = new printTasks(myStrat);

    myCommand->execute();

    Prioritize* myStrat2 = new SchedulerMock(myTask2); 
    TaskCommand* myCommand2 = new printTasks(myStrat2);
	
    myCommand2->execute();

    EXPECT_EQ(myTask->getTestVar(), -1);  
    EXPECT_EQ(myTask2->getTestVar(), 1); 
}

TEST(TaskCommands, changetaskdeadline) {
    Tasks* myTask = new TaskMock();

    TaskCommand* myCommand = new changetaskdeadline(myTask, "deadline");

    myCommand->execute();

    EXPECT_EQ(myTask->getTestVar(), 2);
}

TEST(TaskCommands, changetaskstatus) {
    Tasks* myTask = new TaskMock();

    TaskCommand* myCommand = new changetaskstatus(myTask, false);

    myCommand->execute();

    EXPECT_EQ(myTask->getTestVar(), 3);
}

TEST(TaskCommands, changetaskdescription) {
    Tasks* myTask = new TaskMock();

    TaskCommand* myCommand = new changetaskdescription(myTask, "description");

    myCommand->execute();

    EXPECT_EQ(myTask->getTestVar(), 4);
}

TEST(TaskCommands, changetaskname) {
    Tasks* myTask = new TaskMock();

    TaskCommand* myCommand = new changetaskname(myTask, "name");

    myCommand->execute();

    EXPECT_EQ(myTask->getTestVar(), 5);
}

TEST(TaskCommands, addtask) {
    Tasks* myProject = new ProjectMock();
    Tasks* myTask = new TaskMock();  

    TaskCommand* myCommand = new addtask(myTask, myProject);

    myCommand->execute(); 

    EXPECT_EQ(myProject->getTestVar(), 6); 
}

TEST(TaskCommands, addtaskUNDO) {
    Tasks* myProject = new ProjectMock(); 
    Tasks* myTask = new TaskMock(); 

    TaskCommand* myCommand = new addtask(myTask, myProject); 

    myCommand->unexecute(); 

    EXPECT_EQ(myProject->getTestVar(), 7);
}

TEST(TaskCommands, changetaskdeadlineUNDO) {
    Tasks* myTask = new TaskMock(); 
    Tasks* myProject = new ProjectMock(); 

    TaskCommand* myCommand = new changetaskdeadline(myTask); 
    myCommand->unexecute();
    EXPECT_EQ(myTask->getTestVar(), 2);
    
    myCommand = new changetaskdeadline(myProject); 
    myCommand->unexecute(); 
    EXPECT_EQ(myTask->getTestVar(), 2); 
}

TEST(TaskCommands, changetaskdescriptionUNDO) {
    Tasks* myTask = new TaskMock();
    Tasks* myProject = new ProjectMock();

    TaskCommand* myCommand = new changetaskdescription(myTask);
    myCommand->unexecute();
    EXPECT_EQ(myTask->getTestVar(), 4);

    myCommand = new changetaskdescription(myProject);
    myCommand->unexecute();
    EXPECT_EQ(myTask->getTestVar(), 4);
} 

TEST(TaskCommands, changetaskstatusUNDO) {
    Tasks* myTask = new TaskMock();
    Tasks* myProject = new ProjectMock();

    TaskCommand* myCommand = new changetaskstatus(myTask);
    myCommand->unexecute();
    EXPECT_EQ(myTask->getTestVar(), 3);

    myCommand = new changetaskstatus(myProject);
    myCommand->unexecute();
    EXPECT_EQ(myTask->getTestVar(), 3);
}


TEST(TaskCommands, mixcommandsone) {
    Tasks* myTask = new TaskMock();
    TaskCommand* myCommand = new changetaskname(myTask, "name");
    myCommand->execute();
    EXPECT_EQ(myTask->getTestVar(), 5);

    myCommand = new changetaskstatus(myTask, false); 
    myCommand->execute(); 
    EXPECT_EQ(myTask->getTestVar(), 3);
}

TEST(TaskCommands, mixcommandstwo) {
    Tasks* myProject = new ProjectMock();
    Tasks* myTask = new TaskMock();

    TaskCommand* myCommand1 = new addtask(myTask, myProject);

    myCommand1->execute();

    TaskCommand* myCommand2 = new changetaskdescription(myTask, "description");
    
    myCommand2->execute(); 

    EXPECT_EQ(myProject->getTestVar(), 6); 
    EXPECT_EQ(myTask->getTestVar(), 4);    
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
