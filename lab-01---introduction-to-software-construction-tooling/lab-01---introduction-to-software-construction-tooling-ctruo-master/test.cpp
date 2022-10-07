#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, GoodbyeWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "goodbye"; test_val[2] = "world";
    EXPECT_EQ("goodbye world", echo(3,test_val));
}

TEST(EchoTest, YesSir) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "yes"; test_val[2] = "sir";
    EXPECT_EQ("yes sir", echo(3,test_val));
}

TEST(EchoTest, YesMam) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "yes"; test_val[2] = "mam";
    EXPECT_EQ("yes mam", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
