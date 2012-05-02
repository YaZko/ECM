#include "pollard.h"
#define B 100

vector<int> pollard(int N) {
    int d;
    if (isprime(N)) 
    {
        vector<int> w = vector<int> (1, N);
        return w;
    }
    if (N==1) 
    {
        return vector<int>();
    }
    int a = (rand() % (B-1))+2;
    printf("pollard(%d)->a : %d\n",N,a);
    int a0=a;
    d = pgcd(N, a);
    printf("pollard(%d)->d = pgcd(%d, %d) = %d\n",N,N,a,d);
    if (d>1)
    {
        vector<int> v = pollard(N/d);
        if (isprime(d)) 
        {
            vector<int> w = vector<int> (1, d);
            w.insert(w.end(),v.begin(),v.end());
            return w;
        }
        else 
        {
            vector<int> w = pollard(d);
            w.insert(w.end(),v.begin(),v.end());
            return w;
        }
    }
    else {
        for (int i=2; i<=B; i++) {
            a = (a*a0) %N;
            printf("pollard(%d)->a : %d\n",N,a);
            d = pgcd(N, a-1);
            printf("pollard(%d)->d = pgcd(%d, %d) = %d\n",N,N,a-1,d);
            if (d>1)
            {
                vector<int> v = pollard(N/d);
            /*    if (isprime(d)) 
                {
                    vector<int> w = vector<int> (1, d);
                    w.insert(w.end(),v.begin(),v.end());
                    return w;
                }
                else 
                {
              */    vector<int> w = pollard(d);
                    w.insert(w.end(),v.begin(),v.end());
                    return w;
               // }
            }
        }
    }
    vector<int> v = vector<int>(1, -1);
    return v;
}
