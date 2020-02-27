#ifndef __CONCRETEFACTORY_HPP__
#define __CONCRETEFACTORY_HPP__

#include "base.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "sub.hpp"

using namespace std;

class ConcreteFactory
{
	public:
		ConcreteFactory() {}

		Base* getBase(char* a)
		{
			if(isdigit(c)) 
			{
				return new Op(c);
			}
		}

		Base* getBase(char* a, Base* b, Base* c)
		{
			if(a == '+')
			{
				return new Add(b, c);
			}
			if(a == '/')
			{
				return new Div(b, c);
			}
			if(a[0] == '*')
			{
				if(a[1] == '*')
				{
					return new Pow(b,c);
				}
				else
				{
					return new Mult(b, c);
				}
			}
			if(a == '-')
			{
				return new Sub(b, c);
			}
			else
			{
				cout << "Invalid input" << endl;
				return nullptr;
			}		
		}	
};

#endif //__CONCRETEFACTORY_HPP__
