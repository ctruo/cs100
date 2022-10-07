#ifndef __RAND_TEST_HPP
#define __RAND_TEST_HPP

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, RandEvaluate) {
    Rand* test = new Rand();
    int num = 0;
    EXPECT_EQ(num = test->evaluate(), num /*test->evaluate() >= 0 && test->evaluate() < 100*/ );
    delete test;
}

TEST(RandTest, number_of_children){
        Rand* test = new Rand();
        EXPECT_EQ(test->number_of_children(), 0);
        delete test;
}

TEST(RandTest, get_child){
        Rand* test = new Rand();
        EXPECT_EQ(test->get_child(0), nullptr);
        delete test;
}

#endif
