//
//  utils.h
//  
//
//  Created by Yannick Zakowski on 13/04/12.
//  Copyright (c) 2012 Ecole Normale Supérieure de Cachan. All rights reserved.
//
#ifndef _utils_h
#define _utils_h

#include <iostream>
#include <vector>
#include <math.h>
#include "damned.h"

using namespace std;

int pgcd(int a, int b);
void bezout(int a, int b, int* u, int* v);
int inverse(int a, int N);
void printVec(vector<int> v);
//bool isprime(int n);

#endif
