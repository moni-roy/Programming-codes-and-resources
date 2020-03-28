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
typedef pair<int ,pii>      piii;
typedef vector<pii>         vpii;
typedef vector<piii>        vpiii;
//~ Define
#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define P                   push
#define zero(a)             memset(a,0,sizeof a)
#define minus(a)            memset(a,-1,sizeof a)
#define setinf(a)           memset(a,126,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define I_O                 ios_base::sync_with_stdio(0); cin.tie(0)
#define gcd(a,b)            __gcd(a,b)
//~ Input                   
#define sci(a)              scanf("%d",&a)
#define scii(a,b)           scanf("%d%d",&a,&b)
#define sciii(a,b,c)        scanf("%d%d%d",&a,&b,&c)
#define scl(a)              scanf("%lld",&a)
#define scll(a,b)           scanf("%lld%lld",&a,&b)
#define sclll(a,b,c)        scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a)              scanf("%lf",&a)
//~ Output                  
#define endl                '\n'
#define nl                  puts("")
#define sp                  printf(" ");
#define tcase(cs)           printf("Case %d:",++cs)
#define pri(a)              printf("%d",a)
#define prl(a)              printf("%lld",a)
#define prd(a)              printf("%lf",a)

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}

#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)

//~ cout << fixed << setprecision(20) << p << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

/******************************Let's GO*********************************/

int m[10010],d[10010],y[1000],D,T,n,c[10010];

int leap(int x){
	return ((y[x]%4==0 && y[x]%100) || (y[x]%400==0))?0:1;
}

int F(int x){
	if(y[x-1]==y[x] && m[x-1]+1==m[x] && d[x]==1){
		if(m[x-1]==1 && d[x-1]==31) return 1;
		if(m[x-1]==2 && d[x-1]==28 && leap(x-1)) return 1;
		if(m[x-1]==2 && d[x-1]==29) return 1;
		if(m[x-1]==3 && d[x-1]==31) return 1;
		if(m[x-1]==4 && d[x-1]==30) return 1;
		if(m[x-1]==5 && d[x-1]==31) return 1;
		if(m[x-1]==6 && d[x-1]==30) return 1;
		if(m[x-1]==7 && d[x-1]==31) return 1;
		if(m[x-1]==8 && d[x-1]==31) return 1;
		if(m[x-1]==9 && d[x-1]==30) return 1;
		if(m[x-1]==10 && d[x-1]==31) return 1;
		if(m[x-1]==11 && d[x-1]==30) return 1;
		if(m[x-1]==12 && d[x-1]==31) return 1;
	}
	if(d[x]==d[x-1]+1 && y[x]==y[x-1] && m[x-1]==m[x]) return 1;
	if(y[x]==y[x-1]+1 && d[x]==1 && d[x-1]==31 && m[x]==1 && m[x-1]==12) return 1;
	
	return 0;
}

int main()
{
	I_O;
	while(cin>>n&&n){
		for (int i = 0; i < n; i++)
		{
			cin>>d[i]>>m[i]>>y[i]>>c[i];
		}
		D=T=0;
		for (int i = 1; i < n; i++)
		{
			if(F(i)){
				D++;
				T+=(c[i]-c[i-1]);
			}
		}
		cout<<D<<" "<<T<<endl;
	}
	return 0;
}
