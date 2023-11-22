#define CATCH_CONFIG_MAIN
#include "..//catch.hpp"
#include "a0006.h"

TEST_CASE("createLookup = lookup array should be all zeros")
{
    int i;
    int lookup[7];
    int dieRolls[5] = {0, 0, 0, 0, 0};
    
    createLookup( lookup, dieRolls, 0);
    
    for(i = 0; i < 7; i++)
    {
        REQUIRE( lookup[i] == 0 );
    }
}

TEST_CASE("createLookup = lookup array 5 rolls 12335")
{
    int lookup[7];
    int dieRolls[5] = {1, 2, 3, 3, 5};
    
    createLookup( lookup, dieRolls, 5);
    
    REQUIRE(lookup[0] == 0);
    REQUIRE(lookup[1] == 1);
    REQUIRE(lookup[2] == 1);
    REQUIRE(lookup[3] == 2);
    REQUIRE(lookup[4] == 0);
    REQUIRE(lookup[5] == 1);
    REQUIRE(lookup[6] == 0);
}

TEST_CASE("mostRolled - no duplicates")
{
    int dieNum;
    int lookup[7];
    int dieRolls[11] = { 6, 2, 3, 6, 5, 6, 1, 3, 4, 5, 6};
    
    createLookup(lookup, dieRolls, 11);
    dieNum = mostRolled( lookup, 7 );
    
    REQUIRE(dieNum == 6); 
}
    
TEST_CASE("mostRolled -  duplicates")
{
    int dieNum;
    int lookup[7];
    int dieRolls[5] = {4, 5, 4, 2, 2};
    
    createLookup(lookup, dieRolls, 5);
    dieNum = mostRolled( lookup, 7 );
    
    REQUIRE(dieNum == 2); 
}

TEST_CASE("fewestRolled - no duplicates")
{
    int dieNum;
    int lookup[7];
    int dieRolls[11] = { 6, 2, 3, 6, 5, 6, 1, 3, 4, 5, 6};
    
    createLookup(lookup, dieRolls, 11);
    dieNum = fewestRolled( lookup, 7 );
    
    REQUIRE(dieNum == 1); 
}

TEST_CASE("fewestRolled -  duplicates")
{
    int dieNum;
    int lookup[7];
    int dieRolls[7] = {4, 5, 5, 2, 2, 4, 4};
    
    createLookup(lookup, dieRolls, 7);
    dieNum = fewestRolled( lookup, 7 );
    
    REQUIRE(dieNum == 2); 
}

TEST_CASE("sumRolls – 11 die")
{
    int sumOfDie;
    int lookup[7];
    int die[11] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6 };
    
    createLookup( lookup, die, 11);
    sumOfDie = sumRolls ( lookup, 7 ); 
    
    REQUIRE( sumOfDie == 37 );
}

TEST_CASE("sumRolls – 5 die")
{
    int sumOfDie;
    int lookup[7];
    int die[5] = {1, 4, 5, 3, 6};
    
    createLookup( lookup, die, 5);
    sumOfDie = sumRolls ( lookup, 7 ); 
    
    REQUIRE( sumOfDie == 19 );
}