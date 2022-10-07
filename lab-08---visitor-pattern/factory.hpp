#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include "add/add.hpp"
#include "sub/sub.hpp"
#include "mult/mult.hpp"
#include "div/div.hpp"
#include "pow/pow.hpp"
#include "rand/rand.hpp"
#include "op/op.hpp"

using namespace std;

class Factory /* : public Base */ {
private:
       
public:
    Factory() {
        //Base* root = nullptr;
    }

  //  ~Factory() {
//	delete root;
    //}

    Base* parse(char** input, int length) {
        if (length < 4) {
           cout << "ERROR!: invalid input size" << endl;
           return nullptr;
 	}
	int i = 1;
        Base* root = nullptr;
	Base* left = nullptr;
        char op;
        char *powOp = "**";
        string str(powOp);

	char *subOp = "-";
	string subStr(subOp);

        while(i < length){
	    string st(input[i]);
            op = *input[i];
	   
	    if((root == nullptr) && (op == '+' || st == subStr || op == '*' || op == '/' || op == '**')){
		cout << "ERROR!" << endl;
		return nullptr;
	    }

	    else if((root == nullptr) && (op != '+' || op != '-' || op != '*' || op != '/' || op != '**') && (stod(input[i]) > -100) ){
                   if(root == nullptr) {
                        root = new Op(stod(input[i]));
		        i++;
			continue;
                   }else{
                       cout << "Error: problem in Base* parse() function for input digit" << endl;
                   }
                }

            else if(op == '+'){
                left = root;
		root = new Add(left, new Op(stod(input[++i])));
            }

            else if(op == '-'){
                left = root;
		root = new Sub(left, new Op(stod(input[++i])));
            }
			
            else if(op == '/'){
		left = root;
		root = new Div(left, new Op(stod(input[++i])));
	    }

	    else if(st == str){
		left = root;
		root = new Pow(left, new Op(stod(input[++i])));
	    }
	
            else if(op == '*'){
                left = root;
                root = new Mult(left, new Op(stod(input[++i])));
            }		
	    else{
		cout << "ERROR!" << endl;
		cout << "What caused the error is input[" << i << "] = \"" << input[i] << "\""  << endl;
		return nullptr;
		}

	    i++;
        }
		
	return root;
    }

   

};

#endif
