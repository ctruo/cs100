#ifndef __ADD_TEST_HPP
#define __ADD_TEST_HPP

#include "gtest/gtest.h"

#include "add.hpp"

TEST(AddTest, AddEvaluateNonZero) {
	Op* op1 = new Op(4);
	Op* op2 = new Op(5);
	Add* test = new Add(op1, op2);
	EXPECT_EQ(test->evaluate(), 9);
        delete op1;
        delete op2;
        delete test;
}

TEST(AddTest, AddStringifyNonZero) {
	Op* op1 = new Op(5);
	Op* op2 = new Op(7);
	Add* test = new Add(op1, op2);
 	EXPECT_EQ(test->stringify(), "(5.000000+7.000000)");
        delete op1;
        delete op2;
        delete test;
}

TEST(AddTest, AddEvaluateNeg) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(5);
        Add* test = new Add(op1, op2);
        EXPECT_EQ(test->evaluate(), 1);
        delete op1;
        delete op2;
        delete test;
}

TEST(AddTest, AddStringifyNeg) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(5);
        Add* test = new Add(op1, op2);
        EXPECT_EQ(test->stringify(), "(-4.000000+5.000000)");
        delete op1;
        delete op2;
        delete test;
}


TEST(AddTest, AddEvaluateZero) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(4);
        Add* test = new Add(op1, op2);
        EXPECT_EQ(test->evaluate(), 0);
        delete op1;
        delete op2;
        delete test;
}

TEST(AddTest, AddStringifyZero) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(4);
        Add* test = new Add(op1, op2);
        EXPECT_EQ(test->stringify(), "(-4.000000+4.000000)");
        delete op1;
        delete op2;
        delete test;
}

TEST(AddTest, number_of_children){
	Op* op1 = new Op(5);
        Op* op2 = new Op(7);
        Add* test = new Add(op1, op2);
	EXPECT_EQ(test->number_of_children(), 2);
	delete op1;
	delete op2;
        delete test;
}

TEST(AddTest, get_child_0){
	Op* op1 = new Op(3);
        Op* op2 = new Op(2);
        Add* test = new Add(op1, op2);
        EXPECT_EQ(test->get_child(0), op1);
        delete op1;
        delete op2;
        delete test;
}

TEST(AddTest, get_child_1){
        Op* op1 = new Op(2);
        Op* op2 = new Op(7);
        Add* test = new Add(op1, op2);
        EXPECT_EQ(test->get_child(1), op2);
        delete op1;
        delete op2;
        delete test;
}

#endif
