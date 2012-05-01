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
#include "damned.h"
#include "utils.h"

using namespace std;

class Point 
{
private:
    int x;
    int y;
    bool infty;
    int mod;
    int a;
    
public:
    Point(int n, int a);
    Point(int x, int y, int n, int a);
    
    int abs();
    int ord();
    bool is_infty();
    int get_mod();
    int get_a();
    
    bool operator==(Point &Q);
    Point operator+(Point &Q);
    Point operator*(int k);
    void opposite();
    //void doubles();
    int external_times(int k, const Point& p);
    
    void printPoint();
    Point copy();
};


#endif
