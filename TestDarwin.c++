/*
To test the program:

 % g++ -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestDarwin -lgtest -lpthread -lgtest_main

 % valgrind TestDarwin > TestDarwin.out
*/
// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
//#define class struct
#define private public
#define protected public
#include "Darwin.h"
#include "gtest/gtest.h"



using namespace std;


TEST(Species, name1){
	Species temp("f");
	assert(temp.thename() =="f");
}


TEST(Species,name2){
	Species temp("Lunch time");
	assert(temp.thename() == "Lunch time");
}

TEST(Species,name3){
	Species temp("Corpse");
	assert(temp.thename() == "Corpse");

}

TEST(Species,name4){
	Species temp("Akbar");
	Species temp2("General");
	assert(temp.thename() == "Akbar");
	assert(temp2.thename() == "General");
	assert(temp.thename() != temp2.thename());

}

TEST(Species2, construct){
	Species temp;
	assert(temp.thename() != "Akbar");
	assert(temp.thename() == " ");

}

TEST(Species2, construct2){
	Species temp;
	Species temp2("It's a trap");

	assert(temp.thename() != temp2.thename());

}
