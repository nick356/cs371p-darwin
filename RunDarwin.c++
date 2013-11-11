// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

/*
To run the program:
% g++ -pedantic -std=c++0x -Wall Darwin.c++ RunDarwin.c++ -o RunDarwin
% valgrind RunDarwin > RunDarwin.out

To configure Doxygen:
doxygen -g
That creates the file Doxyfile.
Make the following edits:
EXTRACT_ALL = YES
EXTRACT_PRIVATE = YES
EXTRACT_STATIC = YES
GENERATE_LATEX = NO

To document the program:
doxygen Doxyfile
*/

// --------
// includes
// --------
#include <stdio.h>
#include <cassert> // assert
#include <cstdlib> // rand, srand
#include <iostream> // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include "Darwin.h"
#include "Darwin.c++"
#define HOP 0
#define LEFT 1
#define RIGHT 2
#define INFECT 3
#define IF_EMPTY 4
#define IF_WALL 5
#define IF_RAND 6
#define IF_ENEMY 7
#define GO 8
#define WEST 0
#define NORTH 1
#define EAST 2
#define SOUTH 3


// ----
// main
// ----

int main () {
	using namespace std;

    // ----
    // food
    // ----

    /*
0: left
1: go 0
*/

	Species food("f");
	food.addInstruction(LEFT,0);
	food.addInstruction(GO,0);
    

    // ------
    // hopper
    // ------

    /*
0: hop
1: go 0
*/
	Species hopper("h");
	hopper.addInstruction(HOP);
	hopper.addInstruction(GO,0);
    // -----
    // rover
    // -----

    /*
0: if_enemy 9
1: if_empty 7
2: if_random 5
3: left
4: go 0
5: right
6: go 0
7: hop
8: go 0
9: infect
10: go 0
*/

	Species rover("r");
	rover.addInstruction(IF_ENEMY,9);
	rover.addInstruction(IF_EMPTY,7);
	rover.addInstruction(IF_RAND,5);
	rover.addInstruction(LEFT);
	rover.addInstruction(GO,0);
	rover.addInstruction(RIGHT);
	rover.addInstruction(GO,0);
	rover.addInstruction(HOP);
	rover.addInstruction(GO,0);
	rover.addInstruction(INFECT);
	rover.addInstruction(GO,0);
		

    // ----
    // trap
    // ----

    /*
0: if_enemy 3
1: left
2: go 0
3: infect
4: go 0
*/

	Species trap("t");
	trap.addInstruction(IF_ENEMY,3);
	trap.addInstruction(LEFT);
	trap.addInstruction(GO,0);
	trap.addInstruction(INFECT);
	trap.addInstruction(GO,0);

    // ----------
    // darwin 8x8
    // ----------

    try {
        cout << "*** Darwin 8x8 ***" << endl;
        /*
8x8 Darwin
Food, facing east, at (0, 0)
Hopper, facing north, at (3, 3)
Hopper, facing east, at (3, 4)
Hopper, facing south, at (4, 4)
Hopper, facing west, at (4, 3)
Food, facing north, at (7, 7)
Simulate 5 moves.
Print every grid.
*/
	World themap(8,8);
	Creature f1(food);
	Creature f2(food);
	Creature h1(hopper);
	Creature h2(hopper);
	Creature h3(hopper);
	Creature h4(hopper);
	themap.setCreat(f1,EAST,0,0);
	themap.setCreat(h1,NORTH,3,3);
	themap.setCreat(h2,EAST,3,4);
	themap.setCreat(h3,SOUTH,4,4);
	themap.setCreat(h4,WEST,4,3);
	themap.setCreat(f2,NORTH,7,7);

	Darwin temp(5,themap);
	temp.runGame();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 7x9
    // ----------

    try {
        cout << "*** Darwin 7x9 ***" << endl;
        /*
7x9 Darwin
Trap, facing south, at (0, 0)
Hopper, facing east, at (3, 2)
Rover, facing north, at (5, 4)
Trap, facing west, at (6, 8)
Simulate 5 moves.
Print every grid.
*/    
	World themap2(9,7);
	Creature tr(trap);
	Creature tr2(trap);
	Creature hr(hopper);
	Creature rv(rover);

	themap2.setCreat(tr,SOUTH,0,0);
	themap2.setCreat(hr,EAST,3,2);
	themap2.setCreat(rv,NORTH,5,4);
	themap2.setCreat(tr2,WEST,6,8);
	Darwin temp2(5,themap2);
	srand(0);
	temp2.runGame();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 72x72
    // without best
    // ------------

    try {
        cout << "*** Darwin 72x72 without Best ***" << endl;
        srand(0);
        /*
Randomly place the following creatures facing randomly.
Call rand(), mod it with 5184 (72x72), and use that for the position
in a row-major order grid.
Call rand() again, mod it with 4 and use that for it's direction with
the ordering: west, north, east, south.
Do that for each kind of creature.
10 Food
10 Hopper
10 Rover
10 Trap
Simulate 1000 moves.
Print the first 10 grids (i.e. 0, 1, 2...9).
Print every 100th grid after that (i.e. 100, 200, 300...1000).
*/
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 72x72
    // with best
    // ------------

    try {
        cout << "*** Darwin 72x72 with Best ***" << endl;
        srand(0);
        /*
Randomly place the following creatures facing randomly.
Call rand(), mod it with 5184 (72x72), and use that for the position
in a row-major order grid.
Call rand() again, mod it with 4 and use that for it's direction with
the ordering: 0:west, 1:north, 2:east, 3:south.
Do that for each kind of creature.
10 Food
10 Hopper
10 Rover
10 Trap
10 Best
Simulate 1000 moves.
Best MUST outnumber ALL other species for the bonus pts.
Print the first 10 grids (i.e. 0, 1, 2...9).
Print every 100th grid after that (i.e. 100, 200, 300...1000).
*/
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    return 0;}
