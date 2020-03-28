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
ll n,m,c,d,Ans,l,r,cl,cr,fs,sv[1001010];

int main()
{
	I_O;
	while(cin>>n>>m){
		zero(sv);
		for (int i = 0; i < m; i++)
		{
			cin>>c>>d;
			sv[c]--;
			sv[d]++;
		}
		Ans=0ll;
		fs=0;
		l=n+1;
		r=0;
		cr=cl=0;
		ll ls=0;
		for(ll i=1;i<=n+1;i++){
			
			if(sv[i]<0){
				fs=1;
				l=min(i,l);
				cl+=abs(sv[i]);
			}
			else if(sv[i]>0){
				r=max(i,r);
				cr+=sv[i];
			}
			
			if(cr==cl && fs){
				Ans+=(2*(r-l));
				fs=cr=cl=0;
				l=n+1;
				r=0;
			}
			
			if(fs==0){
				ll d=i-ls;
				Ans+=d;
				ls=i;
			}
			
		}
		cout<<Ans<<endl;
	}		
	return 0;
}
/*
10 3
3 7
8 9
2 5
10 3
8 9
6 7
2 4
10 0
10 6
6 7
4 5
2 5
6 9
3 5
6 8
1000 8
3 4
6 1000
5 1000
7 1000
8 1000
4 1000
9 1000
1 2
*/
