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
//Reste à calculer les puissances des trucs, me faut le net pour itérateurs qur les vecteurs    vector<long> v = 
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

vector<long> ecm(long N) 
{
    vector<long> primes = list_primes(B); /*On récupère la liste des premiers <=B*/
  //  print(primes);
    
    vector<long> power_primes = list_power_primes(primes,B);
  //  print(power_primes);
    
    long a = 1;
    if (isprime(N)) 
    {
        vector<long> w = vector<long> (1, N);
        printf("Byebye par le nord via %ld\n", N );
        return w;
    }
    if (N==1) 
    {
        return vector<long>();
        printf("Byebye par l'ouest\n");
    }
    while (a<B) {
      //  printf("a : %ld\n",a);
        long i = 0;
        Point P = Point(0,1, N,a); /*Point de départ dont on calculera les puissances premières*/
        while (i<(long)primes.size()) {        
            try {
            //    printf("prime : %ld\n", power_primes[i]);
                P = P*power_primes[i];
  //              P.printPoint();
            } catch (long g) {
                //printf("LOL : %ld\n",g);
                long d = pgcd(N, g);
                if (d%N!=0)
                {
                    vector<long> v = ecm(N/d);
                    if (isprime(d))
                    {
                        vector<long> w = vector<long> (1, d);
                        w.insert(w.end(),v.begin(),v.end());
                        printf("Byebye par le Sud via %ld\n", d);
                        return w;
                    }
                    else 
                    {
                        vector<long> w = ecm(d);
                        w.insert(w.end(),v.begin(),v.end());
                        printf("Byebye par l'Est\n");
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
    print((ecm(2345658765)));
    current = get_cpu_time();
    printf("ECM : %f\n", current-time_ini);
    print(pollard(2345658765));
    current = get_cpu_time();
    printf("pollard : %f\n", current-time_ini);
 // printf("inverse de %ld modulo %ld est : %ld\n",a,b,inverse(a,b));
  return 0;
}
