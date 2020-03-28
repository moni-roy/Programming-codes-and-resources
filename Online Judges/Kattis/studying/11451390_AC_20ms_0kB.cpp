#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
typedef double dl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef pair<int,pii> piii;
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
template <class T> inline string to_str(T t) {
    stringstream ss;
    ss<<t;
    return ss.str();
}
//-------------------------------------
int n;
dl m,a[11],b[11],c[11];
dl go(int x,int y,dl z) {
    if(x==y) return a[x]*z*z+b[x]*z+c[x];
    dl l = 0,h = z;
    int t = 13;
    dl r1;
    dl r2;
    while(t--) {
        dl m1 = l+(h-l)/3.0;
        dl m2 = h-(h-l)/3.0;
        r1 = go(x,(x+y)/2,m1) + go((x+y)/2+1,y,z-m1);
        r2 = go(x,(x+y)/2,m2) + go((x+y)/2+1,y,z-m2);
        if(r1<r2) l = m1;
        else h = m2;
    }
    return max(r1,r2);
}

int main() {
    IO;
    cin>>n>>m;
    for(int i = 0; i<n; i++)cin>>a[i]>>b[i]>>c[i];
    dl Ans = go(0,n-1,m);
    Ans/=(n+.0);
    cout<<fixed<<setprecision(10)<<Ans<<endl;
    return 0;
}

