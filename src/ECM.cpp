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

#define B 100

using namespace std;

vector<int> list_primes(int N)
{
    vector<int> w = vector<int> (1, 2);
    int i;
    for (i=3 ; i<=N; i+=2) 
    {
        if (isprime(i))
        {
            w.push_back(i);
        }
    }
//Reste à calculer les puissances des trucs, me faut le net pour itérateurs qur les vecteurs    vector<int> v = 
    return w;
}

vector<int> list_power_primes(vector<int> primes, int b) {
    int i,q,aux;
    vector<int> res = vector<int>();
    for (i=0 ; i<(int)primes.size() ; i++) {
        q = aux = primes[i];
        while (aux <= b) {
            aux *= q;
        }
        res.push_back(aux/q);
    }
    return res;
}

vector<int> ecm(int N) 
{
    vector<int> primes = list_primes(B); /*On récupère la liste des premiers <=B*/
    print(primes);
    
    vector<int> power_primes = list_power_primes(primes,B);
    print(power_primes);
    
    int a = 1;
    while (a<B) {
        printf("a : %d\n",a);
        int i = 0;
        Point P = Point(0,1, N,a); /*Point de départ dont on calculera les puissances premières*/
        int g;
        while (i<(int)primes.size()) {        
            try {
                printf("prime : %d\n", power_primes[i]);
                P = P*power_primes[i];
                P.printPoint();
            } catch (int g) {
                printf("LOL : %d\n",g);
            }
            i++;
        }
        a++;
    }
    return primes;
}

int main()
{
  int a,b,u,v;
  a = 3;
  b = 7;
  bezout(a,b,&u,&v);
  printf("a : %d, b : %d -> u : %d, v : %d\n",a,b,u,v);
  Point p(0,3,6,1);
  Point q(0,2,6,1);
  Point r(0,2,6,1);
  p.printPoint();
  q.printPoint();
  //(q+q).printPoint();
  //(q*2).printPoint();
  //p.printPoint();
  //q.printPoint();
  if (r==q){printf("true\n");} else {printf("false\n");}
  print((ecm(21)));
  printf("inverse de %d modulo %d est : %d\n",a,b,inverse(a,b));
  return 0;
}
