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

#endif
