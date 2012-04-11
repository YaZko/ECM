//
//  Point.h
//  
//
//  Created by Yannick Zakowski on 30/03/12.
//  Copyright (c) 2012 Ecole Normale Supérieure de Cachan. All rights reserved.
//

#ifndef Point_h
#define Point_h

class Point 
{
private:
    double x;
    double y;
    bool infty;
    
public:
    Point();
    Point(double x, double y);
    double abs();
    void add(Point &Q);
    void opposite();
    void doubles();
    void print();
};


#endif
