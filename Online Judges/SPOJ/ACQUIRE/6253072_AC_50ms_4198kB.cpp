/* * * * * * * * * * * *
 * :Krishna (MRoy)     *
 * :JU                 *
 * :mkroy.cs@gmail.com *
 * * * * * * * * * * * */
#include <bits/stdc++.h>

using namespace std;

typedef long long          	ll;
typedef long long unsigned 	llu;
typedef double             	dl;
typedef pair<int,int>      	pii;
typedef pair<ll,ll>     	pll;
typedef vector<int>        	vi;
typedef vector<ll>        	vl;
typedef map<int,int> 		mii;
typedef map<ll,ll>         	mll;
typedef map<string,int>    	msi;
typedef map<char,int>      	mci;
typedef pair<int,pii>       piii;
typedef vector<pii>         vpii;
typedef vector<piii>        vpiii;
//~ Define
#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define P                   push
#define mem(a,b)            memset(a,b,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define gcd(a,b)            __gcd(a,b)
//~ Input
#define I(a)                scanf("%d",&a)
#define I2(a,b)             scanf("%d%d",&a,&b)
#define I3(a,b,c)           scanf("%d%d%d",&a,&b,&c)
#define L(a)                scanf("%lld",&a)
#define L2(a,b)             scanf("%lld%lld",&a,&b)
#define L3(a,b,c)           scanf("%lld%lld%lld",&a,&b,&c)
#define D(a)                scanf("%lf",&a)
//~ Output
#define nl                  puts("")
#define sp                  printf(" ");
#define SP                  cout<<" ";
#define tcase(cs)           printf("Case %d:",++cs)
#define TC(cs)              cout<<"Case "<<++cs<<":"
#define PI(a)               printf("%d",a)
#define PL(a)               printf("%lld",a)
#define PD(a)               printf("%lf",a)

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2; i<=sqrt(double(a)); i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}

#define READ(input)    freopen(input,"r",stdin)
#define WRITE(output)  freopen(output,"w",stdout)
//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra
/******************************Let's GO*********************************/

int nw;

vl slp,cst;

int IsBad(int L1,int L2,int L3)
{
    return (cst[L3]-cst[L1])*(slp[L1]-slp[L2])<(cst[L2]-cst[L1])*(slp[L1]-slp[L3]);
}
void Add(ll m, ll c)
{
    slp.pb(m);
    cst.pb(c);
    int L=slp.size();
    while(L>=3 && IsBad(L-3,L-2,L-1))
    {
        slp.erase(slp.end()-2);
        cst.erase(cst.end()-2);
        L=slp.size();
    }
}
ll Query( ll x)
{
    if( nw >= (int)slp.size())
    {
        nw=slp.size()-1;
    }
    while( nw < slp.size()-1 && (slp[nw+1]*x+cst[nw+1])<(slp[nw]*x+cst[nw])) nw++;

    return (slp[nw]*x+cst[nw]);
}

struct st
{
    int x,y;
    bool operator<(const st &p)const
    {
        if(x==p.x) return y<p.y;
        return x<p.x;
    }
}a[50005],X[50005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a,a+n);
    int k=0;
    for(int i=0;i<n;i++){
        while(k>0 && X[k-1].y<=a[i].y) k--;
        X[k++]=a[i];
    }
//    cout<<k<<endl;
    nw=0;
    ll ret=0;
    Add(X[0].y,0);
    for(int i=0;i<k;i++){
        ret=Query(X[i].x);
//        cout<<ret<<endl;
        if(i<k) Add(X[i+1].y,ret);
    }
    cout<<ret<<endl;
    return 0;
}
