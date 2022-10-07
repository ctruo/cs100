#ifndef __PRINTLATEX_TEST_HPP__
#define __PRINTLATEX_TEST_HPP__

#include "gtest/gtest.h"

//#include "base.hpp"
#include "add/add.hpp"
#include "sub/sub.hpp"
#include "mult/mult.hpp"
#include "div/div.hpp"
#include "pow/pow.hpp"
#include "rand/rand.hpp"
#include "op/op.hpp"
#include "visitor.hpp"
#include "visitorLatex.hpp"
#include "iterator.hpp"
#include "printInLatex.hpp"
#include <string>


TEST(PrintLatexTest, addsub){
    Base* two = new Op(2);
    Base* five = new Op(5);
    Base* one = new Op(1);
    Base* add = new Add(two, five);
    Base* sub = new Sub(add, one);

    printInLatex* latex = new printInLatex();
    
    string output;
    output = latex->PrintLaTeX(sub);
    EXPECT_EQ(output, "${({({2}+{5})}-{1})}$");

    delete two;
    delete five;
    delete one;
    delete add;
    delete sub;
    delete latex;

}


TEST(PrintLatexTest, pow){
    Base* two = new Op(2);
    Base* five = new Op(5);
    Base* pow = new Pow(two, five);

    printInLatex* latex = new printInLatex();

    string output;
    output = latex->PrintLaTeX(pow);
    EXPECT_EQ(output, "${({2}^{5})}$");

    delete two;
    delete five;
    delete pow;
    delete latex;

}

TEST(PrintLatexTest, multiplication){
    Base* three = new Op(3);
    Base* eight = new Op(8);
    Base* mult = new Mult(three, eight);

    printInLatex* latex = new printInLatex();

    string output;
    output = latex->PrintLaTeX(mult);
    EXPECT_EQ(output, "${({3}\\cdot{8})}$");

    delete three;
    delete eight;
    delete mult;
    delete latex;

}

TEST(PrintLatexTest, division){
    Base* three = new Op(3);
    Base* four = new Op(4);
    Base* div = new Div(three, four);

    printInLatex* latex = new printInLatex();

    string output;
    output = latex->PrintLaTeX(div);
    EXPECT_EQ(output, "${\\frac{3}{4}}$");

    delete three;
    delete four;
    delete div;
    delete latex;

}


#endif
