#pragma once
#include <string>
#include <cctype>

using namespace std;

void createLookup(int lookup[], int dieRolls[], int numRolls);
int mostRolled(int lookup[], int lookupSize);
int fewestRolled(int lookup[], int lookupSize);
int sumRolls(int lookup[], int lookupSize);