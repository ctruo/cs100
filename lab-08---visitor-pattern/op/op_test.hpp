#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
    delete test;
}

TEST(OpTest, OpStringifyNonZero){
    Op* test = new Op(5);
    EXPECT_EQ(test->stringify(), "5.000000");
    delete test;
}

TEST(OpTest, OpStringifyNeg){
    Op* test = new Op(-5);
    EXPECT_EQ(test->stringify(), "-5.000000");
    delete test;
}

TEST(OpTest, number_of_children){
	Op* op1 = new Op(5);
	EXPECT_EQ(op1->number_of_children(), 0);
	delete op1;
}

TEST(OpTest, get_child){
        Op* op1 = new Op(2);
        EXPECT_EQ(op1->get_child(0), nullptr);
        delete op1;
}

#endif //__OP_TEST_HPP__
