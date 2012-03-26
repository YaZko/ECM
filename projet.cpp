#include <vector>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#define B 10

using namespace std;

int pgcd(int a, int b) {
    if (b==0) {
        return a;
    }
    else {
        return pgcd(b, a % b);
    }
}

bool isprime(int n) {
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

vector<int> pollard(int N) {
    int d;
    if (N==1) 
    {
        return vector<int>();
    }
    int a = (rand() % (B-1))+2;
    printf("pollard(%d)->a : %d\n",N,a);
    int a0=a;
    d = pgcd(N, a);
    printf("pollard(%d)->d : %d\n",N,d);
    if (d>1)
    {
        vector<int> v = pollard(N/d);
        printf("%i\n",isprime(d));
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
            a *= a0 % N;
            d = (pgcd(N, a-1))%N;
            printf("pollard(%d)->d : %d\n",N,d);
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
        }
    }
}


int main() {
    vector<int> v = pollard(10);
    printf("%d-%d\n",v[0],v.size());
    return 0;
}