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
const int MX = 2e5+5;
int t = 0;
vi g[MX];
int tr[4*MX],lz[4*MX],st[MX],ed[MX],nd[MX],cs[MX];
void go(int u) {
    st[u]=++t;
    nd[t]=u;
    for(auto v: g[u]) {
        go(v);
    }
    ed[u]=t;
}
void bld(int p,int s,int e) {
    lz[p]=0;
    if(s==e) {
        tr[p] = cs[nd[s]];
        return ;
    }
    int m = (s+e)/2;
    int l = 2*p;
    int r = l+1;
    bld(l,s,m);
    bld(r,m+1,e);
    tr[p]=tr[l]+tr[r];
}
void lazy(int p,int s,int e) {
    if(lz[p]) {
        tr[p] = e-s+1-tr[p];
        lz[p]=0;
        if(s!=e) {
            lz[2*p] = !lz[p*2];
            lz[2*p+1] = !lz[p*2+1];
        }
    }
    return ;
}
void upd(int p,int s,int e,int x,int y) {
    if(s>=x && e<=y) {
        lz[p]=!lz[p];
    }
    lazy(p,s,e);
    if(s>y || e<x) return;
    if(s>=x && e<=y) return;
    int m = (s+e)/2;
    int l = 2*p;
    int r = l+1;
    upd(l,s,m,x,y);
    upd(r,m+1,e,x,y);
    tr[p]=tr[l]+tr[r];
}
int qry(int p,int s,int e,int x,int y) {
    lazy(p,s,e);
    if(s>y || e<x) return 0;
    if(s>=x && e<=y) return tr[p];
    int m = (s+e)/2;
    return qry(p*2,s,m,x,y)+qry(p*2+1,m+1,e,x,y);
}
int main() {
    IO;
    int n,a,q,u;
    cin>>n;
    for(int  i = 2; i<=n; ++i) {
        cin>>a;
        g[a].pb(i);
    }
    go(1);
    for(int i = 1; i<=n; ++i) {
        cin>>cs[i];
    }
    int N = n;
    bld(1,1,N);
    cin>>q;
    string s;
    while(q--) {
        cin>>s>>u;
        if(s=="get") {
            cout<<qry(1,1,N,st[u],ed[u])<<endl;
        } else {
            upd(1,1,N,st[u],ed[u]);
        }
    }
    return 0;
}
