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

int id,a[1010],vs[1010],sv[1010],s,t,cs=0;
vector<int>prm,dv[1010];

void sieve(){
	memset(vs,0,sizeof vs);
	prm.push_back(2);
	for(int i=3;i<=1000;i++){
		if(vs[i]==0){
			prm.push_back(i);
			for(int j=i+i;i*j<=1000;j+=i){
				vs[j]=1;
			}
		}
	}
}
void fun(){
	for(int k=1;k<1001;k++){
		int x=k;
		for(int i=0;prm[i]*prm[i]<=x;i++){
			if(x%prm[i]==0){
				dv[k].push_back(prm[i]);
				while(x%prm[i]==0){
					x/=prm[i];
				}
			}
		}
		if(x>1&&x!=k) dv[k].push_back(x);
	}
}
int F(int x,int y){
	memset(sv,0,sizeof sv);
	queue<int>q;
	q.push(x);
	sv[x]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<(int)dv[u].size();i++){
			int v=u+dv[u][i];
			if(sv[v]!=0) continue;
			if(v==y) return sv[u];
			if(v<=y){
				sv[v]=sv[u]+1;
				q.push(v);
			}
		}
	}
	return -1;
}
				
int main(){
	I_O;
	sieve();
	fun();
	while(cin>>s>>t){
		if(s+t==0) break;
		cout<<"Case "<<++cs<<": ";
		if(s==t){
			cout<<0<<endl;
			continue;
		}
		int an=F(s,t);
		if(an!=-1) cout<<an<<endl;
		else cout<<-1<<endl;
	}
}
