#ifndef __VISITOR_LATEX_HPP__
#define __VISITOR_LATEX_HPP__

#include "op/op.hpp"
#include "add/add.hpp"
#include "sub/sub.hpp"
#include "mult/mult.hpp"
#include "div/div.hpp"
#include "rand/rand.hpp"
#include "pow/pow.hpp"
#include "visitor.hpp"

#include <string>
#include <sstream>

class VisitorLatex : public Visitor {
    private:
       std::ostringstream out;
    public:
        virtual void visit_op(Op* node);
        virtual void visit_rand(Rand* node);
          // Nodes with two children are visited three times.
          //         // index = 0 -> begin
          //                 // index = 1 -> middle
          //                         // index = 2 -> end
          //


            virtual void visit_add_begin(Add* node);
            virtual void visit_add_middle(Add* node);
            virtual void visit_add_end(Add* node);
            virtual void visit_sub_begin(Sub* node);
            virtual void visit_sub_middle(Sub* node);
            virtual void visit_sub_end(Sub* node);
            virtual void visit_mult_begin(Mult* node);
            virtual void visit_mult_middle(Mult* node);
            virtual void visit_mult_end(Mult* node);
            virtual void visit_div_begin(Div* node);
            virtual void visit_div_middle(Div* node);
            virtual void visit_div_end(Div* node);
            virtual void visit_pow_begin(Pow* node);
            virtual void visit_pow_middle(Pow* node);
            virtual void visit_pow_end(Pow* node);
            std::string output();
};

#endif
