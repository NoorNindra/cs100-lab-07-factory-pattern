#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include <vector>

#include "base.hpp"
#include "concreteFactory.hpp"

using namespace std;

class Factory {
    
public:
    Factory() {}
    
    Base* parse(char** input, int length) {
        
        ConcreteFactory* build = new ConcreteFactory();

        Base* op1 = nullptr;
        Base* op2 = nullptr;
        Base* linker = nullptr;
        
        char* currInput = *input;
        char curr = *currInput;
        char* save;
        bool needsBases = false;

        for (int i = 0; i < length; ++i) {
            if (isdigit(curr)) {
                if (op1 == nullptr) {
                    op1 = build->getBase(currInput);
                    ++currInput;
                    curr = *currInput;
                }
                else {
                    op2 = build->getBase(currInput);
                    ++currInput;
                    curr = *currInput;
                    if (needsBases == true) {
                        linker = build->getBase(save, op1, op2);
                        op1 = linker;
                        op2 = nullptr;
                        needsBases = false;
                    }
                }
            }
            else {
                if ((op2 == nullptr) && curr != ' ') {
                    save = currInput;
                    ++currInput;
                    curr = *currInput;
                    if (*save == '*' && curr == '*') {
                        ++i;
                        ++currInput;
                        curr = *currInput;
                    }
                    needsBases = true;
                }
            }
        }
        
        
        if (linker == nullptr && op1 != nullptr) {
            return op1;
        }
        return linker;
    }
    
};

#endif //__FACTORY_HPP__
