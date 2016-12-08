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
#define inf 1e9

int main()
{
	int cs=0,a,b,sv[101][101];
	
	while(cin>>a>>b){
		if(a+b==0) break;
		for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			sv[i][j]=(i==j)?0:inf;
		}}
		
		mii mp;
		vi v;
		sv[a][b]=1;
		//~ sv[b][a]=1;
		mp[a]=1;
		mp[b]=1;
		v.pb(a);
		v.pb(b);
		while(cin>>a>>b){
			if(a+b==0) break;
			if(mp[a]==0) v.pb(a);
			if(mp[b]==0) v.pb(b);
			mp[a]=mp[b]=1;
			sv[a][b]=1;
			//~ sv[b][a]=1;
		}
		
		for(int k=0;k<=100;k++){
		for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			sv[i][j]=min(sv[i][j],sv[i][k]+sv[k][j]);
		}}}
		int sm=0,cnt=0;
		for(int i=0;i<(int)v.size();i++){
		for(int j=0;j<(int)v.size();j++){
			if(i==j) continue;
			//~ cout<<sv[v[i]][v[j]]<<endl;
			sm+=sv[v[i]][v[j]];
			cnt++;
		}
		}
		//~ cout<<sm<<" "<<cnt<<endl;
		tcase(cs);
		cout<<" average length between pages = ";
		cout << fixed << setprecision(3) << dl(sm*1.0/cnt*1.0)*1.0 << " clicks"<<endl;
	}		
	return 0;
}
