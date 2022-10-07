#ifndef __PRINTINLATEX_HPP__
#define __PRINTINLATEX_HPP__

#include "base.hpp"
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

using namespace std;

class printInLatex {

private:
VisitorLatex* visit;

public:
    printInLatex(){
	visit = nullptr;
    }

    ~printInLatex(){
	if(visit != nullptr){
	    delete visit;
	}
    }

    string PrintLaTeX(Base* ptr){
	visit = new VisitorLatex;
	for (Iterator it(ptr); !it.is_done(); it.next()){
	    it.current_node()->accept(visit, it.current_index());
	}
	return visit->output();
    }



};

#endif
