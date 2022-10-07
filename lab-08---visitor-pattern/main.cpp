#include <iostream>
#include <string>

#include "base.hpp"
#include "add/add.hpp"
#include "sub/sub.hpp"
#include "mult/mult.hpp"
#include "div/div.hpp"
#include "pow/pow.hpp"
#include "rand/rand.hpp"
#include "op/op.hpp"
#include "factory.hpp"
#include "iterator.hpp"
#include "printInLatex.hpp"
#include "visitor.hpp"
#include "visitorLatex.hpp"

using namespace std;

/*
int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    return 0;
}
*/

/*
int main(int argc, char** argv) {

    Factory fac;
    Base* op = fac.parse(argv, argc);
    if(op != nullptr){
	cout << op->stringify();
	cout << " = ";
	cout << op->evaluate() << endl;

    }
    //cout << op->stringify();
    //cout << " = ";
    //cout << op->evaluate() << endl;
}
*/

int main() {

    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    printInLatex* latex = new printInLatex();

    string output;
    output = latex->PrintLaTeX(minus);
    cout << minus->stringify() << " -> " << output << endl;

    Base* five = new Op(5);
    Base* one = new Op(1);
    Base* pow = new Pow(five, one);
    Base* add2 = new Add(pow, two);
    Base* div = new Div(add2, four);

    printInLatex* latex1 = new printInLatex();

    string output1;
    output1 = latex1->PrintLaTeX(div);
    cout << div->stringify() << " -> " << output1 << endl;

    Base* six = new Op(6);
    Base* eight = new Op(8);
    Base* zero = new Op(0);
    Base* nine = new Op(9);
    Base* mult1 = new Mult(six, eight);
    Base* div1 = new Div(mult, nine);
    Base* pow1 = new Pow(div1, zero);

    printInLatex* latex2 = new printInLatex();

    string output2;
    output2 = latex2->PrintLaTeX(pow1);
    cout << pow1->stringify() << " -> " << output2 << endl;

}
