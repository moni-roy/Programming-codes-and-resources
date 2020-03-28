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
vpii Ans;
int ts,cs=0,nd,n,q,a,ds[100010],lw[100010],pr[100010],vs[100100];
vi adj[100010];
int cnt=0;

void dfs(int u){

	vs[u]=1;
	ds[u]=lw[u]=++cnt;

	for(int i=0;i<(int)adj[u].size();i++){
		int v=adj[u][i];

		if(!vs[v]){
			pr[v]=u;
			dfs(v);
			lw[u]=min(lw[u],lw[v]);
			if(lw[v]>ds[u]){
				Ans.pb(MP(min(u,v),max(u,v)));
			}
		}
		else if(v!=pr[u]){
			lw[u]=min(lw[u],ds[v]);
		}
	}
}

void bridge(){
	minus(pr);
	zero(vs);
	zero(lw);
	zero(ds);

	for(int i=0;i<n;i++){
		if(!vs[i]){
			cnt=0;
			dfs(i);
		}
	}
}
int main()
{
	while(sci(n)==1){
		for (int i = 0; i < n; i++)
		{
			scanf("%d (%d)",&nd,&q);
			for(int i=0;i<q;i++) {
				sci(a);
				adj[nd].pb(a);
			}
		}
		bridge();

		vsort(Ans);
		printf("%d critical links\n",Ans.size());
		for(int i=0;i<(int)Ans.size();i++){
			int x=Ans[i].F;
			int y=Ans[i].S;
			printf("%d - %d\n",x,y);
		}
		Ans.clear();
		for (int i = 0; i < n; i++)
		{
			adj[i].clear();
		}
		nl;
	}
	return 0;
}
