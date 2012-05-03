//
//  ECM.cpp
//  
//
//  Created by Yannick Zakowski on 12/04/12.
//  Copyright (c) 2012 Ecole Normale Supérieure de Cachan. All rights reserved.
//

#include <iostream>
#include "utils.h"
#include "Point.h"
#include <vector>
#include <math.h>
#include "pollard.h"


#define B 100

using namespace std;


vector<long> list_primes(long N)
{
    vector<long> w = vector<long> (1, 2);
    long i;
    for (i=3 ; i<=N; i+=2) 
    {
        if (isprime(i))
        {
            w.push_back(i);
        }
    }
    return w;
}

vector<long> list_power_primes(vector<long> primes, long b) {
    long i,q,aux;
    vector<long> res = vector<long>();
    for (i=0 ; i<(long)primes.size() ; i++) {
        q = aux = primes[i];
        while (aux <= b) {
            aux *= q;
        }
        res.push_back(aux/q);
    }
    return res;
}

vector<long> ecm(long N) {
  vector<long> primes = list_primes(B); /*On récupère la liste des premiers <=B*/
  
  vector<long> power_primes = list_power_primes(primes,B);
  
  long a = 1;
  if (isprime(N)) {
    vector<long> w = vector<long> (1, N);
    return w;
  }
  if (N==1) {
    return vector<long>();
  }
  while (a<B) {
    long i = 0;
    Point P = Point(0,1, N,a); /*Point de départ dont on calculera les puissances premières*/
    while (i<(long)primes.size()) {        
      try {
	P = P*power_primes[i];
      } catch (long g) {
	long d = pgcd(N, g);
	if (d%N!=0)
	  {
	    vector<long> v = ecm(N/d);
	    if (isprime(d))
	      {
		vector<long> w = vector<long> (1, d);
		w.insert(w.end(),v.begin(),v.end());
		return w;
	      }
	    else 
	      {
		vector<long> w = ecm(d);
		w.insert(w.end(),v.begin(),v.end());
		return w;
	      } 
	  }
	
      }
      i++;
    }
    a++;
  }
}

int main()
{
    double time_ini = get_cpu_time();
    double current;
    print((ecm(2992345658)));
    current = get_cpu_time();
    printf("ECM : %f\n", current-time_ini);
    print(pollard(2992345658));
    current = get_cpu_time();
    printf("pollard : %f\n", current-time_ini);
 // printf("inverse de %ld modulo %ld est : %ld\n",a,b,inverse(a,b));
  return 0;
}
