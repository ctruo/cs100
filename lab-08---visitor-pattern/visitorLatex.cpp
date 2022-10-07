#include "visitorLatex.hpp"

void VisitorLatex::visit_op(Op* node) {
    out << "{" << node->evaluate() << "}";
}

void VisitorLatex::visit_rand(Rand* node) {
    out << "{" << node->evaluate() << "}";
}

void VisitorLatex::visit_add_begin(Add* node) {
    out << "{(";
}

void VisitorLatex::visit_add_middle(Add* node) {
        out << "+";
}

void VisitorLatex::visit_add_end(Add* node) {
        out << ")}";
}

void VisitorLatex::visit_sub_begin(Sub* node) {
        out << "{(";
}

void VisitorLatex::visit_sub_middle(Sub* node) {
        out << "-";
}

void VisitorLatex::visit_sub_end(Sub* node) {
        out << ")}";
}

void VisitorLatex::visit_mult_begin(Mult* node) {
        out << "{(";
}

void VisitorLatex::visit_mult_middle(Mult* node) {
        out << "\\cdot";
}

void VisitorLatex::visit_mult_end(Mult* node) {
        out << ")}";
}

void VisitorLatex::visit_div_begin(Div* node) {
        out << "{\\frac";
}

void VisitorLatex::visit_div_middle(Div* node) {
        
}

void VisitorLatex::visit_div_end(Div* node) {
        out << "}";
}

void VisitorLatex::visit_pow_begin(Pow* node) {
        out << "{(";
}

void VisitorLatex::visit_pow_middle(Pow* node) {
        out << "^";
}

void VisitorLatex::visit_pow_end(Pow* node) {
        out << ")}";
}

std::string VisitorLatex::output() {
    return '$'+out.str()+'$';
}
