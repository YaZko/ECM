//
//  Point.h
//  
//
//  Created by Yannick Zakowski on 30/03/12.
//  Copyright (c) 2012 Ecole Normale Supérieure de Cachan. All rights reserved.
//

#ifndef Point_h
#define Point_h
#define A 1
#include <iostream>
#include <assert.h>
#include "utils.h"

using namespace std;

class Point 
{
private:
    long x;
    long y;
    bool infty;
    long mod;
    long a;
    
public:
    Point(long n, long a);
    Point(long x, long y, long n, long a);
    
    long abs();
    long ord();
    bool is_infty();
    long get_mod();
    long get_a();
    
    bool operator==(Point &Q);
    Point operator+(Point &Q);
    Point operator*(long k);
    void opposite();
    //void doubles();
    long external_times(long k, const Point& p);
    
    void printPoint();
    Point copy();
};


#endif
