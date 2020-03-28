#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
typedef double dl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef pair<int, pii> piii;
typedef pair<ll,pll> plll;
typedef vector<pii> vii;
typedef vector<piii> viii;

#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define mem(a,b)            memset(a,b,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define IO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define gcd(a,b)            __gcd(a,b)

#define I(a)                scanf("%d",&a)
#define I2(a,b)             scanf("%d%d",&a,&b)
#define L(a)                scanf("%lld",&a)
#define L2(a,b)             scanf("%lld%lld",&a,&b)
#define D(a)                scanf("%lf",&a)

#define SP                  cout<<" ";
#define PI(a)               printf("%d",a)
#define PL(a)               printf("%lld",a)
#define PD(a)               printf("%lf",a)
#define CHK                 cout<<"MK"<<endl

#define bitCount(x)          __builtin_popcountll(x)

template <class T> inline T BMOD(T p, T e, T m) {
    T ret = 1;
    while(e) {
        if(e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
        e >>= 1;
    }
    return (T)ret;
}
template <class T> inline T MODINV(T a, T m) {
    return BMOD(a, m - 2, m);
}
template <class T> inline T isPrime(T a) {
    for(T i = 2; i <= sqrt(double(a)); i++) {
        if(a % i == 0) {
            return 0;
        }
    }
    return 1;
}
template <class T> inline T lcm(T a, T b) {
    return (a / gcd(a, b)) * b;
}
template <class T> inline T power(T a, T b) {
    return (b == 0) ? 1 : a * power(a, b - 1);
}
template <class T> inline string to_str(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}
//-------------------------------------

const int MX = 1001;

bool Area(plll a, plll b,plll c) {
    ll ar = (c.F - a.F)*(b.S.F - a.S.F)-(b.F - a.F) *(c.S.F-a.S.F);
    return (ar!=0);
}

int main() {
    IO;
    int n;
    cin>>n;
    vector<plll > a(n);
    int ii = 0;
    for(auto &i: a) {
        cin>>i.F>>i.S.F;
        i.S.S=++ii;
    }
    sort(a.begin(),a.end());
    for(int i=2; i<n; i++) {
        if(Area(a[i],a[1],a[0])) {
            for(int j = 0; j<n-1; j++) {
                cout<<a[j].S.S <<" "<<a[j+1].S.S<<endl;
            }
            cout<<a[i].S.S<<" " <<a[0].S.S<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
