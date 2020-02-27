#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include <vector>

#include "base.hpp"
#include "concreteFactory.hpp"

using namespace std;

class factory {
    
public:
    Factory() {}
    
    Base* parse(char** input, int length) {
        
        ConcreteFactory* build = nullptr;

        Base* op1 = nullptr;
        Base* op2 = nullptr;
        Base* linker = nullptr;
        
        if (2 < length) {
            
            op1 = build->getBase(input[0]);
            op2 = build->getBase(input[2]);
            linker = build->getBase(input[1], op1, op2);
            
        }
        
        for (int i = 3; i < length; i = i + 2) {
            
            if (i + 1 < length) {
                
                op1 = linker;
                op2 = build->getBase(input[i+1]);
                linker = build->getBase(input[i], op1, op2);
                
            }
            
        }
        
        if (linker != nullptr) {
            cout << linker->stringify() << ' ' << linker->evaluate();
        }
        
        return linker;
    }
    
};

#endif //__FACTORY_HPP__
