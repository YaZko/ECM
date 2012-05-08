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
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

long pgcd(long a, long b);
void bezout(long a, long b, long* u, long* v);
long inverse(long a, long N);
void print(vector<long> v);
bool isprime(long n);
double get_cpu_time(void);

#endif
