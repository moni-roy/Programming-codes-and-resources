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
typedef pair<int,pii>      piii;
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

#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)
//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

/// Hashing Bases & MOD
///           0123456789
#define Base1 10000019ll
#define Base2 10000079ll
#define Base3 10000103ll
#define MOD1  1000000007ll
#define MOD2  1000000009ll
#define MOD3  1000000021ll
#define LOGX  17
/***********Let's GO********/


int k,dp[4005][805],m,X[4005][4005];
bool vis[4005][805];

int Cost(int l,int r)
{
     return X[r][r]+X[l-1][l-1]-X[r][l-1]-X[l-1][r];
}

void Func(int l,int r,int x,int y)
{
    if(l>r) return;
    int mid=(l+r)/2;

    if(vis[mid][k]) return;
    int &res=dp[mid][k];
    res=INT_MAX;
    int Id=-1;
    for(int i=x;i<=min(y,mid);i++) {
        int Tp=dp[i][k-1]+Cost(i+1,mid);
        if(res>Tp) {
            res=Tp,Id=i;
        }
    }
    Func(l,mid-1,x,Id);
    Func(mid+1,r,Id,y);
}

void Solve(int K,int n)
{
    for(int i=1;i<=n;i++ ) {
        dp[i][1]=Cost(1,i);
    }
    for(int i=2;i<=K;i++) {
        k=i;
        Func(1,n,1,n);
    }
    return ;
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n;
    I2(n,m);

    for(int i=1; i<=n; i++){
        for(int j=1;j<=n;j++)
        {
            getchar();
            char ch=getchar();
            X[i][j]=ch-'0';
            X[i][j]+=X[i][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) X[i][j]+=X[i-1][j];
    }
    Solve(m,n);
    printf("%d\n",dp[n][m]/2);
    return 0;
}
