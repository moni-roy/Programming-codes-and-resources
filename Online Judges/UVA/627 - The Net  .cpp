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
typedef pair<int ,vi > pivi;

vi g[333];
int vs[333];

void bfs(int s,int e){
	vi v;
	v.pb(s);
	zero(vs);
	queue<pivi>q;
	q.P(pivi(s,v));
	vs[s]=1;
	while(!q.empty()){
		pivi p=q.front();q.pop();
		vi c=p.S;
		int u=p.F;
		for(int i=0;i<(int)g[u].size();i++){
			int V=g[u][i];
			if(vs[V]==0){
				vs[V]=1;
				if(V==e){
					for(int j=0;j<(int)c.size();j++){
						cout<<c[j]<< " ";
					}
					cout<<e<<endl;
					return;
				}
				vi xx=c;
				
				xx.pb(V);
				q.P(pivi(V,xx));
			}
		}
	}
	cout<<"connection impossible"<<endl;
}
int main()
{
	int n,m,s,e;
	string ss;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>ss;
			int id;
			ss+=',';
			//~ cout<<ss<<endl;
			for(int j=0;j<(int)ss.size();j++){
				if(ss[j]=='-'){
					id=j+1;
					break;
				}
			}
			int nm=0;
			//~ cout<<id<<endl;
			for(int j=id;j<(int)ss.size();j++){
				if(ss[j]==','){
					g[i+1].pb(nm);
				//	cout<<nm<<endl;
					nm=0;
					continue;
				}
				nm*=10;
				nm+=(ss[j]-'0');
			}
		}
		cin>>m;
		puts("-----");
		while(m--){
			cin>>s>>e;
			bfs(s,e);
		}
		//puts("-----");
		for(int i=0;i<=n;i++) g[i].clear();
	}
	return 0;
}
