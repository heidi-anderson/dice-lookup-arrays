#include "a0006.h"

void createLookup(int lookup[], int dieRolls[], int numRolls)
{
    /*
    int lookup[7] = { 0, 0, 0, 0, 0, 0, 0};
    int rolls[5] = { 4, 3, 5, 1, 3 };
    
    lookup[4] = 1;
    lookup[3] = 2;
    lookup[5] = 1;
    lookup[1] = 1;
    */
    int i;
    //zeroing out lookup
    for(i = 0; i < 7; ++i)
    {
        lookup[i] = 0;
    }
    
    for(i = 0; i < numRolls; ++i)
    {
        if(dieRolls[i] > 0 && dieRolls[i] < 7)
        {
            ++lookup[dieRolls[i]];
        }
    }
}

int mostRolled(int lookup[], int lookupSize)
{
    int dieNum = 0;
    int i;
    
    for(i = 1; i < lookupSize; ++i)
    {
        if(lookup[i] > lookup[dieNum])
        {
            dieNum = i;
        }
    }
    return dieNum;
}
 
int fewestRolled(int lookup[], int lookupSize)
{
    int dieNum = 0;
    int i;
    
    for(i = 1; i < lookupSize; ++i)
    {
    
        if((lookup[i] < lookup[dieNum] && lookup[i] != 0) || (lookup[dieNum] == 0 && lookup[i] !=0))
        {
            dieNum = i;
        }
    }
    return dieNum;
}

int sumRolls(int lookup[], int lookupSize)
{
    int sum = 0;
    int i;
    
    for(i = 1; i < lookupSize; ++i)
    {
        sum += lookup[i] * i;
    }
    return sum;
}