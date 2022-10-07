#ifndef __ADD_TEST_HPP
#define __ADD_TEST_HPP

#include "gtest/gtest.h"

#include "add.hpp"

TEST(AddTest, AddEvaluateNonZero) {
	Op* op1 = new Op(4);
	Op* op2 = new Op(5);
	Add* test = new Add(op1, op2);
	EXPECT_EQ(test->evaluate(), 9);
}

TEST(AddTest, AddStringifyNonZero) {
	Op* op1 = new Op(5);
	Op* op2 = new Op(7);
	Add* test = new Add(op1, op2);
	EXPECT_EQ(test->stringify(), "(5.000000+7.000000)");
}

TEST(AddTest, AddEvaluateNeg) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(5);
        Add* test = new Add(op1, op2);
        EXPECT_EQ(test->evaluate(), 1);
}

TEST(AddTest, AddStringifyNeg) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(5);
        Add* test = new Add(op1, op2);
        EXPECT_EQ(test->stringify(), "(-4.000000+5.000000)");
}

TEST(AddTest, AddEvaluateZero) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(4);
        Add* test = new Add(op1, op2);
        EXPECT_EQ(test->evaluate(), 0);
}

TEST(AddTest, AddStringifyZero) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(4);
        Add* test = new Add(op1, op2);
        EXPECT_EQ(test->stringify(), "(-4.000000+4.000000)");
}
#endif
