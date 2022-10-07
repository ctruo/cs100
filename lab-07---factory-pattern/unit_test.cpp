#include "gtest/gtest.h"

#include "factory_test.hpp"
#include "op/op_test.hpp"
#include "add/add_test.hpp"
#include "sub/sub_test.hpp"
#include "rand/rand_test.hpp"
#include "mult/mult_test.hpp"
#include "pow/pow_test.hpp"
#include "div/div_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
