#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "../mock/sevenOpMock.hpp"
#include "../mock/NegOpMock.hpp"
#include "../mock/ZeroOpMock.hpp"

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


TEST(OpTest, OpEvaluatePos) {
    SevenOpMock* test = new SevenOpMock();
    EXPECT_EQ(test->evaluate(), 7.5);
    delete test;
}

TEST(OpTest, OpEvaluateNeg) {
    NegOpMock* test = new NegOpMock();
    EXPECT_EQ(test->evaluate(), -7.5);
    delete test;
}

TEST(OpTest, OpEvaluateZero) {
    ZeroOpMock* test = new ZeroOpMock();
    EXPECT_EQ(test->evaluate(), 0);
    delete test;
}


#endif //__OP_TEST_HPP__
