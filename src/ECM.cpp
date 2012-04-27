//
//  ECM.cpp
//  
//
//  Created by Yannick Zakowski on 12/04/12.
//  Copyright (c) 2012 Ecole Normale Supérieure de Cachan. All rights reserved.
//

#include <iostream>
#include "Point.h"
#include <vector>
#include <math.h>

#define B 10

using namespace std;

void print (vector<int> myvector) 
{
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
                P.print();
            } catch (Damned d) {
                g = d.get_int();
                printf("LOL : %d",g);   
            }
            i++;
        }
        a++;
    }
    return primes;
}

int main()
{
    Point p(0,3,6,1);
    Point q(0,2,6,1);
    Point r(0,2,6,1);
    p.print();
    q.print();
    (q+q).print();
    (q*2).print();
    p.print();
    q.print();
    if (r==q){printf("true\n");} else {printf("false\n");}
    print((ecm(6)));
    return 0;
}