//
//  damned.h
//  
//
//  Created by Yannick Zakowski on 27/04/12.
//  Copyright (c) 2012 Ecole Normale Supérieure de Cachan. All rights reserved.
//

#ifndef _damned_h
#define _damned_h
#include <iostream>

using namespace std;

class Damned : public exception {
    
private:
    int n;
public:
    Damned(int n);
    int get_int();
}; 

#endif
