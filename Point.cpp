//
//  ECM.cpp
//  
//
//  Created by Christophe Vuillot and Yannick Zakowski on 30/03/12.
//  Copyright (c) 2012 Ecole Normale Supérieure de Cachan. All rights reserved.
//

#include <iostream>
#include "Point.h"
#define A 1

using namespace std;

Point::Point():x(0), y(0), infty(true)
{
}

Point::Point(double x, double y):x(x), y(y), infty(false)
{
}

double Point::abs()
{
    return x;
}

void Point::add(Point &Q)
{   
    double k, aux;
    if (x!=Q.x) 
    {
        k = (x-Q.x)/(y-Q.y);
        x = k*k-x-Q.x;
        y = k*(x-aux)-y;
        return;
    }
    else if (y!=Q.y)
    {
        infty = true;
        return;
    }
    else if (y==0)
    {
        infty = true;
        return;
    }
    else
    {
        k = (3*x*x+A)/(2*y);
        x = k*k-2*x;
        y = k*(x-aux)-y;
        return;
    }
}

void Point::opposite()
{
    y = -y;
}

void Point::doubles()
{
    (*this).add(*this);
}

void Point::print() 
{
    if (infty)
    {
        printf("infty\n");
    }
    else 
    {
        printf("(%f, %f)\n", x, y);
    }
}

int main()
{
    Point P = Point(0,0);
    P.print();
    P.doubles();
    P.print();
    return 0;
}


