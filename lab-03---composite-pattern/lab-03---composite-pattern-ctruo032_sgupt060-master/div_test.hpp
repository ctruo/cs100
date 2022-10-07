#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"

TEST(DivTest, DivEvaluateNonZero){
    Op* val1 = new Op(9);
    Op* val2 = new Op(3);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->evaluate(), 3);
}

TEST(DivTest, DivStringifyNonZero){
    Op* val1 = new Op(3);
    Op* val2 = new Op(5);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->stringify(), "(3.000000/5.000000)");
}

TEST(DivTest, DivEvaluateNeg){
    Op* val1 = new Op(5);
    Op* val2 = new Op(-5);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->evaluate(), -1);
}

TEST(DivTest, DivStringifyNeg){
    Op* val1 = new Op(-8);
    Op* val2 = new Op(2);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->stringify(), "(-8.000000/2.000000)");
}

TEST(DivTest, DivEvaluateZero){
    Op* val1 = new Op(0);
    Op* val2 = new Op(1);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivStringifyZero){
    Op* val1 = new Op(0);
    Op* val2 = new Op(5);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->stringify(), "(0.000000/5.000000)");
}

TEST(DivTest, DivEvaluatePowParam){
    Op* val1 = new Op(2);
    Op* val2 = new Op(5);
    Pow* powVal = new Pow(val1, val2);
    Div* test = new Div(powVal, val1);
    EXPECT_EQ(test->evaluate(), 16);
}

TEST(DivTest, DivStringifyPowParam){
    Op* val1 = new Op(3);
    Op* val2 = new Op(4);
    Pow* powVal = new Pow(val1, val2);
    Div* test = new Div(powVal, val2);
    EXPECT_EQ(test->stringify(), "((3.000000**4.000000)/4.000000)");
}

#endif


