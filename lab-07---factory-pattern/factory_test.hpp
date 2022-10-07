#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"

#include "add/add.hpp"
#include "sub/sub.hpp"
#include "div/div.hpp"
#include "mult/mult.hpp"
#include "pow/pow.hpp"
#include "op/op.hpp"
#include "factory.hpp"

#include <string>


TEST(FactoryTest, SimpleAdd){
    Factory test;
    char* args[] = {"./calculator", "3", "+", "5"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(3.000000+5.000000)");
    EXPECT_EQ(op->evaluate(), 8);
    delete op;
}

TEST(FactoryTest, Add_edge_0){
    Factory test;
    char* args[] = {"./calculator", "5", "+", "0"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(5.000000+0.000000)");
    EXPECT_EQ(op->evaluate(), 5);
    delete op;
}

TEST(FactoryTest, Add_withNegative){
    Factory test;
    char* args[] = {"./calculator", "-15", "+", "-5"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(-15.000000+-5.000000)");
    EXPECT_EQ(op->evaluate(), -20);
    delete op;
}

TEST(FactoryTest, SimpleSubtract){
    Factory test;
    char* args[] = {"./calculator", "7", "-", "6"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(7.000000-6.000000)");
    EXPECT_EQ(op->evaluate(), 1);
    delete op;
}

TEST(FactoryTest, Subtract_edge_0){
    Factory test;
    char* args[] = {"./calculator", "3", "-", "3"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(3.000000-3.000000)");
    EXPECT_EQ(op->evaluate(), 0);
    delete op;
}

TEST(FactoryTest, Subract_withNegative){
    Factory test;
    char* args[] = {"./calculator", "-12", "-", "-5"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(-12.000000--5.000000)");
    EXPECT_EQ(op->evaluate(), -7);
    delete op;
}

TEST(FactoryTest, SimpleMult){
    Factory test;
    char* args[] = {"./calculator", "4", "*", "3"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(4.000000*3.000000)");
    EXPECT_EQ(op->evaluate(), 12);
    delete op;
}

TEST(FactoryTest, Mult_edge_0){
    Factory test;
    char* args[] = {"./calculator", "5", "*", "0"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(5.000000*0.000000)");
    EXPECT_EQ(op->evaluate(), 0);
    delete op;
}

TEST(FactoryTest, Mult_withNegative){
    Factory test;
    char* args[] = {"./calculator", "-12", "*", "-5"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(-12.000000*-5.000000)");
    EXPECT_EQ(op->evaluate(), 60);
    delete op;
}

TEST(FactoryTest, SimpleDiv){
    Factory test;
    char* args[] = {"./calculator", "13", "/", "2"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(13.000000/2.000000)");
    EXPECT_EQ(op->evaluate(), 6.5);
    delete op;
}

TEST(FactoryTest, Div_edge_0){
    Factory test;
    char* args[] = {"./calculator", "0", "/", "10"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(0.000000/10.000000)");
    EXPECT_EQ(op->evaluate(), 0);
    delete op;
}

TEST(FactoryTest, Div_withNegative){
    Factory test;
    char* args[] = {"./calculator", "-12", "/", "-2"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(-12.000000/-2.000000)");
    EXPECT_EQ(op->evaluate(), 6);
    delete op;
}

TEST(FactoryTest, SimplePow) {
    Factory test;
    char* args[] = {"./calculator", "2", "**", "4"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(2.000000**4.000000)");
    EXPECT_EQ(op->evaluate(), 16);
    delete op;
}

TEST(FactoryTest, Pow_withNegative) {
    Factory test;
    char* args[] = {"./calculator", "2", "**", "-1"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(2.000000**-1.000000)");
    EXPECT_EQ(op->evaluate(), 0.5);
    delete op;
}

TEST(FactoryTest, NegativeToPositivePow) {
    Factory test;
    char* args[] = {"./calculator", "-4", "**", "4"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(-4.000000**4.000000)");
    EXPECT_EQ(op->evaluate(), 256);
    delete op;
}

TEST(FactoryTest, PowFraction) {
    Factory test;
    char* args[] = {"./calculator", "0.5", "**", "2"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(0.500000**2.000000)");  
    EXPECT_EQ(op->evaluate(), 0.25);
    delete op;
}

TEST(FactoryTest, Pow_toZero) {
    Factory test;
    char* args[] = {"./calculator", "2", "**", "0"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(2.000000**0.000000)");
    EXPECT_EQ(op->evaluate(), 1);
    delete op;
}

TEST(FactoryTest, ZeroPow) {
    Factory test;
    char* args[] = {"./calculator", "0", "**", "4"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op->stringify(), "(0.000000**4.000000)");
    EXPECT_EQ(op->evaluate(), 0);
    delete op;
}

TEST(FactoryTest, AddSub){
    Factory test;
    char* args[] = {"./calculator", "10", "+", "2", "-", "5"};
    Base* op = test.parse(args, 6);
    EXPECT_EQ(op->stringify(), "((10.000000+2.000000)-5.000000)");
    EXPECT_EQ(op->evaluate(), 7);
    delete op;
}

TEST(FactoryTest, AddSub_edge_0){
    Factory test;
    char* args[] = {"./calculator", "0", "+", "0", "-", "0"};
    Base* op = test.parse(args, 6);
    EXPECT_EQ(op->stringify(), "((0.000000+0.000000)-0.000000)");
    EXPECT_EQ(op->evaluate(), 0);
    delete op;
}

TEST(FactoryTest, AddPowMult) {
    Factory test;
    char* args[] = {"./calculator", "2", "**", "3", "+", "2", "*","10"};
    Base* op = test.parse(args, 8);
    EXPECT_EQ(op->stringify(), "(((2.000000**3.000000)+2.000000)*10.000000)");
    EXPECT_EQ(op->evaluate(), 100);
    delete op;
}

TEST(FactoryTest, SubPow) {
    Factory test;
    char* args[] = {"./calculator", "5", "-", "2", "**", "3"};
    Base* op = test.parse(args, 6);
    EXPECT_EQ(op->stringify(), "((5.000000-2.000000)**3.000000)");
    EXPECT_EQ(op->evaluate(), 27);
    delete op;
}

TEST(FactoryTest, MultDiv){
    Factory test;
    char* args[] = {"./calculator", "4", "*", "5", "/", "2"};
    Base* op = test.parse(args, 6);
    EXPECT_EQ(op->stringify(), "((4.000000*5.000000)/2.000000)");
    EXPECT_EQ(op->evaluate(), 10);
    delete op;
}

TEST(FactoryTest, AddMultDiv){
    Factory test;
    char* args[] = {"./calculator", "8", "+", "2", "*", "2", "/", "5"};
    Base* op = test.parse(args, 8);
    EXPECT_EQ(op->stringify(), "(((8.000000+2.000000)*2.000000)/5.000000)");
    EXPECT_EQ(op->evaluate(), 4);
    delete op;
}

TEST(FactoryTest, AddMultDiv_edge_0){
    Factory test;
    char* args[] = {"./calculator", "0", "+", "0", "*", "0", "/", "1"};
    Base* op = test.parse(args, 8);
    EXPECT_EQ(op->stringify(), "(((0.000000+0.000000)*0.000000)/1.000000)");
    EXPECT_EQ(op->evaluate(), 0);
    delete op;
}

TEST(FactoryTest, Invalid_Add){
    Factory test;
    char* args[] = {"./calculator", "+", "5", "6"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op, nullptr);
    delete op;
}

TEST(FactoryTest, Invalid_Sub){
    Factory test;
    char* args[] = {"./calculator", "-", "10", "8"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op, nullptr);
    delete op;
}

TEST(FactoryTest, Invalid_Mult){
    Factory test;
    char* args[] = {"./calculator", "*", "3", "5"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op, nullptr);
    delete op;
}

TEST(FactoryTest, Invalid_Div){
    Factory test;
    char* args[] = {"./calculator", "/", "7", "3"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op, nullptr);
    delete op;
}

TEST(FactoryTest, Invalid_Pow) {
    Factory test;
    char* args[] = {"./calculator", "**", "7", "3"};
    Base* op = test.parse(args, 4);
    EXPECT_EQ(op, nullptr);
    delete op;
}

TEST(FactoryTest, Invalid_Size) {
    Factory test;
    char* args[] = {"./calculator", "7", "+"};
    Base* op = test.parse(args, 3);
    EXPECT_EQ(op, nullptr);
    delete op; 
}

#endif
