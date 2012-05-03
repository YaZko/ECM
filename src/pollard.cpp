#include "pollard.h"
#define B 100

vector<long> pollard(long N) {
    long d;
    if (N==1) {
      return vector<long>();
    }
    if (isprime(N)) {
      vector<long> w = vector<long> (1, N);
      return w;
    }
    long a = (rand() % (B-1))+2;
    long a0=a;
    d = pgcd(N, a);
    if (d>1) {
      vector<long> v = pollard(N/d);
      vector<long> w = pollard(d);
      w.insert(w.end(),v.begin(),v.end());
      return w;
    }
    else {
      for (long i=2; i<=B; i++) {
	a = (a*a0) %N;
	d = pgcd(N, a-1);
	if (d>1) {
	  vector<long> v = pollard(N/d);
	  vector<long> w = pollard(d);
	  w.insert(w.end(),v.begin(),v.end());
	  return w;
	}
      }
    }
    vector<long> v = vector<long>(1, -1);
    return v;
}
