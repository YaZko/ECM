//
//  utils.cpp
//  
//
//  Created by Yannick Zakowski on 13/04/12.
//  Copyright (c) 2012 Ecole Normale Supérieure de Cachan. All rights reserved.
//

#include <iostream>
#include <vector>

int pgcd(int a, int b) {
    if (b==0) {
        return a;
    }
    else {
        return pgcd(b, a % b);
    }
}

void print (vector<int> myvector) {
    vector<int>::iterator it;
    for ( it=myvector.begin() ; it < myvector.end(); it++ )
        printf("- %d ",*it);
    printf("\n");
}

bool isprime(int n) {
    if (n==2) {return true;}
    int i=2;
    if ((n%i)==0) {
        return false;
    }    
    i++;
    while (i<=sqrt(n)) {
        if ((n%i)==0) {
            return false;
        }
        i+=2;
    }
    return true;
}