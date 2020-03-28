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

ll X[1000005];
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
    while( nw < slp.size()-1 && (slp[nw+1]*x+cst[nw+1])>(slp[nw]*x+cst[nw])) nw++;

    return (slp[nw]*x+cst[nw]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,ts,a,b,c;
    cin>>ts;
    while(ts--){
        cin>>n;
        cin>>a>>b>>c;
        for(int i=1;i<=n;i++){
            cin>>X[i];
            X[i]+=X[i-1];
        }
        nw=0;
        ll ret = a*(X[1]*X[1]) + b*X[1] + c;
        Add(-2*a*X[1], ret + a*X[1]*X[1] - b*X[1]);
        for(int i=2;i<=n;i++){
            ret=a*(X[i]*X[i]) + b*X[i] + c;
            ret=max(ret,a*(X[i]*X[i]) + b*X[i] + c + Query(X[i]));
            if(i<=n) Add(-2*a*X[i], ret + a*X[i]*X[i] - b*X[i]);
        }
        cout<<ret<<endl;
        slp.clear();
        cst.clear();
    }
    return 0;
}
