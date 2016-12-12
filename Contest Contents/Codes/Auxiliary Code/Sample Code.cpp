#include <bits/stdc++.h>
using namespace std;
typedef long long          	ll;
typedef long long unsigned 	llu;
#define pi                  acos(-1.0)
#define gcd(a,b)            __gcd(a,b)
template <class T> inline T BMOD(T p,T e,T m) {
    T ret=1;
    while(e) {
        if(e&1) ret=(ret*p)%m;
        p=(p*p)%m;
        e>>=1;
    }
    return (T)ret;
}
template <class T> inline T MODINV(T a,T m) {
    return BMOD(a,m-2,m);
}
template <class T> inline T isPrime(T a) {
    for(T i=2; i<=sqrt(double(a)); i++) {
        if(a%i==0) {
            return 0;
        }
    }
    return 1;
}
template <class T> inline T lcm(T a, T b) {
    return (a/gcd(a,b))*b;
}
template <class T> inline T power(T a, T b) {
    return (b==0)?1:a*power(a,b-1);
}
template <class T> inline string toString(T t) {
    stringstream ss;
    ss<<t;
    return ss.str();
}
template <class T> inline long long toLong(T t) {
    stringstream ss;
    ss<<t;
    long long ret;
    ss>>ret;
    return ret;
}
cout << fixed << setprecision(20) << Ans << endl;
priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
