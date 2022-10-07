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
        delete op1;
        delete op2;
        delete add;
        delete test;
}

TEST(SubTest, SubStringifyAddParam) {
        Op* op1 = new Op(7);
        Op* op2 = new Op(5);
        Add* add = new Add(op1, op2);
        Sub* test = new Sub(add, op1);
        EXPECT_EQ(test->stringify(), "((7.000000+5.000000)-7.000000)");
        delete op1;
        delete op2;
        delete add;
        delete test;
}


TEST(SubTest, SubEvaluateNonZero) {
	Op* op1 = new Op(7);
	Op* op2 = new Op(5);
	Sub* test = new Sub(op1, op2);
	EXPECT_EQ(test->evaluate(), 2);
        delete op1;
        delete op2;
        delete test;
}

TEST(SubTest, SubStringifyNonZero) {
	Op* op1 = new Op(7);
	Op* op2 = new Op(5);
	Sub* test = new Sub(op1, op2);
	EXPECT_EQ(test->stringify(), "(7.000000-5.000000)");
        delete op1;
        delete op2;
        delete test;
}

TEST(SubTest, SubEvaluateNeg) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(-5);
        Sub* test = new Sub(op1, op2);
        EXPECT_EQ(test->evaluate(), 1);
        delete op1;
        delete op2;
        delete test;
}

TEST(SubTest, SubStringifyNeg) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(-5);
        Sub* test = new Sub(op1, op2);
        EXPECT_EQ(test->stringify(), "(-4.000000--5.000000)");
        delete op1;
        delete op2;
        delete test;
}

TEST(SubTest, SubEvaluateZero) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(-4);
        Sub* test = new Sub(op1, op2);
        EXPECT_EQ(test->evaluate(), 0);
        delete op1;
        delete op2;
        delete test;
}

TEST(SubTest, SubStringifyZero) {
        Op* op1 = new Op(-4);
        Op* op2 = new Op(-4);
        Sub* test = new Sub(op1, op2);
        EXPECT_EQ(test->stringify(), "(-4.000000--4.000000)");
        delete op1;
        delete op2;
        delete test;
}
#endif
