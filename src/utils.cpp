//
//  utils.cpp
//  
//
//  Created by Yannick Zakowski on 13/04/12.
//  Copyright (c) 2012 Ecole Normale Supérieure de Cachan. All rights reserved.
//

#include "utils.h"

int pgcd(int a, int b) {
    if (b==0) {
        return a;
    }
    else {
        return pgcd(b, a % b);
    }
}

void bezout(int a, int b, int* u, int* v) {
  int q,r,s,t;
  if (b==0) {
    (*u) = 1;
    (*v) = 0;
  }
  else {
    q = a/b;
    r = a%b;
    bezout(b,r,&s,&t);    
    (*u) = t;
    (*v) = s-q*t;
  }
}

int inverse(int a, int N) {
  int u,v;
  a = a % N;
  bezout(a,N,&u,&v);
  if (a*u + N*v == 1) {
    return u;
  }
  else {
    throw (new Damned(a));
  }
}

void printVec(vector<int> myvector) {
    vector<int>::iterator it;
    for ( it=myvector.begin() ; it < myvector.end(); it++ )
        printf("- %d ",*it);
    printf("\n");
}

/*bool isprime(int n) {
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
*/
