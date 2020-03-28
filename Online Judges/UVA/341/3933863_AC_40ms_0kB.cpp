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
#define I_O                 ios_base::sync_with_stdio(0); cin.tie(0);
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

#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)

//~ cout << fixed << setprecision(20) << p << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

/******************************Let's GO*********************************/
typedef pair<int, pair<int,vector<int> > >  piivi;
typedef pair<int,vector<int> >  pivi;
typedef vector<piivi> vpiivi;

vpii g[20];
int sv[20];

void dijkstra(int s,int e){
	setinf(sv);
	priority_queue<piivi,vpiivi, greater<piivi> >pq;
	vi V;
	V.pb(s);
	pq.P(piivi(0,pivi(s,V)));
	sv[s]=0;
	while(!pq.empty()){
		piivi p=pq.top();pq.pop();
		int u=p.S.F;
		int w=p.F;
		vi vs=p.S.S;
		if(u==e){
			cout<<"Path =";
			for(int i=0;i<(int)vs.size();i++){
				cout<<" "<<vs[i];
			}
			cout<<"; "<<w<<" "<<"second delay"<<endl;
			
			return;
		}
		for(int i=0;i<(int)g[u].size();i++){
			pii q=g[u][i];
			int v=q.F;
			int cst=q.S;
			vi ss=vs;
			if(w+cst<sv[v]){
				sv[v]=w+cst;
				ss.pb(v);
				pq.P(piivi(sv[v],pivi(v,ss)));
			}
		}
	}
}
				

int main()
{
	int n,m,s,t,u,v,cs=0;
	while(cin>>n){
		if(n==0) break;
		for(int i=1;i<=n;i++){
			cin>>m;
			while(m--){
				cin>>u>>v;
				g[i].pb(MP(u,v));
				//g[u].pb(MP(i,v));
			}
		}
		cin>>s>>t;
		tcase(cs),sp;
		dijkstra(s,t);
		for(int i=0;i<=n;i++) g[i].clear();
	}
	return 0;
}
