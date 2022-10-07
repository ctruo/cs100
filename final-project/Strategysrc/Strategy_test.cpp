#include "gtest/gtest.h"
#include "../Strategyheaders/Scheduler.hpp"
#include "../Strategyheaders/Completed.hpp"
#include "../Task/Task.hpp"
#include "../Project/Project.hpp"
#include <sstream>
//using namespace std::endl;
TEST(SchedulerSort, Test1){
     Project* p1 = new Project();p1->addName("project1");
     	Tasks* m2 = new Task(); m2->addName("project1_task1"); m2->addDeadline("12/27/21");p1->addTask(m2);
	Tasks* m3 = new Task(); m3->addName("project1_task2"); p1->addTask(m3);
/*	Tasks* m4 = new Task(); m4->addName("project_1_task4"); p1->addTask(m4);
	Tasks* m1 = new Task(); m1->addName("project_1_task1"); m1->addDeadline("11/28/21");p1->addTask(m1);
	Project* p2 = new Project(); p2->addName("project1_project2"); p2->addDeadline("12/12/60"); p1->addTask(p2);
		Tasks* m5 = new Task(); m5->addName("project2_task2"); m5->addDeadline("11/16/21");p2->addTask(m5);
		Tasks* m6 = new Task(); m6->addName("project2_task1"); m6->addDeadline("11/13/21");p2->addTask(m6);
		Project* p3 = new Project(); p3->addName("project2_project3"); p3->addDeadline("12/12/60"); p2->addTask(p3);			
			Tasks* m7 = new Task(); m7->addName("project3_task2"); p3->addTask(m7);
			Tasks* m8 = new Task(); m8->addName("project3_task1"); m8->addDeadline("01/01/11");p3->addTask(m8);
*/
testing::internal::CaptureStdout();
(new Scheduler(p1))->sort()->print();
std::string test_output = testing::internal::GetCapturedStdout();

std::string out =  "Project: project1\nStatus: NOT FINISHED\n\n\tTask: project1_task1\n\tDeadline: 12/27/21\n\tStatus: NOT FINISHED\n\n\tTask: project1_task2\n\tStatus: NOT FINISHED\n";
EXPECT_EQ(out, test_output);
}
TEST(SchedulerSort, Test2){
     Project* p1 = new Project();p1->addName("project1");
        Tasks* m2 = new Task(); m2->addName("project1_task1"); m2->addDeadline("12/27/21");p1->addTask(m2); m2->setStatus(true);
        Tasks* m3 = new Task(); m3->addName("project1_task2"); p1->addTask(m3);
      Tasks* m4 = new Task(); m4->addName("project_1_task4"); p1->addTask(m4);m4->setStatus(true);
               Tasks* m1 = new Task(); m1->addName("project_1_task1"); m1->addDeadline("11/28/21");p1->addTask(m1);
 /*                      Project* p2 = new Project(); p2->addName("project1_project2"); p2->addDeadline("12/12/60"); p1->addTask(p2);
*                                      Tasks* m5 = new Task(); m5->addName("project2_task2"); m5->addDeadline("11/16/21");p2->addTask(m5);
 *                                                      Tasks* m6 = new Task(); m6->addName("project2_task1"); m6->addDeadline("11/13/21");p2->addTask(m6);
 *                                                                      Project* p3 = new Project(); p3->addName("project2_project3"); p3->addDeadline("12/12/60"); p2->addTask(p3);
 *                                                                                              Tasks* m7 = new Task(); m7->addName("project3_task2"); p3->addTask(m7);
 *                                                                                                                      Tasks* m8 = new Task(); m8->addName("project3_task1"); m8->addDeadline("01/01/11");p3->addTask(m8);
 *                                                                                                                      */
testing::internal::CaptureStdout();
(new Scheduler(p1))->sort()->print();
std::string test_output = testing::internal::GetCapturedStdout();

std::string out = "Project: project1\nStatus: NOT FINISHED\n\n\tTask: project1_task1\n\tDeadline: 12/27/21\n\tStatus: FINISHED\n\n\tTask: project1_task2\n\tStatus: NOT FINISHED\n\n\tTask: project_1_task4\n\tStatus: FINISHED\n\n\tTask: project_1_task1\n\tDeadline: 11/28/21\n\tStatus: NOT FINISHED\n"; 
EXPECT_EQ(out, test_output);
}
TEST(CompletedSort, Test1){
     Project* p1 = new Project();p1->addName("project1"); p1->setStatus(true);
        Tasks* m2 = new Task(); m2->addName("project1_task1"); m2->addDeadline("12/27/21");p1->addTask(m2);
        Tasks* m3 = new Task(); m3->addName("project1_task2"); p1->addTask(m3);
      Tasks* m4 = new Task(); m4->addName("project_1_task4"); p1->addTask(m4); m4->setStatus(true);
               Tasks* m1 = new Task(); m1->addName("project_1_task1"); m1->addDeadline("11/28/21");p1->addTask(m1);
 /*                      Project* p2 = new Project(); p2->addName("project1_project2"); p2->addDeadline("12/12/60"); p1->addTask(p2);
 *                       *                      *                                      Tasks* m5 = new Task(); m5->addName("project2_task2"); m5->addDeadline("11/16/21");p2->addTask(m5);
 *                        *                       *                                                      Tasks* m6 = new Task(); m6->addName("project2_task1"); m6->addDeadline("11/13/21");p2->addTask(m6);
 *                         *                        *                                                                      Project* p3 = new Project(); p3->addName("project2_project3"); p3->addDeadline("12/12/60"); p2->addTask(p3);
 *                          *                         *                                                                                              Tasks* m7 = new Task(); m7->addName("project3_task2"); p3->addTask(m7);
 *                           *                          *                                                                                                                      Tasks* m8 = new Task(); m8->addName("project3_task1"); m8->addDeadline("01/01/11");p3->addTask(m8);
 *                            *                           *                                                                                                                      */
testing::internal::CaptureStdout();
(new Completed(p1))->sort()->print();
std::string test_output = testing::internal::GetCapturedStdout();

std::string out = "Project: project1\nStatus: FINISHED\n\n\tTask: project1_task1\n\tDeadline: 12/27/21\n\tStatus: NOT FINISHED\n\n\tTask: project1_task2\n\tStatus: NOT FINISHED\n\n\tTask: project_1_task1\n\tDeadline: 11/28/21\n\tStatus: NOT FINISHED\n\n\tTask: project_1_task4\n\tStatus: FINISHED\n";
EXPECT_EQ(out, test_output);
}

TEST(CompletedSort, Test2){
     Project* p1 = new Project();p1->addName("project1");
        Tasks* m2 = new Task(); m2->addName("project1_task1"); m2->addDeadline("12/27/21");p1->addTask(m2);
        Tasks* m3 = new Task(); m3->addName("project1_task2"); p1->addTask(m3);
      Tasks* m4 = new Task(); m4->addName("project_1_task4"); p1->addTask(m4);
               Tasks* m1 = new Task(); m1->addName("project_1_task1"); m1->addDeadline("11/28/21");p1->addTask(m1);
 /*                      Project* p2 = new Project(); p2->addName("project1_project2"); p2->addDeadline("12/12/60"); p1->addTask(p2);
 *                      *                                      Tasks* m5 = new Task(); m5->addName("project2_task2"); m5->addDeadline("11/16/21");p2->addTask(m5);
 *                       *                                                      Tasks* m6 = new Task(); m6->addName("project2_task1"); m6->addDeadline("11/13/21");p2->addTask(m6);
 *                        *                                                                      Project* p3 = new Project(); p3->addName("project2_project3"); p3->addDeadline("12/12/60"); p2->addTask(p3);
 *                         *                                                                                              Tasks* m7 = new Task(); m7->addName("project3_task2"); p3->addTask(m7);
 *                          *                                                                                                                      Tasks* m8 = new Task(); m8->addName("project3_task1"); m8->addDeadline("01/01/11");p3->addTask(m8);
 *                           *                                                                                                                      */
testing::internal::CaptureStdout();
(new Completed(p1))->sort()->print();
std::string test_output = testing::internal::GetCapturedStdout();

std::string out = "Project: project1\nStatus: NOT FINISHED\n\n\tTask: project1_task1\n\tDeadline: 12/27/21\n\tStatus: NOT FINISHED\n\n\tTask: project1_task2\n\tStatus: NOT FINISHED\n\n\tTask: project_1_task4\n\tStatus: NOT FINISHED\n\n\tTask: project_1_task1\n\tDeadline: 11/28/21\n\tStatus: NOT FINISHED\n";
EXPECT_EQ(out, test_output);
}
TEST(PrioritizeSort, Test1){
     Project* p1 = new Project();p1->addName("project1");
        Tasks* m2 = new Task(); m2->addName("project1_task1"); m2->addDeadline("12/27/21");p1->addTask(m2);
        Tasks* m3 = new Task(); m3->addName("project1_task2"); p1->addTask(m3);
/*      Tasks* m4 = new Task(); m4->addName("project_1_task4"); p1->addTask(m4);
 *              Tasks* m1 = new Task(); m1->addName("project_1_task1"); m1->addDeadline("11/28/21");p1->addTask(m1);
 *                      Project* p2 = new Project(); p2->addName("project1_project2"); p2->addDeadline("12/12/60"); p1->addTask(p2);
 *                                      Tasks* m5 = new Task(); m5->addName("project2_task2"); m5->addDeadline("11/16/21");p2->addTask(m5);
 *                                                      Tasks* m6 = new Task(); m6->addName("project2_task1"); m6->addDeadline("11/13/21");p2->addTask(m6);
 *                                                                      Project* p3 = new Project(); p3->addName("project2_project3"); p3->addDeadline("12/12/60"); p2->addTask(p3);
 *                                                                                              Tasks* m7 = new Task(); m7->addName("project3_task2"); p3->addTask(m7);
 *                                                                                                                      Tasks* m8 = new Task(); m8->addName("project3_task1"); m8->addDeadline("01/01/11");p3->addTask(m8);
 *                                                                                                                      */
testing::internal::CaptureStdout();
(new Prioritize(p1))->sort()->print();
std::string test_output = testing::internal::GetCapturedStdout();

std::string out = "Project: project1\nStatus: NOT FINISHED\n\n\tTask: project1_task1\n\tDeadline: 12/27/21\n\tStatus: NOT FINISHED\n\n\tTask: project1_task2\n\tStatus: NOT FINISHED\n";
EXPECT_EQ(out, test_output);
}
TEST(PrioritizeSort, Test2){
     Project* p1 = new Project();p1->addName("project1");
        Tasks* m2 = new Task(); m2->addName("project1_task1"); m2->addDeadline("12/27/21");p1->addTask(m2);
        Tasks* m3 = new Task(); m3->addName("project1_task2"); p1->addTask(m3);
      Tasks* m4 = new Task(); m4->addName("project_1_task4"); p1->addTask(m4);
              Tasks* m1 = new Task(); m1->addName("project_1_task1"); m1->addDeadline("11/28/21");p1->addTask(m1);
/*        *                      Project* p2 = new Project(); p2->addName("project1_project2"); p2->addDeadline("12/12/60"); p1->addTask(p2);
 *         *                                      Tasks* m5 = new Task(); m5->addName("project2_task2"); m5->addDeadline("11/16/21");p2->addTask(m5);
 *          *                                                      Tasks* m6 = new Task(); m6->addName("project2_task1"); m6->addDeadline("11/13/21");p2->addTask(m6);
 *           *                                                                      Project* p3 = new Project(); p3->addName("project2_project3"); p3->addDeadline("12/12/60"); p2->addTask(p3);
 *            *                                                                                              Tasks* m7 = new Task(); m7->addName("project3_task2"); p3->addTask(m7);
 *             *                                                                                                                      Tasks* m8 = new Task(); m8->addName("project3_task1"); m8->addDeadline("01/01/11");p3->addTask(m8);
 *              *                                                                                                                      */
testing::internal::CaptureStdout();
(new Prioritize(p1))->sort()->print();
std::string test_output = testing::internal::GetCapturedStdout();

std::string out ="Project: project1\nStatus: NOT FINISHED\n\n\tTask: project1_task1\n\tDeadline: 12/27/21\n\tStatus: NOT FINISHED\n\n\tTask: project1_task2\n\tStatus: NOT FINISHED\n\n\tTask: project_1_task4\n\tStatus: NOT FINISHED\n\n\tTask: project_1_task1\n\tDeadline: 11/28/21\n\tStatus: NOT FINISHED\n";
EXPECT_EQ(out, test_output);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

