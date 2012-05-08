//
//  utils.cpp
//  
//
//  Created by Yannick Zakowski on 13/04/12.
//  Copyright (c) 2012 Ecole Normale Supérieure de Cachan. All rights reserved.
//

#include "utils.h"

long pgcd(long a, long b) {
    if (b==0) {
        return a;
    }
    else {
        return pgcd(b, a % b);
    }
}

void bezout(long a, long b, long* u, long* v) {
  long q,r,s,t;
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

long inverse(long a, long N) {
  long u,v;
  a = a % N;
  bezout(a,N,&u,&v);
  if (a*u + N*v == 1) {
      long i=u%N;
      if (i<0) {
          return i+N;
      } else {
          return i;
      }
  } else if (a*u + N*v == -1) {
      long i=-u%N;
      if (i<0) {
          return i+N;
      } else {
          return i;
      }
  } else {
    throw a;
  }
}

void print(vector<long> myvector) {
    vector<long>::iterator it;
    for ( it=myvector.begin() ; it < myvector.end(); it++ )
        printf("- %ld ",*it);
    printf("\n");
}

bool isprime(long n) {
    n = abs(n);
    if (n==2) {return true;}
    long i=2;
    if ((n%i)==0) {
        return false;
    }    
    i++;
    while (i<=sqrt(n)) {
        if ((n%i)==0) {
            return false;
        }
        i=i+2;
    }
    return true;
}


double get_cpu_time(void)
{
    struct timeval tim;
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    tim = ru.ru_utime;
    double t = (double) tim.tv_sec + (double) tim.tv_usec /1000000.0;
    tim = ru.ru_stime;
    t += (double) tim.tv_sec + (double) tim.tv_usec /1000000.0;
    return t;
}
