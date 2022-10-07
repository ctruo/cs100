#include "gtest/gtest.h"
#include "menu.cpp"
#include "../taskcommandsheader/taskcommand.hpp"
#include "mocks/ConcreteCommand1Mock.hpp"
#include "mocks/ConcreteCommand2Mock.hpp"

TEST(GeneralMenu, Output){

Menu* test = new Menu();

testing::internal::CaptureStdout();
test->generalMenu();
std::string test_output = testing::internal::GetCapturedStdout();

std::ostringstream out;
out << std::endl;
out << "TASK SCHEDULER" << std::endl;
out << "a- add simple task" << std::endl;
out << "p- add project" << std::endl;
out << "o- print my list" << std::endl;
out << "e- edit task" << std::endl;
out << "q- quit" << std::endl;
EXPECT_EQ(test_output,out.str());
}

TEST(SimpleMenu, Output){

Menu* test = new Menu();

testing::internal::CaptureStdout();
test->simpleMenu();
std::string test_output = testing::internal::GetCapturedStdout();

std::ostringstream out;
out <<  std::endl;
out << "d- description" << std::endl;
out << "t- deadline"<< std::endl;
out << "b- status" << std::endl;
out << "q- I'm done entering info" << std::endl;
EXPECT_EQ(test_output, out.str());
}

TEST(ComplexMenu, Output){

Menu* test = new Menu();

testing::internal::CaptureStdout();
test->complexMenu();
std::string test_output = testing::internal::GetCapturedStdout();

std::ostringstream out;
out <<  std::endl;
out << "d- description" << std::endl;
out << "t- deadline"<< std::endl;
out << "b- status" << std::endl;
out << "c- project subtask" << std::endl;
out << "s- simple subtask" << std::endl;
out << "q- I'm done entering info" << std::endl;
EXPECT_EQ(test_output, out.str());
}

TEST(EditMenu, Output){

Menu* test = new Menu();

testing::internal::CaptureStdout();
test->editMenu();
std::string test_output = testing::internal::GetCapturedStdout();

std::ostringstream out;
out << std::endl;
out << "en- edit name" << std::endl;
out << "ed- edit description" << std::endl;
out << "et- edit deadline" << std::endl;
out << "eb- change status" << std:: endl;
out << "q- I'm done entering info" << std::endl;
EXPECT_EQ(test_output, out.str());
}
TEST(UserInput, word){

    Menu* test = new Menu();

    test->setUserInput("normal");
    EXPECT_EQ(test->UserInput(), "normal");
}

TEST(UserInput, character){

    Menu* test = new Menu();

    test->setUserInput("a");
    EXPECT_EQ(test->UserInput(), "a");
}

TEST(UserInput, phrase){

    Menu* test = new Menu();

    test->setUserInput("A dime a dozen");
    EXPECT_EQ(test->UserInput(), "A dime a dozen");
}

TEST(SetterGetterTaskCommand, ConcreteCommand1){

    Menu* test = new Menu();
    TaskCommand* taskcommand = new ConcreteCommand1Mock();
   
    test->setCommand(taskcommand);
    EXPECT_EQ(test->Command(), taskcommand); 
}

TEST(SetterGetterTaskCommand, ConcreteCommand2){

    Menu* test = new Menu();
    TaskCommand* taskcommand = new ConcreteCommand2Mock();

    test->setCommand(taskcommand);
    EXPECT_EQ(test->Command(), taskcommand);
}

TEST(ExecuteCommand, ConcreteCommand1){

    Menu* test = new Menu();
    TaskCommand* taskcommand = new ConcreteCommand1Mock();

    test->setCommand(taskcommand);    

    testing::internal::CaptureStdout();
    test->ExecuteCommand();
    std::string test_output = testing::internal::GetCapturedStdout();

    std::ostringstream out;
    out << "ConcreteCommand1Mock executed" << std::endl;
    EXPECT_EQ(test_output, out.str());

}

TEST(ExecuteCommand, ConcreteCommand2){

    Menu* test = new Menu();
    TaskCommand* taskcommand = new ConcreteCommand2Mock();

    test->setCommand(taskcommand);

    testing::internal::CaptureStdout();
    test->ExecuteCommand();
    std::string test_output = testing::internal::GetCapturedStdout();

    std::ostringstream out;
    out << "ConcreteCommand2Mock executed" << std::endl;
    EXPECT_EQ(test_output, out.str());

}

TEST(UnexecuteCommand, ConcreteCommand1){

    Menu* test = new Menu();
    TaskCommand* taskcommand = new ConcreteCommand1Mock();

    test->setCommand(taskcommand);

    testing::internal::CaptureStdout();
    test->UnexecuteCommand();
    std::string test_output = testing::internal::GetCapturedStdout();

    std::ostringstream out;
    out << "ConcreteCommand1Mock unexecuted" << std::endl;
    EXPECT_EQ(test_output, out.str());

}

TEST(UnexecuteCommand, ConcreteCommand2){

    Menu* test = new Menu();
    TaskCommand* taskcommand = new ConcreteCommand2Mock();

    test->setCommand(taskcommand);

    testing::internal::CaptureStdout();
    test->UnexecuteCommand();
    std::string test_output = testing::internal::GetCapturedStdout();

    std::ostringstream out;
    out << "ConcreteCommand2Mock unexecuted" << std::endl;
    EXPECT_EQ(test_output, out.str());

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
//menu_test.hpp
