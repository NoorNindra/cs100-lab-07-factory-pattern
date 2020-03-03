#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include <stdlib.h>

#include "gtest/gtest.h"

#include "base.hpp"
#include "op.hpp"
#include "factory.hpp"

TEST(AddTestFact, AddFactory) {
	/*char one = '1';
	char* oneP = &one;
	char plus = '+';
	char* plusP = &plus;
	char five = '5';
	char* fiveP = &five;
        char nullc = '\0';
        char* nullcP = &nullc;

	char** array; //= {oneP, plusP, fiveP};*/
        
        string userInput = "5 + 1";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;
        
        cout << "Test A\n";

	/*array[0] = oneP; cout << "First works\n"; // This is where the error is
	array[1] = plusP; cout << "Second works\n";
	array[2] = fiveP; cout << "Thirs works\n";
	*/
        cout << "Test B\n";

	Factory* fact = new Factory();
	//Base* base = fact->parse(array, 3);
        Base* base = fact->parse(ptr2, userInput.size());

        cout << "Test C\n";

	EXPECT_EQ(base->evaluate(), 6);
}


#endif //__FACTORY_TEST_HPP__
