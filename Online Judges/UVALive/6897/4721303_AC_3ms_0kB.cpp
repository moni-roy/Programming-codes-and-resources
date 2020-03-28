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
int ret=0,ts,a,b,r[2002],Ans,k,f,vs[2020],n;
vi v[2020];

void fun(int x){
	vs[x]=1;
	ret++;
	for(int i=0;i<(int)v[x].size();i++){
		if(vs[v[x][i]]==0 && r[v[x][i]]>=k){
			fun(v[x][i]);
		}
	}
}

int main()
{
	cin>>ts;
	while(ts--){
		cin>>n>>k>>f;
		zero(r);
		for (int i = 0; i < f; i++)
		{
			cin>>a>>b;
			v[a].pb(b);
			v[b].pb(a);
			r[a]++;
			r[b]++;
		}
		for(int i=1;i<=n;i++){
			if(r[i]<k)
			{
				for(int j=0;j<(int)v[i].size();j++) r[v[i][j]]--;
			}
		}
		Ans=0;
		zero(vs);
		for(int i=1;i<=n;i++){
			//~ cout<<r[i]<< " "<<i<<endl;
			if(r[i]>=k){
				ret=0;
				fun(i);	
				Ans=max(Ans,ret);
			}
		}
		cout<<Ans<<endl;
		for(int i=0;i<=n;i++) v[i].clear();
	}
	return 0;
}

/*
2
5 2 6
1 2
3 2
3 4
4 5
5 2
2 4
5 3 6
1 2
3 2
3 4
4 5
5 2
2 4

* */
