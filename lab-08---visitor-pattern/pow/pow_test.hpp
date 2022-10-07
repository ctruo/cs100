#ifndef __POW_TEST_HPP
#define __POW_TEST_HPP

#include "gtest/gtest.h"

#include "pow.hpp"

TEST(PowTest, PowEvaluateMultParam) {
        Op* op1 = new Op(3);
        Op* op2 = new Op(2);
	Mult* mult = new Mult(op1, op2);
        Pow* test = new Pow(op2, mult);
        EXPECT_EQ(test->evaluate(), 64);
        delete op1;
        delete op2;
        delete test;
        delete mult;
}

TEST(PowTest, PowStringifyMultParam) {
        Op* op1 = new Op(3);
        Op* op2 = new Op(2);
        Mult* mult = new Mult(op1, op2);
        Pow* test = new Pow(op2, mult);
        EXPECT_EQ(test->stringify(), "(2.000000**(3.000000*2.000000))");
        delete op1;
        delete op2;
        delete test;
        delete mult;
}


TEST(PowTest, PowEvaluateNonZero) {
	Op* op1 = new Op(3);
	Op* op2 = new Op(2);
	Pow* test = new Pow(op1, op2);
	EXPECT_EQ(test->evaluate(), 9);
        delete op1;
        delete op2;
        delete test;
}

TEST(PowTest, PowStringifyNonZero) {
	Op* op1 = new Op(3);
	Op* op2 = new Op(2);
	Pow* test = new Pow(op1, op2);
	EXPECT_EQ(test->stringify(), "(3.000000**2.000000)");
        delete op1;
        delete op2;
        delete test;
}

TEST(PowTest, PowEvaluateNeg) {
        Op* op1 = new Op(-2);
        Op* op2 = new Op(3);
        Pow* test = new Pow(op1, op2);
        EXPECT_EQ(test->evaluate(), -8);
        delete op1;
        delete op2;
        delete test;
}

TEST(PowTest, PowStringifyNeg) {
        Op* op1 = new Op(-2);
        Op* op2 = new Op(3);
        Pow* test = new Pow(op1, op2);
        EXPECT_EQ(test->stringify(), "(-2.000000**3.000000)");
        delete op1;
        delete op2;
        delete test;
} 

TEST(PowTest, PowEvaluateZero) {
        Op* op1 = new Op(5);
        Op* op2 = new Op(0);
        Pow* test = new Pow(op1, op2);
        EXPECT_EQ(test->evaluate(), 1);
        delete op1;
        delete op2;
        delete test;
}

TEST(PowTest, PowStringifyZero) {
        Op* op1 = new Op(5);
        Op* op2 = new Op(0);
        Pow* test = new Pow(op1, op2);
        EXPECT_EQ(test->stringify(), "(5.000000**0.000000)");
        delete op1;
        delete op2;
        delete test;
}

TEST(PowTest, number_of_children){
	Op* op1 = new Op(5);
        Op* op2 = new Op(7);
        Pow* test = new Pow(op1, op2);
	EXPECT_EQ(test->number_of_children(), 2);
	delete op1;
	delete op2;
        delete test;
}

TEST(PowTest, get_child_0){
	Op* op1 = new Op(3);
        Op* op2 = new Op(2);
        Pow* test = new Pow(op1, op2);
        EXPECT_EQ(test->get_child(0), op1);
        delete op1;
        delete op2;
        delete test;
}

TEST(PowTest, get_child_1){
        Op* op1 = new Op(2);
        Op* op2 = new Op(4);
        Pow* test = new Pow(op1, op2);
        EXPECT_EQ(test->get_child(1), op2);
        delete op1;
        delete op2;
        delete test;
}
#endif
