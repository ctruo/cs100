#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"

TEST(DivTest, DivEvaluateNonZero){
    Op* val1 = new Op(9);
    Op* val2 = new Op(3);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->evaluate(), 3);
    delete val1;
    delete val2;
    delete test;
}

TEST(DivTest, DivStringifyNonZero){
    Op* val1 = new Op(3);
    Op* val2 = new Op(5);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->stringify(), "(3.000000/5.000000)");
    delete val1;
    delete val2;
    delete test;
}

TEST(DivTest, DivEvaluateNeg){
    Op* val1 = new Op(5);
    Op* val2 = new Op(-5);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->evaluate(), -1);
    delete val1;
    delete val2;
    delete test;
}

TEST(DivTest, DivStringifyNeg){
    Op* val1 = new Op(-8);
    Op* val2 = new Op(2);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->stringify(), "(-8.000000/2.000000)");
    delete val1;
    delete val2;
    delete test;
}

TEST(DivTest, DivEvaluateZero){
    Op* val1 = new Op(0);
    Op* val2 = new Op(1);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->evaluate(), 0);
    delete val1;
    delete val2;
    delete test;
}

TEST(DivTest, DivStringifyZero){
    Op* val1 = new Op(0);
    Op* val2 = new Op(5);
    Div* test = new Div(val1, val2);
    EXPECT_EQ(test->stringify(), "(0.000000/5.000000)");
    delete val1;
    delete val2;
    delete test;
}

TEST(DivTest, DivEvaluatePowParam){
    Op* val1 = new Op(2);
    Op* val2 = new Op(5);
    Pow* powVal = new Pow(val1, val2);
    Div* test = new Div(powVal, val1);
    EXPECT_EQ(test->evaluate(), 16);
    delete val1;
    delete val2;
    delete test;
    delete powVal;
}

TEST(DivTest, DivStringifyPowParam){
    Op* val1 = new Op(3);
    Op* val2 = new Op(4);
    Pow* powVal = new Pow(val1, val2);
    Div* test = new Div(powVal, val2);
    EXPECT_EQ(test->stringify(), "((3.000000**4.000000)/4.000000)");
    delete val1;
    delete val2;
    delete test;
    delete powVal;
}

TEST(DivTest, number_of_children){
	Op* op1 = new Op(5);
        Op* op2 = new Op(7);
        Div* test = new Div(op1, op2);
	EXPECT_EQ(test->number_of_children(), 2);
	delete op1;
	delete op2;
        delete test;
}

TEST(DivTest, get_child_0){
	Op* op1 = new Op(3);
        Op* op2 = new Op(2);
        Div* test = new Div(op1, op2);
        EXPECT_EQ(test->get_child(0), op1);
        delete op1;
        delete op2;
        delete test;
}

TEST(DivTest, get_child_1){
        Op* op1 = new Op(4);
        Op* op2 = new Op(2);
        Div* test = new Div(op1, op2);
        EXPECT_EQ(test->get_child(1), op2);
        delete op1;
        delete op2;
        delete test;
}

#endif

