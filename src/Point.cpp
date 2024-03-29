//
//  ECM.cpp
//  
//
//  Created by Christophe Vuillot and Yannick Zakowski on 30/03/12.
//  Copyright (c) 2012 Ecole Normale Supérieure de Cachan. All rights reserved.
//

#include "Point.h"


Point::Point(long n, long a):x(0L), y(0L), infty(true), mod(n), a(a)
{
}

Point::Point(long x, long y, long n, long a):x(x%n), y(y%n), infty(false), mod(n), a(a)
{
}

long Point::abs()
{
    return x;
}

long Point::ord()
{
    return y;
}

bool Point::is_infty()
{
    return infty;
}

long Point::get_mod()
{
    return mod;
}

long Point::get_a() 
{
    return a;
}

bool Point::operator==(Point &Q) {
    return (this->a==Q.get_a() && this->mod==Q.get_mod() && ((this->x==Q.abs() && this->y==Q.ord() && this->infty==Q.is_infty()) || (this->infty && Q.is_infty())));
}

Point Point::operator+(Point &Q)
{   
    assert(this->mod==Q.get_mod());
    long i, k, x, y;
    if (Q.is_infty()) {
        return Point(this->x, this->y, this->mod, this->a);
    } 
    else if (this->infty) {
        return Point(Q.abs(), Q.ord(), Q.get_mod(), Q.get_a());
    }
    else if (this->x!=Q.abs()) {
      i = inverse(this->x-Q.abs(),this->mod);
      k = (this->y-Q.ord())*i;
      x = (k*k-this->x-Q.abs())%(this->mod);
      y = (k*(this->x-x)-this->y)%(this->mod);
      return Point(x,y,this->mod, this->a);
    } 
    else if (this->y!=Q.ord()) {
      return Point(this->mod, this->a);
    } 
    else if (this->y==0) {
      assert((*this)==Q);
      return Point(this->mod, this->a);
    } 
    else {
      assert((*this)==Q);
      i = inverse(2*this->y,this->mod);
      k = (3*this->x*this->x+A)*i;
      x = (k*k-2*this->x)%(this->mod);
      y = (k*(this->x-x)-this->y)%(this->mod);
      return Point(x,y,this->mod, this->a);
    }
}

void Point::opposite()
{
    y = -y;
}


Point Point::operator*(long k)
{
    Point p = this->copy();
    while (k!=1) {
        if (k%2==0) 
        {
            p = p+p;
        }
        else
        {
            p = p+p;
            p = p+(*this);
        }
        k /= 2;
    } 
    return p;
}


void Point::printPoint() 
{
    if (infty)
    {
        printf("infty\n");
    }
    else 
    {
        printf("(%ld, %ld)\n", x, y);
    }
}

Point Point::copy() {
    if (this->is_infty()) {
        return Point(this->mod, this->a);
    }
    else {
        return Point(this->x,this->y,this->mod, this->a);
    }
}


