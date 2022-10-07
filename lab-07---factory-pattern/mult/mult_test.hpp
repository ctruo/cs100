#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"

TEST(MultTest, MultEvaluateNonZero){
    Op* val1 = new Op(5);
    Op* val2 = new Op(8);
    Mult* test = new Mult(val1, val2);
    EXPECT_EQ(test->evaluate(), 40);
    delete val1;
    delete val2;
    delete test;
}

TEST(MultTest, MultStringifyNonZero){
    Op* val1 = new Op(2);
    Op* val2 = new Op(7);
    Mult* test = new Mult(val1, val2);
    EXPECT_EQ(test->stringify(), "(2.000000*7.000000)");
    delete val1;
    delete val2;
    delete test;
}

TEST(MultTest, MultEvaluateNeg){
    Op* val1 = new Op(-3);
    Op* val2 = new Op(4);
    Mult* test = new Mult(val1, val2);
    EXPECT_EQ(test->evaluate(), -12);
    delete val1;
    delete val2;
    delete test;
}

TEST(MultTest, MultStringifyNeg){
    Op* val1 = new Op(4);
    Op* val2 = new Op(-9);
    Mult* test = new Mult(val1, val2);
    EXPECT_EQ(test->stringify(), "(4.000000*-9.000000)");
    delete val1;
    delete val2;
    delete test;
}

TEST(MultTest, MultEvaluateZero){
    Op* val1 = new Op(0);
    Op* val2 = new Op(5);
    Mult* test = new Mult(val1, val2);
    EXPECT_EQ(test->evaluate(), 0);
    delete val1;
    delete val2;
    delete test;
}

TEST(MultTest, MultStringifyZero){
    Op* val1 = new Op(6);
    Op* val2 = new Op(0);
    Mult* test = new Mult(val1, val2);
    EXPECT_EQ(test->stringify(), "(6.000000*0.000000)");
    delete val1;
    delete val2;
    delete test;
}

TEST(MultTest, MultEvaluateSubParam){
    Op* val1 = new Op(-6);
    Op* val2 = new Op(-7);
    Sub* subVal = new Sub(val1, val2);
    Mult* test = new Mult(subVal, val2);
    EXPECT_EQ(test->evaluate(), -7);
    delete val1;
    delete subVal;
    delete val2;
    delete test;
}

TEST(MultTest, MultStringifySubParam){
    Op* val1 = new Op(-5);
    Op* val2 = new Op(-8);
    Sub* subVal = new Sub(val1, val2);
    Mult* test = new Mult(subVal, val2);
    EXPECT_EQ(test->stringify(), "((-5.000000--8.000000)*-8.000000)");
    delete val1;
    delete subVal;
    delete val2;
    delete test;
}

#endif
