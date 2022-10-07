#ifndef __SUB_TEST_HPP
#define __SUB_TEST_HPP

#include "gtest/gtest.h"

#include "sub.hpp"

TEST(SubTest, SubEvaluateAddParam) {
        Op* op1 = new Op(7);
        Op* op2 = new Op(5);
	Add* add = new Add(op1, op2);
        Sub* test = new Sub(add, op1);
        EXPECT_EQ(test->evaluate(), 5);
}

TEST(SubTest, SubStringifyAddParam) {
        Op* op1 = new Op(7);
        Op* op2 = new Op(5);
        Add* add = new Add(op1, op2);
        Sub* test = new Sub(add, op1);
        EXPECT_EQ(test->stringify(), "((7.000000+5.000000)-7.000000)");
}


TEST(SubTest, SubEvaluateNonZero) {
	Op* op1 = new Op(7);
	Op* op2 = new Op(5);
	Sub* test = new Sub(op1, op2);
	EXPECT_EQ(test->evaluate(), 2);
}

TEST(SubTest, SubStringifyNonZero) {
	Op* op1 = new Op(7);
	Op* op2 = new Op(5);
	Sub* test = new Sub(op1, op2);
	EXPECT_EQ(test->stringify(), "(7.000000-5.000000)");
}

TEST(SubTest, SubEvaluateNeg) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(-5);
        Sub* test = new Sub(op1, op2);
        EXPECT_EQ(test->evaluate(), 1);
}

TEST(SubTest, SubStringifyNeg) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(-5);
        Sub* test = new Sub(op1, op2);
        EXPECT_EQ(test->stringify(), "(-4.000000--5.000000)");
}

TEST(SubTest, SubEvaluateZero) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(-4);
        Sub* test = new Sub(op1, op2);
        EXPECT_EQ(test->evaluate(), 0);
}

TEST(SubTest, SubStringifyZero) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(-4);
        Sub* test = new Sub(op1, op2);
        EXPECT_EQ(test->stringify(), "(-4.000000--4.000000)");
}
#endif
