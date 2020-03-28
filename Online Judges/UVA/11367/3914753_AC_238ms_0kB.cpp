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

#define PI          acos(-1.0)
#define S           second
#define F           first
#define PB          push_back
#define MP          make_pair
#define P           push
#define zero(a)     memset(a,0,sizeof a)
#define minus(a)    memset(a,-1,sizeof a)
#define setinf(a)   memset(a,126,sizeof a)
#define all(v)      (v.begin(),v.end())
#define vsort(v)    sort(v.begin(),v.end())
#define nl          puts("")
#define tcase(cs)   printf("Case %d:",++cs)
#define endl        '\n'
#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)
#define I_O         ios_base::sync_with_stdio(0); cin.tie(0);
#define gcd(a,b)    __gcd(a,b)
#define sci(a)      scanf("%d",&a)
#define scl(a)      scanf("%lld",&a)
#define scd(a)      scanf("%lf",&a)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}

typedef pair<int ,pii> piii;
typedef vector<pii> vpii;
typedef vector<piii> vpiii;


int price[10001],sv[10001][101];
vpii adj[10001];


int query(int c,int s,int e){
	
	setinf(sv);
	priority_queue<piii,vpiii, greater<piii> >pq;
	
	pq.push(piii(0,pii(s,0)));
	sv[s][0]=0;
	
	while(!pq.empty()){
	
		piii p=pq.top();pq.pop();
		int w=p.F;
		int u=p.S.F;
		int cp=p.S.S;
	
		if(u==e) return w;
		//~ if(w!=sv[u][cp]) continue;
	
		if(cp>0){
			for(int i=0;i<(int)adj[u].size();i++){
				
				pii q=adj[u][i];
				int d=q.S;
				int v=q.F;
				
				if(cp>=d && sv[u][cp]<sv[v][cp-d]){
					sv[v][cp-d]=sv[u][cp];
					pq.push(piii(sv[v][cp-d],pii(v,cp-d)));
				}
			}
		}
		
		if(cp<c){
			if(sv[u][cp]+price[u]<sv[u][cp+1]){
				sv[u][cp+1]=sv[u][cp]+price[u];
				pq.push(piii(sv[u][cp+1],pii(u,cp+1)));
			}
		}
	}
	return -1;
}
			

int main()
{
	int n,m,u,v,d,Ans,c,s,e,q;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>price[i];
	for(int i=0;i<m;i++){
		cin>>u>>v>>d;
		adj[u].PB(pii(v,d));
		adj[v].PB(pii(u,d));
	}
	cin>>q;
	while(q--){
		cin>>c>>s>>e;
		Ans=query(c,s,e);
		if(Ans==-1) cout<<"impossible"<<endl;
		else cout<<Ans<<endl;
	}
	return 0;
}
//~ 5 5
//~ 10 10 20 12 13
//~ 0 1 9
//~ 0 2 8
//~ 1 2 1
//~ 1 3 11
//~ 2 3 7
//~ 2
