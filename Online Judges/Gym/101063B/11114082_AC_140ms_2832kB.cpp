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

const int MX = 1e4+3;
int sv[MX+5],n,m,id;
string ss[MX+5],s[16][10];
set<string>pr[MX];

int go(int p) {
    if(p>=m) return 0;
    int &ret = sv[p];
    if(ret!=-1) return ret;
    ret = 1e9;
    for(int  i = 0; i<id; i++) {
        int ii = p;
        while(pr[i].find(ss[ii])!=pr[i].end()) {
            ii++;
        }
        if(ii!=p) ret = min(ret,go(ii)+1);
    }
    return ret;
}

int main() {
    IO;
    cin>>n;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<7; j++) {
            cin>>s[i][j];
        }
    }
    cin>>m;
    for(int i = 0; i<m; i++) {
        cin>>ss[i];
    }
    id = 0;
    for(int i =0; i<n; i++) {
        for(int j=i+1; j<n; ++j) {
            for(int k=0; k<7; k++) {
                pr[id].insert(s[i][k]);
                pr[id].insert(s[j][k]);
            }
            id++;
        }
    }
    for(int i=0; i<7; i++)
        pr[id].insert(s[0][i]);
    id++;
    memset(sv,-1,sizeof sv);
    int Ans = go(0);
    cout<<Ans<<endl;
    return 0;
}
